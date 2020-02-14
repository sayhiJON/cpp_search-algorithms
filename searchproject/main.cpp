#include "bfs.h"
#include "eight_puzzle_problem.h"

int main () {
    srand (time (NULL));

    eight_puzzle_problem problem;
    bfs search;

    printf ("Starting state: %s\n", problem.get_starting_state ().id.c_str());

    vector<search_state> result = search.search (problem);
    printf ("Ending state: %s\n", result.back ().id.c_str ());
    printf ("# of states searched: %d\n", problem.expanded_states.size ());
    printf ("# of moves required to solve: %d\n", result.size ());
    printf ("Time required to find solution: %f ms\n", (search.code_runtime.count() / 1000.0f / 1000.0f));

    return 0;
}