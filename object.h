#pragma once
#include <stdlib.h>
#include <string.h>
class Object {
    public:

        //set the hash for the object
        virtual hash() {}
        virtual size_t hash() {}

        //object constructor with no arguments
        Object() {  }

       //compare hashes to see if objects are the same
        virtual bool equals(Object* object) {}

        virtual ~Object() {}
};
