/*
////////
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <random>

const std::string SCORE_FILE = "score.txt";
const int POINTS_PER_GUESS = 10;

std::pair<std::string, std::string> getRandomWord(const std::vector<std::pair<std::string, std::string>>& dictionary)
{
    std::srand(std::time(0)); // Seed random number generator
    while (true) {
        int index = std::rand() % dictionary.size();
        std::string definition = dictionary[index].second;
        std::size_t pos = definition.find_first_of(" \t\n\r\f\v");
        pos = definition.find_first_of(" \t\n\r\f\v", pos + 1);
        pos = definition.find_first_of(" \t\n\r\f\v", pos + 1);
        pos = definition.find_first_of(" \t\n\r\f\v", pos + 1);
        if (pos != std::string::npos) {
            std::string word = dictionary[index].first;
            return std::make_pair(word, definition);
        }
    }
}

std::string replaceFourthWord(const std::string& str)
{
    std::string result = str;
    int count = 0;
    for (std::size_t i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            count++;
            if (count == 3) {
                std::size_t start = i + 1;
                std::size_t end = str.find_first_of(" \t\n\r\f\v", start);
                for (std::size_t j = start; j < end; j++) {
                    result[j] = '_';
                }
                break;
            }
        }
    }
    return result;
}

// Checks if the guess is correct
bool isGuessCorrect(const std::string& guess, const std::string& answer)
{
    return guess == answer;
}

// Loads the current high score from the score file
int loadHighScore()
{
    std::ifstream scoreFile(SCORE_FILE);
    if (scoreFile.is_open()) {
        int highScore;
        scoreFile >> highScore;
        scoreFile.close();
        return highScore;
    } else {
        return 0;
    }
}

void saveHighScore(int highScore)
{
    std::ofstream scoreFile(SCORE_FILE);
    scoreFile << highScore;
    scoreFile.close();
}

int main() {
    // Load the dictionary
    std::ifstream inputFile("dictionary_2023S1.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open dictionary file.\n";
        return 1;
    }

    std::vector<std::pair<std::string, std::string>> dictionary;
    std::string word, definition;
    while (inputFile >> word && std::getline(inputFile, definition)) {
        // Only add words with definitions longer than four words
        if (std::count_if(definition.begin(), definition.end(), [](char c) { return std::isspace(c); }) >= 4) {
            dictionary.emplace_back(word, definition);
        }
    }
    inputFile.close();

    // Load the current high score
    int highScore = loadHighScore();

    // Welcome the player and print the current high score
    std::cout << "Welcome to Guess the Fourth Word!\n";
    std::cout << "Current High Score: " << highScore << "\n";

    // Set up the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, dictionary.size() - 1);

    // Play the game
    int score = 0;
    bool playAgain = true;
    while (playAgain) {
        // Choose a random word from the dictionary
        auto [word, definition] = getRandomWord(dictionary);

        // Replace the fourth word with underscores
        std::string maskedDefinition = replaceFourthWord(definition);

        // Prompt the player to guess the missing word
        std::cout << "\n" << word << ": " << maskedDefinition << "\n\n";
        std::string guess;
        std::cout << "Guess the missing word: ";
        std::cin >> guess;

        // Check the guess and update the score
        if (isGuessCorrect(guess, replaceFourthWord(definition))) {
            std::cout << "Congratulations!\n";
            score += POINTS_PER_GUESS;
        } else {
            std::cout << "Incorrect. The missing word was \"" << replaceFourthWord(definition) << "\".\n";
            std::cout << "Your final score is " << score << ".\n";
            playAgain = false;

            // Update the high score if necessary
            if (score > highScore) {
                highScore = score;
                std::cout << "Congratulations, you have beaten the high score!\n";
                saveHighScore(highScore);
            }
        }
    }

    return 0;
}

*/