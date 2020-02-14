#pragma once
#include <map>
#include <string>
#include <vector>
#include "search_state.h"

using namespace std;

class search_problem {
public:
    map<int, string> expanded_states;

    virtual search_state get_starting_state () = 0;
    virtual vector<search_state> get_successors (search_state current_state) = 0;
    virtual bool is_goal_state (search_state current_state) = 0;
};