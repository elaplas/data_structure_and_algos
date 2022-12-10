#include <iostream>
#include <atomic>
#include <thread>
#include <pthread.h>


std::atomic<bool> g_data_ready{false};
int g_data;

[[noreturn]] void producer()
{
  while (true)
  {
    g_data = std::rand();
    g_data_ready.store(true) ;
    while (g_data_ready.load())
    {
      // do nothing
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
  }
};

[[noreturn]] void consumer()
{
  while (true)
  {
    std::cout<<g_data<<std::endl;
    g_data_ready.store(false);
    while (!g_data_ready.load())
    {
      // do nothing
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
  }
}

int main() {

  std::thread t1(producer);
  std::thread t2(consumer);

  t1.join();
  t2.join();
  return 0;
}
