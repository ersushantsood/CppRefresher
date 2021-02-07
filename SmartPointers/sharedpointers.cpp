#include <memory>
#include <iostream>
//SMART POINTERS keep reference to raw pointers.
/*class OpenSourceProject {

};
class OpensourceContributor {
    OpenSourceProject *ptrProject;
public:
    void SetProject(OpenSourceProject *p){
        ptrProject = p;
    }
    //method which return pointer will have either method name start with * or there will be *<WHITESPACE>methodName()
    OpenSourceProject *GetProject()const {
        return ptrProject;
    }
};

OpensourceContributor * AssignOpensourceProject(){
    //ptr_opensource can be shared among other parts of program
    // so this pointer cannot be deleted and freed memory
    //rather than use shared_pointers
    OpenSourceProject *ptr_opensource = new OpenSourceProject{};
    OpensourceContributor *ptr_contrib = new OpensourceContributor{};
    ptr_contrib->SetProject(ptr_opensource);
    return ptr_contrib;
}*/

//Now rewriting above by sharedpointers.
//Shared ptr keeps the count of the references created while getting copied or when passed as argument to methods
//When reference count is zero and shared pointer will destroy itself.
class OpenSourceProject {

public:
    ~OpenSourceProject() {
        std::cout<< "Destroy OpensourceProject called"< std::endl; 
    }
};
class OpensourceContributor {
    std::shared_ptr<OpenSourceProject> ptrProject;
public:
    void SetProject(std::shared_ptr<OpenSourceProject> p){
        ptrProject = p;
    }
    //method which return pointer will have either method name start with * or there will be *<WHITESPACE>methodName()
    std::shared_ptr<OpenSourceProject> GetProject()const {
        return ptrProject;
    }
};

OpensourceContributor * AssignOpensourceProject(){
    //ptr_opensource can be shared among other parts of program
    std::shared_ptr<OpenSourceProject> ptr_opensource {new OpenSourceProject{}};
    OpensourceContributor *ptr_contrib = new OpensourceContributor{};
    ptr_contrib->SetProject(ptr_opensource);
    return ptr_contrib;
}

int main() {
    auto sp = AssignOpensourceProject();
}