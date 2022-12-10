//
// Created by z639627 on 3/3/21.
//

#ifndef PRODUCER_CONSUMER_THREADS_THREADS_H_
#define PRODUCER_CONSUMER_THREADS_THREADS_H_

#include <mutex>
#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>

std::mutex g_mutex;

int g_data {0};
bool data_ready {false};

class Producer {

 public:

  int produceData()
  {
    return std::rand();
  }
  void producer()
  {
    while (true)
    {
      std::unique_lock<std::mutex> uniqueLock(g_mutex);
      g_data = produceData();
      data_ready=true;
      uniqueLock.unlock();

      while(data_ready)
      {

      }
    }
  }
};

class Consumer{

 public:

  void consumeData()
  {
    std::cout<<"two times received data is: "<< g_data<<"\n";
  }

  void consumer()
  {
    while (true)
    {
      while (!data_ready)
      {

      }
      std::unique_lock<std::mutex> uniqueLock (g_mutex);
      consumeData();
      uniqueLock.unlock();
      data_ready=false;
    }
  }

};

#endif //PRODUCER_CONSUMER_THREADS_THREADS_H_
