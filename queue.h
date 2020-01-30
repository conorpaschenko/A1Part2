#pragma once
#include <stdlib.h>
#include "object.h"

class Queue: public Object {
   public:
	

	Queue() {
	}
	
	// checks if queue has 0 elements
	virtual bool is_empty() {
	 
	}

	// returns front element of queue
	virtual Object* front_element() {
	
	}
	
	// returns queue size
	virtual size_t size() {
	   
	}
	
	// adds element to back of queue. 
	virtual void push(Object* element) {
	  
	}
	
	// removes front element of queue. Shifts remaining elements down a spot and returns popped element	
	virtual Object* pop() {
	 
	}
	
	//get the hash for the Queue
    virtual size_t hash() {}
	

    //compare queue objects to see if they are the same
    virtual bool equals(Object* queue) {}
   
	virtual ~Queue() {
         
        }
};
