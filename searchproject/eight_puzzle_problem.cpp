#include "eight_puzzle_state.h"
#include "eight_puzzle_problem.h"

eight_puzzle_problem::eight_puzzle_problem () {
    this->generate_puzzle (rand () % RAND_MAX);
}

eight_puzzle_problem::eight_puzzle_problem (int seed) {
    this->generate_puzzle (seed);
}

search_state eight_puzzle_problem::get_starting_state () {
    return eight_puzzle_state (this->p_starting_state);
}

vector<search_state> eight_puzzle_problem::get_successors (search_state current_state) {
    eight_puzzle_state state = (eight_puzzle_state)current_state;

    int spaceIndex = state.id.find ('0'),
        x = spaceIndex % 3,
        y = spaceIndex / 3;

    vector<search_state> successors;

    for (int dx = -1; dx < 2; dx++) {
        for (int dy = -1; dy < 2; dy++) {
            int nx = x + dx,
                ny = y + dy;

            if ((nx != x && ny != y) || (nx == x && ny == y) || nx < 0 || nx > 2 || ny < 0 || ny > 2)
                continue;

            int index = (ny * 3) + nx;

            if (index < 0 || index >= state.id.size ())
                continue;

            string successor (state.id);

            successor[spaceIndex] = successor[index];
            successor[index] = '0';

            eight_puzzle_state next (successor);
            successors.push_back (next);
        }
    }

    this->expanded_states[state.get_hash_code ()] = state.id;

    return successors;
}

bool eight_puzzle_problem::is_goal_state (search_state current_state) {
    eight_puzzle_state state = (eight_puzzle_state)current_state;

    /*if (state == nullptr)
        return false;*/

    return (state.id.compare(this->p_goal_state) == 0);
}

void eight_puzzle_problem::generate_puzzle (int seed) {
    srand (seed);

    while (!this->p_solvable) {
        string puzzle;
        vector<int> digits{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };

        while (digits.size () > 0) {
            int next = rand () % digits.size ();
            puzzle += to_string (digits[next]);
            digits.erase (digits.begin () + next);
        }

        this->p_starting_state = puzzle;
        this->p_solvable = (this->count_inversions () % 2 == 0);
    }
}

int eight_puzzle_problem::count_inversions () {
    vector<int> sequence;

    for (int index = 0; index < this->p_starting_state.size (); index++) {
        int value = (int)this->p_starting_state[index] - 48;

        if (value == 0)
            continue;

        sequence.push_back (value);
    }

    int count = 0;

    for (int index = 0; index < sequence.size () - 1; index++) {
        for (int position = index + 1; position < sequence.size (); position++) {
            if (sequence[index] > sequence[position])
                count++;
        }
    }

    return count;
}