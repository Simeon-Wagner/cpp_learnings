
#include <string>
#include <iostream>
#include <string>
//Exercise 2.2 -> Write a function that gives back the vale x^y pow(int base, int exponent)
int pow(int base, int exponent){
    if(exponent == 0)
        return 1;

    return base * pow(base, exponent -1);
}
//Exercise 2.3 -> Write a recusive faculty function
int fac(int number){
    if (number == 0){
        return 1;
    }
    return number * fac(number -1);
}
//Exercise 2.5 -> Write a function that reverses the string based on the reference of the string 
void str_reverse(std::string& input){
    int start {0};
    int end = static_cast<int>(input.size()-1);
    char temp;
    while(start < end ){
        temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        end --;
        start ++;
    }
}

//Exercise 2.8 -> Write a function that returns true if the string passed is alphanumerical
bool isAlphaNumerical(const std::string& input){
    for(char c : input){
        if (c < 48 || (c >= 57 && c < 65) || (90 < c  && c < 97) ||  122 < c ){
            return false;
        }
    }
    return true;
}
int main(int argc, char** argv){
    std::cout << "The number 2 to the power of 3 is 8: Here the result: "<< pow(2,3) << std::endl;
    std::cout << "Faculty of 5 is 120. This is the result: "<<fac(5) << std::endl; 
    std::string name = "Simeon";
    str_reverse(name);
    std::cout << "This is my name (Simeon) reversed: " << name << std::endl;
    std::string alphaNum = "SimeonWagner222001";
    std::string notAlphaNum = "Simeon Wagner 2.2.2001";
    bool isAlphaNum = isAlphaNumerical(alphaNum);
    bool isNotAlphaNum = isAlphaNumerical(notAlphaNum);
    std::cout << alphaNum << " is alpha numerical :" << isAlphaNum <<"\n";
    std::cout << notAlphaNum << " is not alpha  numerical :" << isNotAlphaNum << std::endl;


}