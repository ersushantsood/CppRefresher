#include <iostream>

class Animal {
    public:
        void Type() {
            std::cout<< "Animal Carnivorous,Omnivorous or Herbivorous" << std::endl;
        }
        void Run() {
            std::cout<< "Animal Runs very fast" << std::endl;
        }
        void Home() {
            std::cout<< "Animal lives in jungle" << std::endl;
        }
};

//Dog extends Animal i.e inherits from Animal
class Dog : public Animal {
    public:
     void Home() {
        std::cout<< "Animal lives in home" << std::endl;
    }
};

int main() {
    Dog d;
    d.Home();
    d.Run();
    d.Type();
}
