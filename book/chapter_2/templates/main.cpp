#include <iostream>
#include <vector>

#include "./template.hpp"


#define PRINT(x,y) std::cout << x << ": " << y << std::endl;


//Exercise 2.13:
//Write a function that return the value of a ploynom. Avoid calculating
//the power of a number multiple times.
template<typename T>
T polynomeCalc (std::vector<T> coef, T x){
    T result = 0;
    int pow = 1;
    for(int i = 0; i < coef.size(); i++){
        result += coef[i]*pow;
        pow *= x;
    }
    return result;
}

int main (int argc, char ** argv){
    int i; PRINT("Integer", getType(i));
    float f; PRINT("Float", getType(f));
    char c; PRINT("Char", getType(c));
    long l; PRINT("Long", getType(l));
    unsigned int u; PRINT("Unsigned Int", getType(u));
    std::string s; PRINT("String", getType(s))

    i = -23;
    std::cout << "Absolute value of -23: " << absolute(i) << std::endl;

    //testing polynome calculator
    std::vector<int> coef = {1,2,3};
    int x = 2;
    std::cout << "The polynome 3x^2 + 2x + 1 with x=2 equals too: " << polynomeCalc(coef, x) << std::endl;  
}