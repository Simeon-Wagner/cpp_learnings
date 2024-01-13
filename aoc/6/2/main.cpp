#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>

long long getNumber(std::string line) {
    long long nr;
    int index = 0;
    std::string number;
    while (index < line.size()){
        while((line[index] >= 48 && line[index] <= 57) || line[index] == 32 ){
            if (line[index] != 32){
                number += line[index];
            }
            index ++;
        }
        index ++;
    } 
    nr = std::stoll(number);
    return nr;
}

std::unordered_map<std::string, long long> readFile(std::string path){
    std::ifstream file(path);
    if(!file.is_open()){
        std::cerr << "File was not found " << path << std::endl;
    }
    std::unordered_map<std::string, long long> map;
    std::string line;
    bool firstLine = true;
    while (std::getline(file, line))
    {
        if (firstLine){
            map["Time"] = getNumber(line);
            firstLine = false;
        }
        else{
            map["Distance"] = getNumber(line);
        }
    }
    std::cout << "Time: " << map["Time"] << std::endl;
    std::cout << "Distance: " << map["Distance"] << std::endl;

    return map;
    
}

long long distance(long long loadingTime, long long time){
    return (-1)*std::pow(loadingTime,2) + loadingTime*time;
}


int main (int argc, char ** argv){
    std::string path = "C:\\dev\\aoc\\6\\input.txt";
    std::unordered_map <std::string, long long> map = readFile(path);

    long long count = 0;
    long long load = 0;
    while(load <= map["Time"]){
        if(distance(load, map["Time"]) > map["Distance"]){
            count++;
        }
        load++;
    }

    std::cout << "Options: " << count << std::endl;
}