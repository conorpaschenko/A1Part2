#pragma once
#include <stdlib.h>
#include <string.h>
class Object {
    public:
        size_t hash_code;

        //set the hash for the object
        size_t _make_hash() {
            return reinterpret_cast<size_t>(this);
        }

        virtual size_t hash() {}

        //object constructor with no arguments
        Object() {
            this->type = "object";
            this->hash_code = this->_make_hash();
        }

       //compare hashes to see if objects are the same
        virtual bool equals(Object* object) {}

        virtual ~Object() {}
};
