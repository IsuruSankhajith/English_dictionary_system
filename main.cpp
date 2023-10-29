#include <iostream>
#include <vector>
#include "Dictionary.h"
#include "ExtendedDictionary.h"

using namespace std;

void displayMenu() {
    cout << "---------------------------" << endl;
    cout << "Dictionary Menu" << endl;
    cout << "---------------------------" << endl;
    cout << "Task 1. Lookup a word" << endl;
    cout << "Task 2. Add a new word" << endl;
    cout << "Task 3. Store dictionary to file" << endl;
    cout << "Task 4. Find palindromes" << endl;
    cout << "Task 5. Find rhyming words" << endl;
    cout << "Task 6. Exit" << endl;
    cout << "Enter your choice (1-6): ";
}

int getUserChoice() {
    int choice;
    cin >> choice;
    return choice;
}

void performTask(int choice, vector<Word>& dictionary, Dictionary dict2, ExtendedDictionary extendedDict) {
    switch (choice) {
        case 1:
            dict2.lookupWord(dictionary);
            break;
        case 2:
            dict2.addNewWord(dictionary);
            break;
        case 3: {
            string filename;
            cout << "Enter the filename to store the dictionary: ";
            cin >> filename;
            dict2.storeDictionary(dictionary, filename);
            break;
        }
        case 4:
            cout << "Task 04. Palindromes" << endl;
            extendedDict.findPalindromes();
            break;
        case 5:
            cout << "Task 05. Rhyming words" << endl;
            extendedDict.findRhymingWords();
            break;
        case 6:
            cout << "Task 06. Guess the fourth word" << endl;
            extendedDict.guessTheFourthWord();
            break;
        case 7:
            cout << "Task 07. Rhyming words" << endl;
            //extendedDict.findRhymingWords();
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

int main() {
    Dictionary dict2;
    ExtendedDictionary extendedDict;
    vector<Word> dictionary;
    dict2.openTheDictionary(dictionary);

    int choice;
    do {
        displayMenu();
        choice = getUserChoice();
        performTask(choice, dictionary, dict2, extendedDict);
    } while (choice != 6);

    return 0;
}
