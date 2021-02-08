//Task Based Concurrency
#include <iostream>
#include <thread>
#include<future>
int TaskCallable(int count){
    using namespace std::chrono_literals;
    int sum{};
    for(int i=0;i<100;i++){
        sum+=i;
        std::cout<<".";
        std::this_thread::sleep_for(1s); //s literal is same as std::chrono::seconds(1)
    }
    return sum;
}

// Callable ---INPUTCHANNEL--> promise --OUTPUTCHANNEL--->future . this is done in a separate thread from the task async thread created to call Callable.This separate thread waits until the future gets the value.
int main(){
    using namespace std::chrono_literals;
    //if you dont create a variable of future , then a temp variable is created and it blocks the main thread 
    //, so operation becomes synchronous even though async creates separate thread
    //async immediately returns and does not wait for the thread to be created.
    //std::future<int> result = std::async(TaskCallable,13); //this returns future
    std::future<int> result = std::async(std::launch::async,TaskCallable,13);
    
    //deferred makes async run synchronously
    //std::future<int> result = std::async(std::launch::deferred,TaskCallable,13);
    std::cout << "main() thread is getting completed"<<std::endl;
    if(result.valid()){
        result.wait();
        //it returns enum with values std::future_status::deferred or ready or timeout
        auto futurestatus = result.wait_for(4s); //s literal same as std::chrono::seconds(4)
        auto sum = result.get();
        std::cout <<sum<<std::endl;
    }
    //this is a blocking call and blocks the main thread
    result.get();
}