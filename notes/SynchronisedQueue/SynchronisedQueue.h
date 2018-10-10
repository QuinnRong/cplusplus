#ifndef SYNCHRONISEDQUEUE
#define SYNCHRONISEDQUEUE

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class SynchronisedQueue
{
public:
    void push(const T& data);
    void pop();
    T& front();
    int size();
    bool empty();

private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cond;
};

template <typename T>
void SynchronisedQueue<T>::push(const T& data)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_queue.push(data);
    m_cond.notify_one();
}

template <typename T>
void SynchronisedQueue<T>::pop()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    while (m_queue.size() == 0)
    {
        m_cond.wait(lock);
    }
    m_queue.pop();
}

template <typename T>
T& SynchronisedQueue<T>::front()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    while (m_queue.size() == 0)
    {
        m_cond.wait(lock);
    }
    return m_queue.front();
}

template <typename T>
int SynchronisedQueue<T>::size()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_queue.size();
}

template <typename T>
bool SynchronisedQueue<T>::empty()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_queue.empty();
}

#endif