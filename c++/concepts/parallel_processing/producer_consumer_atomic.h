#include <atomic>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <vector>


std::atomic<bool>  g_ready{false};
int g_data;

void producer()
{
    while(true)
    {
        auto randNum = std::rand();
        g_data = randNum;
        g_ready.store(true);
    }
}

void consumer()
{
    while(true)
    {
        if (g_ready.load())
        {
            std::cout<<"random number: "<<g_data<<"\n";
            g_ready.store(false);
        }
    }
}
