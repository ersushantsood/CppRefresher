/*
Different memory areas allocated to C/C++ programs
Stack : allocated by runtime automatically to local variables. Its managed by runtime.
data section : allocated to global and static data . Its managed by runtime.
heap : allocated at runtime when program runs and if programmer allocates any memory in heap , then it has to be managed by programmer only.
*/

/*C provides functions to dynamically allocate memory in heap
malloc : returns address to raw memory and does not initialize memory
calloc : return memory initialized to zero

C++ provides 2 operators for Dynamic memory allocation
new : allocates memory in heap
delete: deallocates memory from heap
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int main(){
    int *pointerToDynMemAllocatedAddress = (int*)malloc(sizeof(int)); //(int*) is explicit casting.
    if(pointerToDynMemAllocatedAddress == NULL){
        std::cout<<"failed to initialize the memory";
        return -1;
    }
    *pointerToDynMemAllocatedAddress = 10;
     std::cout<<*pointerToDynMemAllocatedAddress;
    free(pointerToDynMemAllocatedAddress);
    //good practice is to assign null to pointer once memory is freed 
    //so that if you accidently call free(pointerToDynMemAllocatedAddress)
    //to pointer whose memory is already deallocated ,program will not crash
    pointerToDynMemAllocatedAddress = NULL;

    //Using calloc
    int *pointerToDynMemAllocatedAddress_usingcalloc = (int*)calloc(1,sizeof(int));
    *pointerToDynMemAllocatedAddress_usingcalloc = 15;
    std::cout<<*pointerToDynMemAllocatedAddress_usingcalloc;
    free(pointerToDynMemAllocatedAddress_usingcalloc);

    //C++ new and delete
    // DATA_TYPE *pointer = new DATA_TYPE(optional_args_to_initialize_mem)
    // delete pointer
    int *p_without_init_new = new int;  //it will be like malloc , just return raw mem
    int *p_using_new = new int(10); //here you are initializing memory with 10
    *p_using_new = 11;
    delete p_using_new;
    p_using_new = nullptr;  //otherwise pointer will be dangling pointer

    //new for arrays using new[] and delete[]
    // DATA_TYPE *var = new DATA_TYPE[arr_size]
    //below allocates memory locations of 5 integers , so allocating multiple locations with one NEW operator
    int *p_arr = new int[5];
    for(int i=0; i<=4;i++){
        p_arr[i] = i;
    }
    //or initialize the memory alongwith new
    // int *p_arr2 = new int[5]{1,2,3,4,5};
    std::cout<<*p_arr;
    delete []p_arr;
    p_arr = nullptr;

    //new with chars
    char *p_char = new char[4]; //allocate extra byte for null terminating char
    strcpy_s(p_char,4,"c++"); //c++ is only 3 bytes , 1 etra for null term char.

    //Using New for memory allocation for pointers and use it for 2D array
    int *p_row = new int[3];
    int *p_col = new int[3];

    int **p_pointers = new int*[2];  //type is pointer here with new and left is pointer to pointer
    p_pointers[0] = p_row;
    p_pointers[]

    return 0;


    /*
    Malloc vs New
    1.Malloc is a function but New is an operator
    2.Malloc cannot initialize the memory but New can.
    3.Malloc cannot call the constructors of objects but New can.
    4.Malloc cannot be customized but New can be using Operator overloading
    5.Malloc returns void pointer that need to be typecasted whereas New provides the type it is used with
    */
}