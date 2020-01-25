#include <iostream>
#pragma once
#include <stdlib.h>
#include <string.h>
#include "object.h"

class Queue: public Object {
   public:
	
	unsigned int back; // most recent element added to queue
	unsigned int front; // front of the queue/first element
	size_t size; // size of queue
	size_t capacity; // max size of queue
	Object** data; // array of objects representing elements of queue

	// constructor queue that takes in a max capacity
	Queue(unsigned int _capacity) {
	   this->capacity = _capacity;
	   this->front = 0;
	   this->back = 0;
	   this->size = 0;
       Object *arr[this->capacity];
	   this->data = arr;
	}
	
	// checks if queue has 0 elements
	bool queue_empty() {
	   if(this->size == 0) {
		return true;
	   }
	   return false;
	}

	// checks if queue has reached capacity
	bool queue_full() {
	   if(this->size == this->capacity) {
		return true;
	   }
	   return false;
	}

	// returns front element of queue
	Object* frontElement() {
	   if(this->queue_empty()) {
		std:: cout << "queue is empty";
		exit(1);
	   }
	   return this->data[0];
	}
	
	// returns queue size
	size_t getSize() {
	   return this->size;
	}
	
	// adds element to back of queue if queue is not full. Increments back. 
	void queue_push(Object* element) {
	   if(this->queue_full()) {
		std:: cout << "queue is full";
		exit(1);
	   }
	   else {
		this->data[this->back] = element;
		this->back++;
		this->size++;
	   }
	}
	
	// removes front element of queue. Shifts remaining elements down a spot	
	void queue_pop() {
	   if (this->queue_empty()) {
		std:: cout << "queue is empty";
		exit(1);
	   }

           Object *temp[this->capacity];
	   for(int i = 0; i < this->size - 1; i++) {
		temp[i] = temp[i+1];
	   }
	   this->data = temp;
	   this->size--;
	   this->back--;
	}
   
	~Queue() {
           for(int i = 0; i < this->getSize(); i++) {
                delete this->data[i];
           }
           delete this->data;
        }
};
