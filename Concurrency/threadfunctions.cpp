#include <iostream>
#include <thread>

void Process(){
    std::this_thread::get_id();
    std::this_thread::sleep_for(std::chrono::seconds(4));
}

int main(){
    std::thread t1(Process);
    auto threadId = t1.get_id();
    std::cout<< threadId << std::endl;
    //to access the native thread of the OS used by c++ thread lib, in case of linux its Pthread and in case of windows its HANDLE
    t1.native_handle();

    // it returns the hardware topology or cpu cores
    int cores = std::thread::hardware_concurrency();
    t1.join();
    return 0;
}