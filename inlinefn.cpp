#include <iostream>
int IamNormalFn(int x){
    return x*x;
}

//In case of inline fn , no need to save the return address
// and its invoked inline and stack of the function call is also not
//created in the memory.

//Marking fn inline is just a request given to compiler and Excessive
//inlining would increase the binary size.
inline int IamInlineFn(int z){
    return z*z;
}

//create a macro to use fn as inline. Macro work by text substitution by 
//preprocessor and any expressions in macros are substituted as is and return
//incorrect result. Rather use inline functions to resolve this.
#define IamMacro_WillbeInlinefn(x) x+x+x

#define MacroWithExpression(y) y*y
int main() {
    using namespace std;
    int val = 5;
    int result = IamMacro_WillbeInlinefn(val);
    int incorrect = MacroWithExpression(val+2); //expected 49 answer y got substituted as 5+2*5+2
    int correct = IamInlineFn(val+2);
    cout<< result << endl;
    cout << "Expected 49 ,but got: "<< incorrect << endl;
    cout << "Expected 49 ,and got: "<< correct << endl;
    return 0;
}