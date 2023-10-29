#ifndef EXTENDEDDICTIONARY_H
#define EXTENDEDDICTIONARY_H

#include "Dictionary.h"

class ExtendedDictionary : public Dictionary {
public:
    bool isPalindrome(const std::string& str);
    void findPalindromes();
    void findRhymingWords();
    void guessTheFourthWord();
    //void cheatSearchdle(const std::string& mysteryWord, const std::string& excludedLetters, const std::string& requiredLetters, const std::string& positionLetters);

};

#endif  // EXTENDEDDICTIONARY_H