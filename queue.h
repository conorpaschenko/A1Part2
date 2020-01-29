#include <iostream>
#pragma once
#include <stdlib.h>
#include <string.h>
#include "object.h"

class Queue: public Object {
   public:
	

	Queue() {
	}
	
	// checks if queue has 0 elements
	virtual bool queue_empty() {
	 
	}

	// returns front element of queue
	virtual Object* frontElement() {
	
	}
	
	// returns queue size
	virtual size_t getSize() {
	   
	}
	
	// adds element to back of queue if queue is not full. Increments back. 
	virtual void queue_push(Object* element) {
	  
	}
	
	// removes front element of queue. Shifts remaining elements down a spot and returns popped element	
	virtual Object* queue_pop() {
	 
	}
	
	//get the hash for the Queue
        virtual size_t hash() {}
	

       //compare hashes to see if Queues are the same
        virtual bool equals(Queue* queue) {}
   
	virtual ~Queue() {
         
        }
};
