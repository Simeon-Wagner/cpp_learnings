#include "person.h"
#include <iostream>


int main(int argc, char ** argv){
    Person person ("Annabelle Meier", 22);
    std::cout << person.getName() << " is " <<   person.getAge() << " years old." << std::endl;
    person.setAge(23);
    std::cout << person.getName() << " is " << person.getAge() << " years old." << std::endl;
    person.setName("Annabelle Schulz");
    std::cout << "She married, her name is " << person.getName() << " now." << std::endl;
    }