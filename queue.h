#include <iostream>
#pragma once
#include <stdlib.h>
#include <string.h>
#include "object.h"

class Queue: public Object {
   public:
	

	// constructor queue that takes in a max capacity
	Queue() {
	}
	
	// checks if queue has 0 elements
	bool queue_empty() {
	 
	}

	// checks if queue has reached capacity
	bool queue_full() {
	   
	}

	// returns front element of queue
	Object* frontElement() {
	
	}
	
	// returns queue size
	size_t getSize() {
	   
	}
	
	// adds element to back of queue if queue is not full. Increments back. 
	void queue_push(Object* element) {
	  
	}
	
	// removes front element of queue. Shifts remaining elements down a spot	
	void queue_pop() {
	 
	}
   
	~Queue() {
         
        }
};
