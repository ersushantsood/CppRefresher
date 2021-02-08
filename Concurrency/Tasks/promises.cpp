//Promise provides a way to store a value or an exception
//This is called the shared state
//promise/future are used together and are 2 endpoints of the communication channel
// promise is an input channel and future is an output channel
//Threads use promise and future to share data with each other.
//promise receives the value from the task/callable return value or populated explicitly

//Task Based Concurrency
#include <iostream>
#include <thread>
#include<future>
//passing data using promise to callable
int TaskCallable(std::promise<int> & data){
    using namespace std::chrono_literals;
    auto future = data.get_future();
    //here callable will be blocked until main sends the data
    std::cout<< "TASKCALLABLE IS WAITING";
    auto count = future.get();
    std::cout<< "TASKCALLABLE RECIEVED THE COUNT";
    int sum{};
    for(int i=0;i<100;i++){
        sum+=i;
        std::cout<<".";
        std::this_thread::sleep_for(1s); //s literal is same as std::chrono::seconds(1)
    }

    //if you throw an exception from the task , then that exception is passed to promise and to future to the main as well as return from async
    //no need to create an exception pointer to pass to promise as its taken care by the runtime automatically.
    //throw std::runtime_error("Failed to add the data");

    return sum;
}

// Callable ---INPUTCHANNEL--> promise --OUTPUTCHANNEL--->future . this is done in a separate thread from the task async thread created to call Callable.This separate thread waits until the future gets the value.
int main(){
    using namespace std::chrono_literals;
    //passing data from main to callable using promise
    std::promise<int> promisedata;
    //if you dont create a variable of future , then a temp variable is created and it blocks the main thread 
    //, so operation becomes synchronous even though async creates separate thread
    //async immediately returns and does not wait for the thread to be created.
    //std::future<int> result = std::async(TaskCallable,13); //this returns future
    std::future<int> result = std::async(std::launch::async,TaskCallable,std::ref(promisedata));
    
    //callable thread will be blocked for 4 secs
    std::this_thread::sleep_for(4s);

    try{
    //throw std::runtime_error("Failed to set count");
    //one can set value only once in promise
    promisedata.set_value(10);
    }
    catch(std::exception &ex){
        //promise can also pass the exception
        //exception can only be passed as shared pointer shared_ptr
        promisedata.set_exception(std::make_exception_ptr(ex));
    }
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