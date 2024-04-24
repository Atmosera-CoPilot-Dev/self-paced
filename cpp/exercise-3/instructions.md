# Producer Consumer Application

Use Copilot to buildout the functionality of a producer-consumer using a a thread-safe queue data structure.

## C++ threading and condition variables

### In the template:

Implement a method `pop()` that will:
 1) acquire the lock
 2) wait until the queue is not empty
 3) pop the item
 4) release the lock

Implement a method `push()` that will:
 1) acquire the lock
 2) push the item
 3) release the lock
 4) notify the condition variable

### In main():

Here's a breakdown of the code to implement:

1) Create a Queue object named `queue`. This queue holds integers.

2) Declare two lambda functions, `qpush` and `qpull`. These functions are used to push and pop items from the queue, respectively.

`qpush` is a producer function. It pushes integers from 1 to size (10) into the queue. Before each push operation, the thread is made to sleep for 1 second. This simulates a producer that generates a new item every second.

`qpull` is a consumer function. It pops items from the queue and prints them to the console. It tries to pop size (10) items from the queue. If the queue is empty, it will block until an item is available.

3) Create two threads, `pub` and `sub`. `pub` runs the `qpush` function, and `sub` runs the `qpull` function. This simulates a producer-consumer scenario where one thread is producing items and another thread is consuming them.

4) Call The `join` method on both threads. This causes the main thread to block until both pub and sub have finished executing. This is necessary to prevent the main thread from exiting before pub and sub have finished their work.
