#include <string>
#include "search_state.h"

using namespace std;

/*
    none of this is intended to be used
*/
float search_state::cost () {
    return 1.0f;
}

bool search_state::equals (search_state other) {
    return this->get_hash_code () == other.get_hash_code ();
}

int search_state::get_hash_code () {
    return hash<string>{} (this->id);
}