/*Function POinters are similar to Reference Methods in Java8
  They can be used as callback functions*/
#include <iostream>

 int fnReferredByPointerFn(int x){
     //creating pointer function to self
     int (*selfpointer)(int) = &fnReferredByPointerFn;
     using namespace std;
     for(int i=1;i<=x;i++){
         cout<<i;
     }
     if(x>0){
     cout<<endl;    
     (*selfpointer)(x-1);
     }
    return x+x;
}

void EndMessageHook(){
    using namespace std;
    cout<< "Function Pointers Discussion Completed"<<endl;
}

int main(){
    using namespace std;
    atexit(&EndMessageHook);
  //function pointer has to match the signature of the function being pointed to  
  /*RETURN_TYPE*/int (*pointerFn) (int)/*FUNC_ARGUMENT*/ = &fnReferredByPointerFn;  //& is optional

//calling func using pointer to the func. Two ways to call it
  //(*pointerFn)(5);
  pointerFn(5);
  cout<<"End of Operation main"<<endl;
    return 0;
}