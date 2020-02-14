#pragma once
#include<chrono>
#include "search_interface.h"

using namespace std;
using namespace chrono;

class search_algorithm : public search_interface {
public:
    high_resolution_clock::duration code_runtime;
    vector<search_state> search (search_problem& problem) override;
    vector<search_state> search (search_problem& problem, heuristic_interface& heuristic) override;

private:
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point stop;

    void start_timing ();
    void stop_timing ();

    virtual vector<search_state> run_search (search_problem& problem, heuristic_interface& heuristic) = 0;
};