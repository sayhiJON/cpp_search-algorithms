#pragma once
#include "heuristic_interface.h"

class null_heuristic : public heuristic_interface {
public:
    float evaluate_state (search_problem& problem, search_state state) override { return 0.0f; }
};