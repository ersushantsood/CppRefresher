#include <iostream>
#include <list>
#include <thread>

std::list<int> lstData;
const int listSize = 600000;

void LongOperation(){
    std::cout << "[Starting long blocking operation]" << std::endl;
    for(int i=0;i < listSize; i++){
        lstData.push_back(i);
    }
}

int main(){
    std::cout << "[Main Operation started]" << std::endl;
    //Passing callable function in the thread constructor
    std::thread parallelThread(LongOperation);
    //if you want to detach the thread from the main thread you can detach it but then that thread is not joinable
    parallelThread.detach();
    std::cout << "[Main operation completed]" << std::endl;
    if( parallelThread.joinable()){
        parallelThread.join();
    }

    //as you made child thread detached so main function would not wait for child thread , so to pause the main use system("Pause")
    system("pause");
    return 0;
}