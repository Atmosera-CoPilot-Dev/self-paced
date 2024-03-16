
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

/*
https://en.cppreference.com/w/cpp/thread/condition_variable
*/

template <typename T>
class Queue
{
public:
    T pop()
    {
        throw std::runtime_error("not implemented");
    }

    void push(const T &item)
    {
        throw std::runtime_error("not implemented");
    }

private:
    std::queue<T> _queue;
    std::mutex _mutex;
    std::condition_variable _condition;
};

// demonstrates the use of a thread-safe queue. The queue is implemented using the Queue class.

int main()
{
    return 1;
}