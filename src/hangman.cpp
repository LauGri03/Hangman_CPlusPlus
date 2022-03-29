#include "hangman.h"
#include <vector>
#include <utility>

hangame::hangman::hangman(std::string Word, int Difficulte){
    this->difficulte = Difficulte;
    for(char c : Word){
        tab.push_back(std::make_pair(c, false));
    }
    loop();
}

hangame::hangman::~hangman(){}

bool hangame::hangman::win(){
    bool key = false;
    auto it = std::find_if(tab.begin(),tab.end(),
        [&key](const std::pair<char, bool>& entry){ 
            return entry.second == key;
        } );
        return it != tab.end() ? false : true;
}

void hangame::hangman::endGame(){
    for(int i = 0; i<=tab.size() -1; i++){       
            tab.at(i).second = true;     
    }
}

int hangame::hangman::attempt(char c){
    int error = 1;
    for(int i = 0; i<=tab.size() -1; i++){
        if(tab.at(i).first == c){
            tab.at(i).second = true;
            error--;
        }
    }
    return error == 1 ? 1 : 0;
}

std::vector<char> hangame::hangman::getCurrent(){
    std::vector<char> result;
    for(auto it : tab){
        if(it.second == true){
            result.push_back(it.first);
        }
        else{
            result.push_back('_');
        }
    }
    return result;
}

void hangame::hangman::printWord(){
     for(char c : getCurrent()){
            std::cout << c << " ";
        }
    std::cout << "" << std::endl;
}

void hangame::hangman::loop(){
    int errors = 0;
    bool won = false;
    char letter;

    std::cout << "The word has " << tab.size() << " letters" << std::endl;
    std::cout << "You have " << difficulte << " attempts to win" << std::endl;
    printWord();
    while((won == false) && (errors != difficulte)){
        std::cout << "Attempt a letter" << std::endl;
        std::cin >> letter;
        errors += attempt(letter);
        won = win();
        std::cout << "Your current advancement is :" << std::endl;
        printWord();
        std::cout << "You commited : " << errors << " errors" << std::endl;
    }
    if(won == true){
        std::cout << "You Win !" << std::endl;
    }
    else{
        std::cout << "Sorry you lose !" << std::endl;
    }
    endGame();
    std::cout << "The word was :" << std::endl;
    printWord();
}
