#include <queue>
#include "bfs.h"

vector<search_state> bfs::run_search (search_problem& problem, heuristic_interface& heuristic) {
    queue<search_state> frontier;
    map<int, search_state> visited;
    map<int, search_state> parents;

    search_state start = problem.get_starting_state ();
    search_state current = start;

    frontier.push (current);

    while (!frontier.empty ()) {
        current = frontier.front ();
        frontier.pop ();

        if (visited.count (current.get_hash_code ()))
            continue;

        visited[current.get_hash_code ()] = current;

        if (problem.is_goal_state (current))
            break;

        vector<search_state> successors = problem.get_successors (current);

        if (successors.empty ())
            continue;

        for (int index = 0; index < successors.size (); index++) {
            search_state successor = successors[index];

            if (visited.count (successor.get_hash_code ()))
                continue;

            if (!parents.count (successor.get_hash_code ()))
                parents[successor.get_hash_code ()] = current;

            frontier.push (successor);
        }
    }

    vector<search_state> path;

    while (!current.equals (start)) {
        path.push_back (current);
        current = parents[current.get_hash_code ()];
    }

    reverse (path.begin (), path.end ());

    return path;
}