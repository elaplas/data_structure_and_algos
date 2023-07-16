#pragma

#include <iostream>

#include <mutex>
#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <vector>


// for exchanging data
int g_data;
// it could happen that the consumer is too fast 
// and read a produced data more frequently than it is produced
bool g_ready = false;
// for synchronization 
std::mutex g_mutex;

void producer()
{
    while(true)
    {
        auto randNum = std::rand();
        std::unique_lock<std::mutex> uniqueLock(g_mutex);
        g_data = randNum;
        g_ready = true;
        uniqueLock.unlock();
    }
}

void consumer()
{
    while(true)
    {
        if (g_ready)
        {
            std::unique_lock<std::mutex> uniqueLock(g_mutex);
            std::cout<<"random number: "<<g_data<<"\n";
            g_ready=false;
            uniqueLock.unlock();
        }
    }
}
