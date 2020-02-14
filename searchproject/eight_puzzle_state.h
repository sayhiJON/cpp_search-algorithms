#pragma once
#include <string>
#include "search_state.h"

using namespace std;

class eight_puzzle_state : public search_state {
public:
    eight_puzzle_state (const search_state& x) : search_state (x) {}

    eight_puzzle_state (string id);

    float cost () override;
    bool equals (search_state other) override;
    int get_hash_code () override;
};