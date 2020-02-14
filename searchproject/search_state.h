#pragma once
#include <string>

using namespace std;

class search_state {
public:
    string id;

    virtual float cost ();
    virtual bool equals (search_state other);
    virtual int get_hash_code ();
};