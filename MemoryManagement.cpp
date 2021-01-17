/*
Different memory areas allocated to C/C++ programs
Stack : allocated by runtime automatically to local variables. Its managed by runtime.
data section : allocated to global and static data . Its managed by runtime.
heap : allocated at runtime when program runs and if programmer allocates any memory in heap , then it has to be managed by programmer only.
*/

/*C provides functions to dynamically allocate memory in heap */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *pointerToDynMemAllocatedAddress = malloc(sizeof(int));
    *pointerToDynMemAllocatedAddress = 10;
    printf("%s", *pointerToDynMemAllocatedAddress);
    free(pointerToDynMemAllocatedAddress);
    return 0;
}