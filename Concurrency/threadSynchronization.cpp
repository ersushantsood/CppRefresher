#include <iostream>
#include <list>
#include <thread>
#include <mutex>
std::list<int> lstData;
const int listSize = 600000;
std::mutex g_Mutex;
void LongOperationCallable(){
    std::cout << "[Starting long blocking operation]" << std::endl;
    for(int i=0;i < listSize; i++){
        g_Mutex.lock();
        lstData.push_back(i);
        //if any exception come here then lock will never be released 
        //so use lockguard which will lock and unlock the mutex or release ownership on destruction/completion of SCOPE
        //if (i == 500){
            //return;
        //}
        g_Mutex.unlock();
    }
}

void LongOperationCallable2(){
    std::cout << "[Starting long blocking operation 2nd callable]" << std::endl;
    for(int i=0;i < listSize; i++){
        g_Mutex.lock();
        lstData.push_back(i);
        g_Mutex.unlock();
    }
}

int main(){
    std::cout << "[Main Operation started]" << std::endl;
    //Passing callable function in the thread constructor
    std::thread parallelThread(LongOperationCallable);
    std::thread parallelThread2(LongOperationCallable2);
    //if you want to detach the thread from the main thread you can detach it but then that thread is not joinable
    parallelThread.detach();
    std::cout << "[Main operation completed]" << std::endl;
    if( parallelThread.joinable() || parallelThread2.joinable()){
        parallelThread.join();
        parallelThread2.join();
    }

    //as you made child thread detached so main function would not wait for child thread , so to pause the main use system("Pause")
    system("pause");
    return 0;
}