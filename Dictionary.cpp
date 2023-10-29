#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Dictionary.h"


bool Dictionary::existing_word(const std::vector<Word>& dictionary, const std::string& name) {
    for (const auto& word : dictionary) {
        if (word.getName() == name) {
            return true;
        }
    }
    return false;
}

bool openTheDictionary(std::vector<Word>& dictionary) {
    std::string directoryName;
    std::cout << "Type 'default' to open the default file, or the name of the dictionary file: ";
    std::cin >> directoryName;

    if (directoryName == "default") {
        directoryName = "dictionary_2023S1.txt";
    }

    std::ifstream file(directoryName);
    if (!file.is_open()) {
        std::cout << "Dictionary file cannot be opened!" << std::endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        if (line == "<word>") {
            std::string name, type, definition;
            getline(file, name); // read the next line after <word>
            getline(file, definition); // read the definition
            getline(file, type); // read the type

            if (name.length() > 0) {
                Word word(name, type, definition); // Specify std::string parameters explicitly
                dictionary.push_back(word);
            }
        }
    }

    file.close();

    std::cout << "Dictionary loaded successfully!" << std::endl;
    return true;
}


void showWord(const Word& word) {
    std::cout << "Name: " << word.getName() << std::endl;
    std::cout << "Type: " << word.getType() << std::endl;
    std::cout << "Definition: " << word.getDefinition() << std::endl;
}

void lookupWord(const std::vector<Word>& dictionary) {
    if (dictionary.empty()) {
        std::cout << "Nothing is in the dictionary." << std::endl;
        return;
    }

    std::string searchWord;
    std::cout << "*************** Hi users! *************** " << std::endl;
    std::cout << "Enter a search word: ";
    std::cin >> searchWord;

    bool detected = false;
    for (const auto& word : dictionary) {
        std::string lowercaseWord = word.getName();
        transform(lowercaseWord.begin(), lowercaseWord.end(), lowercaseWord.begin(), ::tolower);
        std::string lowercaseSearchWord = searchWord;
        transform(lowercaseSearchWord.begin(), lowercaseSearchWord.end(), lowercaseSearchWord.begin(), ::tolower);
        if (lowercaseWord == lowercaseSearchWord) {
            showWord(word);
            detected = true;
            break;
        }
    }

    if (!detected) {
        std::cout << "Word not found." << std::endl;
    }
}

void Dictionary::addNewWord(std::vector<Word>& dictionary) {
    Word w;
    std::string name;
    std::cout << "Type the word name here: ";
    std::cin >> name;
    if (existing_word(dictionary, name)) {
        std::cout << "Error: word already exists. Editing existing words requires advanced privileges.\n";
        return;
    }
    w.setName(name);
    std::cout << "Enter word type: ";
    std::string type;
    std::cin >> type;
    w.setType(type);
    std::cout << "Type word definition here: ";
    std::cin.ignore(); // disregard any remaining newline characters in the input stream.
    std::string definition;
    getline(std::cin, definition);
    w.setDefinition(definition);
    dictionary.push_back(w);
    std::cout << "Word added to the dictionary:\n";
    w.printDefinition();
}

void Dictionary::storeDictionary(const std::vector<Word>& dictionary, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) { // check to see if the failbit flag is set.
        std::cout << "Error: unable to open the file " << filename << " to write.\n";
        return;
    }
    for (const auto& w : dictionary) {
        file << w.getName() << "," << w.getType() << "," << w.getDefinition() << "\n";
    }
    std::cout << "Dictionary stored in file " << filename << ".\n";
}

std::istream& operator>>(std::istream& in, Word& w) {
    std::string name, type, definition;
    std::cout << "Enter word name: ";
    in >> name;
    w.setName(name);
    std::cout << "Enter word type: ";
    in >> type;
    w.setType(type);
    std::cout << "Enter word definition: ";
    in.ignore(); // ignore any remaining newline characters in the input stream
    std::getline(in, definition);
    w.setDefinition(definition);
    return in;
}