//Task Based Concurrency
#include <iostream>
#include <thread>
#include<future>
void TaskCallable(){
    using namespace std::chrono_literals;

    for(int i=0;i<100;i++){
        std::cout<<".";
        std::this_thread::sleep_for(1s); //s literal is same as std::chrono::seconds(1)
    }
}

//std:async has overloaded methods 1) async(Callable,args) 2)async(policy,callable,args) where policy defines the behavior of async
//std::launch::deferred - the task is executed synchronously
//std::launch::async - the task is created asynchronously
//args are passed by value by default , so use std::ref() or std::cref()

//future is used for communication between threads
//future is created through a std::promise object and std::promise object is 
//created by std::async which directly returns the future.
//std::promise is an input channel and std::future is an output channel. So promise and future used together.
// Callable ---INPUTCHANNEL--> promise --OUTPUTCHANNEL--->future . this is done in a separate thread from the task async thread created to call Callable.This separate thread waits until the future gets the value.
int main(){
    //if you dont create a variable of future , then a temp variable is created and it blocks the main thread 
    //, so operation becomes synchronous even though async creates separate thread
    //async immediately returns and does not wait for the thread to be created.
    std::future<void> result = std::async(TaskCallable); //this returns future
    
    std::cout << "main() thread is getting completed"<<std::endl;
    
    //this is a blocking call and blocks the main thread
    result.get();
}