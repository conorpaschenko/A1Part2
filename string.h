#pragma once
#include<stdio.h>

#include "object.h"
#include <string.h>

class String : public Object {
    public:
        const char* _value;

        //string constructor with specified value
        String(const char* v) : Object("string") {
           this->_value = this->_strdup(v); 
        }

        //return length of string
        int length() {
            return strlen(this->_value);
        }

        //return string value
        const char* get_value() {
            return this->_value; 
        }

        //string equals; return true if strings are equal, else return false
        bool streq(String* s1, String* s2) {
            return !strcmp(s1->get_value(), s2->get_value());
        }

        //append s1 onto end of this string
        String* concat(String* s1) {
            printf("%d %d %d\n", this->length(), s1->length(), 1);
            char temp[this->length() + s1->length() + 1];
            strcat(temp, this->get_value());
            strcat(temp, s1->get_value());
            return new String(temp);
        }

        ~String() {
            delete this->_value;
        }
};
