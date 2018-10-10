#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>

#include "SynchronisedQueue.h"

using namespace std;

#define MAX_SIZE 10

SynchronisedQueue<int> MyQueue;

void* InsertToQueue(void*)
{
    cout << "Insert Started" << endl;
    int i = 0;
    while (1)
    {
        if (MyQueue.size() < MAX_SIZE)
        {
            MyQueue.push(++i);
        }
        else
        {
            usleep(1000);
        }
    }
}

void* ConsumeFromQueue(void*)
{
    cout << "Comsume Started" << endl;
    while (1)
    {
        if (!MyQueue.empty())
        {
            cout << "value is " << MyQueue.front() << endl;
            MyQueue.pop();
        }
        else
        {
            usleep(1000);
        }
    }
}

int main()
{
    cout << "Test Started" << endl;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_t insertThread, comsumeThread;
    pthread_create(&insertThread, &attr, &InsertToQueue, NULL);
    pthread_create(&comsumeThread, &attr, &ConsumeFromQueue, NULL);

    pthread_join(insertThread, NULL);
    pthread_join(comsumeThread, NULL);
}
