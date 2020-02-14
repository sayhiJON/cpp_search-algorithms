#pragma once
#include "search_algorithm.h"

class bfs : public search_algorithm {
    vector<search_state> run_search (search_problem& problem, heuristic_interface& heuristic) override;
};