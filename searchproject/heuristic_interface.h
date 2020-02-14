#pragma once
#include "search_state.h"
#include "search_problem.h"

class heuristic_interface {
public:
    virtual ~heuristic_interface () {}

    virtual float evaluate_state (search_problem& problem, search_state state) = 0;
};