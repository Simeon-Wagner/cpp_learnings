#include <string>
// #include <exception>

class Person{
private:
std::string name;
unsigned int age;

public:
Person(std::string oneName, unsigned int oneAge) : name{oneName}, age{oneAge}{};

void setName(std::string newName){
    name = newName;
}
void setAge(unsigned int newAge){
    age = newAge;
}

unsigned int getAge(){
    return age;
}

std::string getName(){
    return name;
}

};