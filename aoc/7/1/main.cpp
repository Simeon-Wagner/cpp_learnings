#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

struct CardBid{
    std::string hand;
    int bid;
};
std::unordered_map<char, int> order{
{'2', 2},
{'3', 3},
{'4', 4},
{'5', 5},
{'6', 6},
{'7', 7},
{'8', 8},
{'9', 9},
{'T', 10},
{'J', 11},    
{'Q', 12},
{'K', 13},
{'A', 14},
};
CardBid returnCard(std::string line){
    CardBid card;
    int index = line.find(" ");
    card.hand = line.substr(0, index);
    card.bid = stoi(line.substr(index, (line.size() - index)));
    std::cout << "Hand: " << card.hand << " - Bid: " << card.bid << std::endl;
    return card;
}
std::vector <CardBid> readFile(std::string path){
    std::vector <CardBid> cards;
    std::ifstream file(path);
    if(!file.is_open()){
        std::cerr << "Unable to open file " << path << std::endl;
    }
    std::string line;
    while(std::getline(file, line)){
        cards.push_back(returnCard(line));
    }
    return cards;
}


int main (int argc, char ** argv){
    std::string path = "C:\\dev\\aoc\\7\\data\\input.txt";
    std::vector<CardBid> cards = readFile(path);    
}