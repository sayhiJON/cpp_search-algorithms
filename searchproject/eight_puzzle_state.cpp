#include "eight_puzzle_state.h"

eight_puzzle_state::eight_puzzle_state (string id) {
    this->id = id;
}

float eight_puzzle_state::cost () {
    return 1.0f;
}

bool eight_puzzle_state::equals (search_state other) {
    if (dynamic_cast<eight_puzzle_state*>(&other) == nullptr)
        return false;

    return this->get_hash_code () == other.get_hash_code ();
}

int eight_puzzle_state::get_hash_code () {
    return hash<string>{} (this->id);
}