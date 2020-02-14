#pragma once
#include <vector>
#include "search_state.h"
#include "search_problem.h"
#include "heuristic_interface.h"

using namespace std;

class search_interface {
public:
    virtual ~search_interface () {}

    virtual vector<search_state> search (search_problem& problem) = 0;
    virtual vector<search_state> search (search_problem& problem, heuristic_interface& heuristic) = 0;
};