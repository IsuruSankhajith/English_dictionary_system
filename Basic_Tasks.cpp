/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool to_be_Palindrome(const std::string& str)
{
    int len = str.size();
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-1-i]) {
            return false;
        }
    }
    return true;
}

void findPalindromes()
{
    std::ifstream inputFile("dictionary_2023S1.txt");
    if (!inputFile.is_open()) {
        std::cout << "Unable to open the file.\n";
        return;
    }

    std::vector<std::string> palindromes;
    std::string word;
    while (inputFile >> word) {
        if (to_be_Palindrome(word)) {
            palindromes.push_back(word);
        }
    }

    std::cout << "Palindromes:\n";
    for (const auto& palindrome : palindromes) {
        std::cout << palindrome << "\n";
    }
}

void findRhymingWords()
{
    std::ifstream inputFile("dictionary_2023S1.txt");
    if (!inputFile.is_open()) {
        std::cout << "Failed to open file.\n";
        return;
    }

    std::vector<std::string> rhymingWords;
    std::string inputWord;
    std::cout << "Enter a word: ";
    std::cin >> inputWord;

    if (inputWord.size() < 3) {
        std::cout << "Please type a word with at least 3 letters in it.\n";
        return;
    }

    std::string endSequence = inputWord.substr(inputWord.size() - 3, 3);
    std::string word;
    while (inputFile >> word) {
        if (word.size() >= 3 && word.substr(word.size() - 3, 3) == endSequence) {
            rhymingWords.push_back(word);
        }
    }

    std::cout << "Rhyming words:\n";
    for (const auto& rhymingWord : rhymingWords) {
        std::cout << rhymingWord << "\n";
    }
}

int main()
{
    int choice;
    while (true) {
        std::cout << "Menu:\n";
        std::cout << "Task 05. Palindromes\n";
        std::cout << "Task 06. Rhyming words\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                findPalindromes();
                break;
            case 2:
                findRhymingWords();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << "\n";
    }
}
*/

