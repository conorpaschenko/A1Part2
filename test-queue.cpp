#include <stdlib.h>
#include <stdio.h>
#include "object.h"
#include "string.h"
#include "queue.h"

/**
 * Program to test the functionality of the queue
 * @author: Conor Paschenko <paschenko.c@husky.neu.edu>, James Herbstritt <herbstritt.j@husky.neu.edu>
 */

// prints a fail message to stderr then exits the process
void FAIL(const char* msg) {
  fprintf(stderr, "failed: %s\n", msg);
  exit(1);
}

// prints a success message to stdout
void OK(const char* msg) {
  printf("success: %s\n", msg);
}

// fails the process if a given boolean expression p is false, continues otherwise
void t_true(bool p, const char* msg) {
  if (!p) FAIL(msg); 
}

// two Queue's are equal when they have the same elements in the same order 
void equal_test() {
  String* s1 = new String("String one");
  Object* o2 = new Object();
  Queue* q1 = new Queue();
  Queue* q2 = new Queue();
  t_true(q1->equals(q2), "empty queues are equal");
  q1->queue_push(s1);
  t_true(!q1->equals(q2), "q1 and q2 are not equal");
  q2->queue_push(s1);
  t_true(q1->equals(q2), "q1 is equal to q2");
  q1->queue_push(o2);
  q1->queue_push(s1);
  q1->queue_push(s1);
  q2->queue_push(o2);
  q2->queue_push(s1);
  t_true(!q1->equals(q2), "q1 should not equal q2");

  OK("equal");

  delete q1;
  delete q2;
  delete s1;
  delete o2;
}

// checks if hashes are same which implies the two are equal
void queue_hashes() {
  String* s1 = new String("hash");
  String* s2 = new String("hash");
  Queue* q1 = new Queue();
  Queue* q2 = new Queue();
  q1->queue_push(s1);
  q2->queue_push(s2);
  t_true(q1->equals(q2), "q1 equals q2");
  t_true(q1->hash() == q2->hash(), "queues have the same hash and are therefore equal");

  OK("queue hashes");

  delete q1;
  delete q2;
  delete s1;
  delete s2;
}

// size increases as elements are pushed
void queue_push_increase_size() {
  Object* o1 = new Object();
  Object* o2 = new Object();
  Queue* q1 = new Queue();
  t_true(q1->getSize() == 0, "initial size is 0");
  q1->queue_push(o1);
  t_true(q1->getSize() == 1, "size increases to 1");
  q1->queue_push(o1);
  q1->queue_push(o1);
  q1->queue_push(o1);
  t_true(q1->getSize() == 4, "size increases to 4");

  OK("size increases correctly");

  delete q1;
  delete o1;
  delete o2;
}

// size decreases as elements are popped
void queue_pop_decrease_size() {
  Object* o1 = new Object();
  Object* o2 = new Object();
  Queue* q1 = new Queue();
  q1->queue_push(o1);
  q1->queue_push(o2);
  q1->queue_push(o2);
  q1->queue_push(o1);
  q1->queue_push(o1);
  t_true(q1->getSize() == 5, "size is 5");
  q1->queue_pop();
  t_true(q1->getSize() == 4, "size decreases to 4");
  q1->queue_pop();
  q1->queue_pop();
  t_true(q1->getSize() == 2, "size decreases to 2");
  
  q1->queue_pop();
  q1->queue_pop();
  q1->queue_pop();
  q1->queue_pop();
  t_true(q1->getSize() == 0, "size remains at 0");

  OK("size decreases correctly");

  delete q1;
  delete o1;
  delete o2;
}

// correct elements are popped
void queue_pop() {
  String* s1 = new String("one");
  String* s2 = new String("two");
  String* s3 = new String("three");
  Queue* q1 = new Queue();
  q1->queue_push(s1);
  q1->queue_push(s2);
  q1->queue_push(s3);
  t_true(s1->equals(q1->queue_pop()), "s1 should be popped");
  t_true(s2->equals(q1->queue_pop()), "s2 should be popped");
  t_true(s3->equals(q1->queue_pop()), "s3 should be popped");

  OK("pop works correctly");

  delete q1;
  delete s1;
  delete s2;
  delete s3;
}

// peeking returns the Queue's top element but does not remove it
void queue_frontElement() {
  String* s1 = new String("first");
  String* s2 = new String("second");
  Queue* q1 = new Queue();
  q1->queue_push(s1);
  q1->queue_push(s2);
  t_true(q1->getSize() == 2, "size is 2 before the peek");
  t_true(s1->equals(q1->frontElement()), "s1 is the top element");
  t_true(q1->getSize() == 2, "size is 2 after the peek");

  OK("queue peek");

  delete q1;
  delete s1;
  delete s2;
}

// popping or peeking an empty Queue should return a nullptr
void queue_pop_peek_empty() {
  String* s1 = new String("dummy");
  Queue* q1 = new Queue();
  q1->queue_push(s1);
  t_true(s1->equals(q1->queue_pop()), "popping once returns s1");
  t_true(q1->queue_empty(), "queue should now be empty");
  t_true(q1->queue_pop() == nullptr, "popping twice returns nullptr");
  t_true(q1->frontElement() == nullptr, "peeking return nullptr");

  OK("queue pop peek empty");

  delete q1;
  delete s1;
}


// runs the tests
int main() {
  equal_test();
  queue_hashes();
  queue_push_increase_size();
  queue_pop_decrease_size();
  queue_pop();
  queue_frontElement();
  queue_pop_peek_empty();
  return 0;
}
