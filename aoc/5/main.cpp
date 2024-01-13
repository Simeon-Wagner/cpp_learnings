#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

struct x2y
{
    int x;
    int y;
    int range;
};
std::vector<int> seeds;
std::vector<x2y> seed2Soil;
std::vector<x2y> soil2Fertilizer;
std::vector<x2y> fertilizer2Water;
std::vector<x2y> water2Light;
std::vector<x2y> light2Temperature;

std::unordered_map<int, std::vector<x2y>> map = {
{1, seed2Soil},
{2, soil2Fertilizer},
{3, fertilizer2Water},
{4, water2Light},
{5, light2Temperature}
};

x2y stringToMap(std::string line){
    x2y map;
    int firstDiv = line.find(" ");
    int length = line.size() - firstDiv;
    map.x = std::stoi(line.substr(0, firstDiv));
    std::string secLine = line.substr(firstDiv, length);  
    int secondDiv = secLine.find(" ");
    map.y = std::stoi(secLine.substr(0, secondDiv));
    length = secLine.size() - secondDiv;
    map.range = std::stoi(secLine.substr(secondDiv, length));
    return map;    
}

int readFile(std::string path){
    std::ifstream file(path);
    int index = 0;
    if(!file.is_open()){
        std::cerr << "Unable to find file " << path;
    }
    std::string line;
    while(std::getline(file, line)){
        if(line[0] >= 48 && line [0] <= 57){
            
        }
    }
}

int main (int argc, char ** argv){

}