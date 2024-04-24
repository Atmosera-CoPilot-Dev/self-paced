
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

/*
https://en.cppreference.com/w/cpp/thread/condition_variable
From the docs:

The thread that intends to modify the shared variable must:

1) Acquire a std::mutex (typically via std::lock_guard)
2) Modify the shared variable while the lock is owned
3) Call notify_one or notify_all on the std::condition_variable (can be done after releasing the lock)
4) leave the app
*/

template <typename T>
class Queue
{
public:
    T pop()
    {
        std::unique_lock<std::mutex> mlock(_mutex);
        // Instead of a while loop, this also works: _condition.wait(_mlock,[&](){ return !_queue.empty(); });
        while (_queue.empty())
        {
            _condition.wait(mlock);
        }
        auto item = _queue.front();
        _queue.pop();
        return item;
    }

    void push(const T &item)
    {
        std::unique_lock<std::mutex> mlock(_mutex);
        _queue.push(item);
        mlock.unlock();

        _condition.notify_one();
    }

private:
    std::queue<T> _queue;
    std::mutex _mutex;
    std::condition_variable _condition;
};

int main()
{
    const int size = 10;
    Queue<int> queue;

    auto qpush = [&]()
    {
        for (int i = 1; i <= size; i++)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            queue.push(i);
        }
    };

    auto qpull = [&]()
    {
        for (int i = 1; i <= size; i++)
        {
            std::cout << queue.pop() << std::endl;
        }
    };

    std::thread pub(qpush);
    std::thread sub(qpull);

    pub.join();
    sub.join();
}
