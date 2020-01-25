#pragma once
#include <stdlib.h>
#include <string.h>
class Object {
    public:

        //deep copy a string
        char* _strdup(const char* s) {
            int length = strlen(s);

            char* str = new char[length + 1];
            for (int i =0; s[i] != 0; i++) {
                str[i] = s[i];
            }
            str[length + 1] = '\0';

            return str;
        }

        //set the hash for the object
        size_t _make_hash() {
            return reinterpret_cast<size_t>(this);
        }

        size_t hash() {
            return this->hash_code;
        }

        const char* type;
        size_t hash_code;

        //object constructor with no arguments
        Object() {
            this->type = "object";
            this->hash_code = this->_make_hash();
        }
        
        //object constructor with type specified
        Object(const char* type) {
            this->type = this->_strdup(type);
            this->hash_code = this->_make_hash();
        }
    
        const char* get_type() {
            return this->type;
        }

       //compare hashes to see if objects are the same
        bool equals(Object* object) {
             return this->hash() == object->hash();
        }

        ~Object() {
             delete this->type;
        }
};
