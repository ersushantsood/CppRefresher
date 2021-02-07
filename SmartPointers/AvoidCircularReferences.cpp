#include <iostream>
#include <memory>
class Kids;
class Mother {
public:
    std::shared_ptr<Kids> m_kids;
    Mother() {
        std::cout << "Mother()"<<std::endl;
    }
    ~Mother() {
        std::cout << "~Mother()"<< std::endl;
    }
};

class Kids {
public:
    //this will avoid circular reference Memory issue, if you used shared pointer then it will cause Memory issue as it will also increase the ref count of mother pointer and maintain 
    std::weak_ptr<Mother> m_mother;
    Kids() {
        std::cout << "Kids()"<<std::endl;
    }
    ~Kids() {
        std::cout << "~Kids()"<< std::endl;
    }
};

int main() {
    std::shared_ptr<Kids> kids{new Kids{}};
    std::shared_ptr<Mother> mother{new Mother{}};

    kids->m_mother = mother;
    mother->m_kids = kids;

    mother = nullptr;  
}