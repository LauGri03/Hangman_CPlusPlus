#include <iostream>
#include <vector>
#include <utility>

namespace hangame {
    class hangman
    {
    private:
       std::vector<std::pair<char, bool> > tab;
       int difficulte;
       bool win();
       void printWord();
       void endGame();
       int attempt(char c);
       void loop();
       std::vector<char> getCurrent();
    public:
        hangman(std::string Word, int Difficulte);
        ~hangman();   
    };
    
   
};