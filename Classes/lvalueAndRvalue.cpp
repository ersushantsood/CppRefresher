#include "iostream"
//this function returns r-value. R-values are those whose value is maintained only 
//durng the evaluation of expression and no values can be assigned to r-values
int add(int x,int y){
    return x+y;
}

//returning l-value, reference is considered l-value
int & ReturnLValue(int &x,int &y){
    x *=x;
    y *=y;
    return x;
}

//this is arg as lvalue reference overloaded fn
void CheckOutput(int &x) {
    std::cout << "CheckOutput(int&) lvalue reference as arg" << std::endl;
}

//this is arg as constant lvalue reference overloaded fn
void CheckOutput(const int &x) {
    std::cout << "CheckOutput(const int&) constant lvalue reference as arg" << std::endl;
}

//this is arg as rvalue reference overloaded fn
void CheckOutput(int &&x) {
    std::cout << "CheckOutput(int&&) rvalue reference as arg" << std::endl;
}

//l-value references and r-value references
// r-value reference is created to a temporary and created using &&
// R-value references always bind to temporaries and never bind to l-value
// l-value reference always bind to l-value and cannot bind to temporaries
// One can overload methods based on lvalue and rvalue references

int main(){
    int x =4; // here x is l-value and 4 is R-value

    //r-value reference
    int &&rval = 12;
    int &&rval2 = add(4,5); // add returns r-value so it could bind

    //r-value reference cannot be bound to l-value
    int x = 0;
    //int &&rval_illegal = x;

    int z=4;
    int v =3;

    //l-value reference
    int &ref = ReturnLValue(z,v);

    CheckOutput(z);
    CheckOutput(10); //in overloading , const or temp rvalues will always bind to rvalue references
}