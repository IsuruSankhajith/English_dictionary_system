#include "ExtendedDictionary.h"
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <fstream> 

bool isPalindrome(const std::string& str) {
    int len = str.size();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

void findPalindromes() {
    std::ifstream inputFile("dictionary_2023S1.txt");
    if (!inputFile.is_open()) {
        std::cout << "Unable to open the file.\n";
        return;
    }

    std::vector<std::string> palindromes;
    std::string word;
    while (inputFile >> word) {
        if (isPalindrome(word)) {
            palindromes.push_back(word);
        }
    }

    std::cout << "Palindromes:\n";
    for (const auto& palindrome : palindromes) {
        std::cout << palindrome << "\n";
    }
}

void findRhymingWords() {
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

//Intermediate Question
void ExtendedDictionary::guessTheFourthWord() {
    // // Print welcome message
    // std::cout << "Welcome to Guess the Fourth Word!" << std::endl;

    // // Print current high score
    // int highScore = getHighScore();
    // std::cout << "Current High Score: " << highScore << std::endl;

    // // Choose a random word with more than 4 words in its definition
    // std::vector<Word> validWords;
    // for (const Word& word : words) {
    //     if (word.getDefinition().size() > 4) {
    //         validWords.push_back(word);
    //     }
    // }

    // // Check if there are valid words
    // if (validWords.empty()) {
    //     std::cout << "No words found with more than 4 words in their definitions." << std::endl;
    //     return;
    // }

    // // Seed the random number generator
    // std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // // Choose a random word index
    // int randomIndex = std::rand() % validWords.size();
    // const Word& selectedWord = validWords[randomIndex];

    // // Print the word and definition with the fourth word replaced by underscores
    // std::cout << "Word: " << selectedWord.getName() << std::endl;
    // std::string definition = selectedWord.getDefinition();
    // replaceFourthWordWithUnderscores(definition);
    // std::cout << "Definition: " << definition << std::endl;

    // // Player's guess
    // std::string guess;
    // std::cout << "Guess the missing word: ";
    // std::cin >> guess;

    // // Check if the guess is correct
    // std::string fourthWord = getFourthWord(selectedWord.getDefinition());
    // if (guess == fourthWord) {
    //     std::cout << "Congratulations! You guessed it correctly." << std::endl;

    //     // Update the score
    //     int score = getScore();
    //     score += 10;
    //     updateScore(score);

    //     // Check if the player beat the high score
    //     if (score > highScore) {
    //         setHighScore(score);
    //         std::cout << "New High Score! You beat the previous record." << std::endl;
    //     }

    //     // Continue the game by presenting another word
    //     guessTheFourthWord();
    // } else {
    //     std::cout << "Incorrect guess! The correct word is: " << fourthWord << std::endl;

    //     // Print the player's score
    //     std::cout << "Your Score: " << getScore() << std::endl;
    // }
}



