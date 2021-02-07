#include <iostream>
#include <memory>
class Usb {
    int *driver_pvalue{};
public:
    void SetValue(int *p) {
        driver_pvalue = p;
    }
    void Print() {
        std::cout << "value is:" << *driver_pvalue << std::endl;
    }
};

class Smart_Usb {
    std::shared_ptr<int> driver_pvalue;
public:
    void SetValue(std::shared_ptr<int> pvalue) {
        driver_pvalue = pvalue;
    }
    void Print() {
        std::cout<< "Shared pointer Ref Count"<< driver_pvalue.use_count()<< std::endl;
        std::cout << "value is:" << *driver_pvalue << std::endl;
    }
};

//(We reduced the dependency of class on Shared pointer and refered shared pointer using weak pointer)
// As SHARED pointers can lead to MEMORY LEAKS due to Circular references as they maintain the REF count.
class Smart_Usb_with_WeakPtr {
    std::weak_ptr<int> driver_pvalue;
public:
    void SetValue(std::weak_ptr<int> pvalue) {
        driver_pvalue = pvalue;
    }
    void Print() {
        std::cout<< "Shared pointer Ref Count"<< driver_pvalue.use_count()<< std::endl;
     
        if(driver_pvalue.expired()){
            std::cout<<"SHARED POINTER IS ALREADY DELETED AND MEMORY IS RELEASED and REFCOUNT is 0,SO WEAK POINT CANNOT access shared pointer's underlying pointer";
            return;
        }

        //lock will will return a shared pointer and ref count is incremented by 1.
        auto sp = driver_pvalue.lock();

        std::cout << "value is:" << *sp<< std::endl;
        std::cout<< "Shared pointer Ref Count via weak pointer"<< sp.use_count()<< std::endl;
    }
};

int main(){
    Usb usb;
    int driver_num{};
    std::cin >> driver_num;
    int *pointer = new int{driver_num};
    usb.SetValue(pointer);
    if(*pointer > 10){
        delete pointer;
        //when this pointer got deleted , USB pointer did not know 
        //usb.Print will print garbage, to communicate that use smart pointers
        pointer = nullptr;
    }
    usb.Print();
    delete pointer;

    //starting to use shared pointer
    Smart_Usb smart_usb;
    int smart_num{};
    std::cin >> smart_num;
    std::shared_ptr<int> shrdpointer{new int{smart_num}};
    smart_usb.SetValue(shrdpointer);
    if(*shrdpointer > 10){
        //no need to call delete here as its taken care by smart pointer
        //here only one pointer is null , so reference count is reduced by 1
        //but smart_usb reference is not decremented and memory is not released.
        //TO DO THAT USE WEAK POINTER to help releasing Class member variable shared pointer memory 
        //as soon passed pointer is set to null
        shrdpointer = nullptr;
    }
    //smart pointer will take care of shared pointer being set to nullptr
    //and communicate to the Class smart_usb member variable
    smart_usb.Print();


    //USING WEAK POINTERS : 
    //=> Weak pointers are initialized refering to shared pointer
    //=> weak pointer has access to control block of shared pointer, so it has access to REFERENCE count
    //=>by calling weak pointer lock method, one can lock the shared pointer and access the underlying pointer
    //HELPED IN POINTING WEAKLY TO A RESOURCE if its available or not.
    Smart_Usb_with_WeakPtr smartweak_usb;
    int smartweak_num{};
    std::cin >> smartweak_num;
    std::shared_ptr<int> shrdpointer_passedtoweakptr{new int{smartweak_num}};
    smartweak_usb.SetValue(shrdpointer_passedtoweakptr);
    if(*shrdpointer_passedtoweakptr > 10){
        // as weak pointer has the access to the ref count and control block of shared pointer
        shrdpointer_passedtoweakptr = nullptr;
    }
    //smart pointer will take care of shared pointer being set to nullptr
    //and communicate to the Class smart_usb member variable
    smartweak_usb.Print();

}


