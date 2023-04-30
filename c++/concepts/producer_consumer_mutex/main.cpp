#include "threads.h"


void func()
{
  std::cout<<" running"<<std::endl;
}

int main() {


 std::cout<<".............."<<"\n";
    Producer producer;
    Consumer consumer;
    std::thread t1(&Producer::producer, Producer());
    std::thread t2(&Consumer::consumer, Consumer());

    t1.join();
    t2.join();   

    return 0;
}
