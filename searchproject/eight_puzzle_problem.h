#pragma once
#include "search_problem.h"

class eight_puzzle_problem : public search_problem {
public:
    eight_puzzle_problem ();
    eight_puzzle_problem (int seed);

    search_state get_starting_state () override;
    vector<search_state> get_successors (search_state current_state) override;
    bool is_goal_state (search_state current_state) override;

private:
    string p_starting_state;
    string p_goal_state = "123456780";

    bool p_solvable = false;

    void generate_puzzle (int seed);
    int count_inversions ();
};