#include "search_algorithm.h"
#include "null_heuristic.h"

vector<search_state> search_algorithm::search (search_problem& problem) {
    null_heuristic heuristic;

    return this->search (problem, heuristic);
}

vector<search_state> search_algorithm::search (search_problem& problem, heuristic_interface& heuristic) {
    this->start_timing ();

    vector<search_state> result = this->run_search (problem, heuristic);

    this->stop_timing ();

    return result;
}

void search_algorithm::start_timing () {
    this->start = high_resolution_clock::now ();
}

void search_algorithm::stop_timing () {
    this->stop = high_resolution_clock::now ();
    high_resolution_clock::duration d = this->stop - this->start;

    this->code_runtime = d;
}