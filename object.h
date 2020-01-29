#pragma once
#include <stdlib.h>
#include <string.h>
class Object {
    public:

        //get the hash for the object
        virtual size_t hash() {}

        //object constructor with no arguments
        Object() {  }

       //compare hashes to see if objects are the same
        virtual bool equals(Object* object) {}

        virtual ~Object() {}
};
