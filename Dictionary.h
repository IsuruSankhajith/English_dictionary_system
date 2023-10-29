#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>
#include "Word.h"

class Dictionary {
public:
    bool existing_word(const std::vector<Word>& dictionary, const std::string& name);
    void openTheDictionary(const std::vector<Word>& dictionary);
    void lookupWord(const std::vector<Word>& dictionary);
    void showWord(const Word& word);
    void addNewWord(std::vector<Word>& dictionary);
    void storeDictionary(const std::vector<Word>& dictionary, const std::string& filename);
    //std::istream& operator>>(std::istream& in, Word& w);
    //void openDictionary(std::vector<Word>& dictionary);
    //void showAllWords(const std::vector<Word>& dictionary);
    //std::string searchWord(const std::vector<Word>& dictionary, const std::string& word);

private:
    std::vector<Word> words;
};

#endif  // DICTIONARY_H