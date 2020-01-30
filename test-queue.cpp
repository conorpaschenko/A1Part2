// lang::Cpp
#include <assert.h>
#include <iostream>
#include "object.h"
#include "string.h"
#include "queue.h"

/* Program to test methods (with their updated names) with both Objects 
 * and Strings to ensure expected functionality.
 *
 * We added more tests to be more thorough. One major addition is testing 
 * large Queues.
 *
 * authors: cella.c@husky.neu.edu and mooney.kyl@husky.neu.edu
 */

void OK(const char* m) { std::cout << m << "\n"; }

void testEqualsAndHash() {
    Queue* q1 = new Queue(); Queue* q2 = new Queue();
    Object* o1 = new Object(); Object* o2 = new Object();
    String* s1 = new String("Hello"); String* s2 = new String("World");

    /** Ensure empty Queues are equivalent: */
    assert(q1->equals(q2));
    assert(q1->hash() == q2->hash());

    /** Ensure non-empty Queue and empty Queues are not equivalent: */
    q1->push(s1);
    assert(not q1->equals(q2));
    assert(q1->hash() != q2->hash());

    /** Ensure Queues are equal after equivalent pushes of identical 
     *  elements: */
    q1->push(s2);
    q2->push(s1); 
    q2->push(s2);
    assert(q1->equals(q2));
    assert(q1->hash() == q2->hash());

    /** Ensure differently indexed Queues register as equivalent: */
    q1->pop(); 
    q1->pop();
    q1->push(s1);
    q1->push(s2);
    assert(q1->equals(q2));
    assert(q1->hash() == q1->hash());

    /** Ensure that Queue with no "pop"s so far registers as equivalent to
     *  a Queue with identically ordered elements */
    delete q1; delete q2; q1 = new Queue(); q2 = new Queue();
    for (size_t i = 0; i < 8; i++) q1->push(s1);
    for (size_t i = 0; i < 12; i++) q2->push(s2);
    for (size_t i = 0; i < 12; i++) q2->pop();
    // Then make q2 meaningfully identical to q1 (same elements in same order):
    for (size_t i = 0; i < 8; i++) q2->push(s1);
    assert(q1->equals(q2));
    assert(q1->hash() == q2->hash());

    /** Ensure Queues that are not equivalent do not register as such: */
    delete q1; delete q2; q1 = new Queue(); q2 = new Queue();
    q1->push(s1);
    q1->push(s2);
    q2->push(s2);
    q2->push(s1);
    assert(not q1->equals(q2));
    assert(q1->hash() != q2->hash());

    delete q1; delete q2; delete o1; delete o2; delete s1; delete s2;
    OK("6 - equals() and hash()");
}

void testEmpty() {
    Queue* q1 = new Queue(); Queue* q2 = new Queue();
    Object* o1 = new Object(); Object* o2 = new Object();
    String* s1 = new String("Hello"); String* s2 = new String("World");

    /** Ensure a Queue is empty: */
    assert(q1->is_empty());

    /** Ensure a non-empty Queue is not empty: */
    q1->push(s1);
    assert(not q1->is_empty());

    delete q1; delete q2; delete o1; delete o2; delete s1; delete s2;
    OK("5 - is_empty()");
}

void testGetSize() {
    Queue* q1 = new Queue(); Queue* q2 = new Queue();
    Object* o1 = new Object(); Object* o2 = new Object();
    String* s1 = new String("Hello"); String* s2 = new String("World");

    /** Check the size of an empty Queue: */
    assert(q1->size() == 0);

    /** Add 1 element, check if size is 1: */
    q1->push(s1);
    assert(q1->size() == 1);

    /** Push 40 elements, check if size is 40: */
    for (size_t i = 0; i < 40; i++) q2->push(s2);
    assert(q2->size() == 40);

    delete q1; delete q2; delete o1; delete o2; delete s1; delete s2;
    OK("4 - size()");
}

void testPop() {
    Queue* q1 = new Queue(); Queue* q2 = new Queue();
    Object* o1 = new Object(); Object* o2 = new Object();
    String* s1 = new String("Hello"); String* s2 = new String("World");

    /** Try to pop on empty: */
    q1->pop(); // does nothing

    /** Try to pop from a populated Queue until the Queue is empty: */
    q1->push(o1);
    q1->push(s2);
    assert(q1->size() == 2);
    q1->pop();
    q1->pop();
    assert(q1->size() == 0);

    /** Pop until resize down: */
    for (size_t i = 0; i < 16; i++) q2->push(s1);
    for (size_t i = 0; i < 8; i++) q2->push(s2);
    for (size_t i = 0; i < 15; i++) q2->pop();
    assert(q2->front_element()->equals(s1));
    assert(q2->size() == 9);
    q2->pop();
    assert(q2->front_element()->equals(s2));

    delete q1; delete q2; delete o1; delete o2; delete s1; delete s2;
    OK("3 - pop()");
}

void testFrontElement() {
    Queue* q1 = new Queue(); Queue* q2 = new Queue();
    Object* o1 = new Object(); Object* o2 = new Object();
    String* s1 = new String("Hello"); String* s2 = new String("World");
    
    /** Trying to peek from an empty Queue: */
    q1->front_element();

    /** Peeking at an Object: */
    q1->push(o1);
    assert(q1->front_element()->equals(o1));

    /** Peeking at a String after pops: */
    q1->push(s1);
    q1->push(s2);
    q1->pop();
    assert(q1->front_element()->equals(s1));

    delete q1; delete q2; delete o1; delete o2; delete s1; delete s2;
    OK("2 - front_element()");
}

void testPush() {
    Queue* q1 = new Queue(); Queue* q2 = new Queue();
    Object* o1 = new Object(); Object* o2 = new Object();
    String* s1 = new String("Hello"); String* s2 = new String("World");
    
    /** Adding 1 element to an empty Queue: */
    assert(q1->size() == 0);
    q1->push(o1);
    assert(q1->size() == 1);

    /** Testing adding to a non-empty Queue: */
    q1->push(s1);
    assert(q1->size() == 2);
    assert(q1->front_element()->equals(o1));

    /** Testing adding until resize: */
    for (size_t i = 0; i < 17; i++) q2->push(s1);
    assert(q2->size() == 17);
    
    delete q1; delete q2; delete o1; delete o2; delete s1; delete s2;
    OK("1 - push()");
}

int main(int argc, char** argv) {
    testPush();
    testFrontElement();
    testPop();
    testGetSize();
    testEmpty();
    testEqualsAndHash();
    return 0; 
}
