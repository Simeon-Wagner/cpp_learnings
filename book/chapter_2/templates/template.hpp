#include <string>
#include <typeinfo>

template<typename T>
std::string getType( T &V){
    return typeid(V).name();
}

template<typename T>
T absolute(T &V){
    return V < 0 ? (-1) * V : V;
}

