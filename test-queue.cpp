#include <assert.h> 
#include "object.h"
#include "queue.h"

int main(int argc, char** argv) {

    Queue* queue1 = new Queue(10);
    Queue* queue2 = new Queue(5);
    Object* object1 = new Object();
    Object* object2 = new Object();
    queue1->queue_pop();
    queue1->queue_push(object1);
    queue1->queue_push(object2);
    assert(queue1->getSize() == 2);
    queue1->frontElement();

    assert(queue1->queue_full() == false);
    
    assert(queue1->frontElement()==object2);
    queue1->queue_empty();
    queue1->queue_pop();
   
    assert(queue1->getSize() == 1);
    assert(queue2->frontElement()==object2); 

    queue1->queue_pop();

    assert(queue1->queue_empty()); 

    assert(queue1->getSize() == 0);

    return 0;
}
