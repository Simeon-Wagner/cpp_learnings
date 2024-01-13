#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
struct Card {
    std::vector<int> winNr;
    std::vector<int> cardNr;
};

std::vector<std::string> readFile(std::string path){
    std::vector<std::string> data;
    std::ifstream file(path);
    if(!file.is_open()){
        std::cerr << "Unable to find file " << path;
    }

    std::string line;
    while(std::getline(file, line)){
        data.push_back(line);
    }

    return data;
}
std::vector<int> readNumbers(std::string input){
    std::vector<int> numbers;
    int index = 0;

    while (index < input.size()){
        std::string nr;
        bool flag = false;
        while(48 <= input[index] && input[index] <= 57){
            flag = true;
            nr += input[index];
            index ++;
        }
        if(flag){
            numbers.push_back(std::stoi(nr));
        }
        index ++;
        
    }
    return numbers;
}

std::vector<Card> readCards(std::vector<std::string> input){
    std::vector<Card>  cards;
    for(std::string line : input){
        int iPipe = line.find("|");
        int iColon =  line.find(":");
        int lengthWinNr = iPipe - iColon;
        int lengthCardNr =  line.size()-1 - iPipe;
        std::string strWinNr = line.substr(iColon, lengthWinNr);
        std::string strCardNr = line.substr(iPipe +1, lengthCardNr);

        std::vector<int> winNr = readNumbers(strWinNr);
        std::vector<int> cardNr = readNumbers(strCardNr);
        cards.push_back(Card{winNr, cardNr});
    }
    return cards;
}

std::vector<int> returnPoints(std::vector<Card> cards){
    std::vector<int> points;
    for(Card c: cards){
        int winNr = 0;
        for(int cnr : c.cardNr){
            for(int wnr : c.winNr){
                if(cnr == wnr){
                    winNr ++;
                }
            }
        }
        if(winNr > 0){
            points.push_back(std::pow(2, winNr-1));
        }
    }
    return points;
}

int sum (std::vector<int> points) {
    int sum = 0;
    for(int n : points){
        sum += n;
    }
    return sum;
}

int main(int argc, char ** argv){
    std::string path = "C:\\dev\\aoc\\4\\input.txt";
    std::vector<std::string> input = readFile(path);
    std::vector<Card> cards = readCards(input);
    std::vector<int> points = returnPoints(cards);
    int sumPoints = sum(points);

    std::cout << "Amount of points are: " << sumPoints << std::endl;



}