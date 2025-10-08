#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string.h>
using namespace std;

int main() {
    char words[50][20];   // can hold 50 words max, each up to 20 letters
    int count = 0;

    ifstream file("words.txt");
    if (!file) {
        cout << "Error: Cannot open words.txt file.\n";
        return 0;
    }

    // Read words from file
    while (file >> words[count] && count < 50)
        count++;
    file.close();

    srand(time(0));
    int index = rand() % count; // choose random word
    char secret[20];
    strcpy(secret, words[index]);

    int len = strlen(secret);
    char guess[20];
    for (int i = 0; i < len; i++)
        guess[i] = '_';
    guess[len] = '\0';

    int mistakes = 0;
    int maxMistakes = 7;
    bool found = false;

    cout << "=== Hangman Game ===\n";
    cout << "You have " << maxMistakes << " chances.\n";

    while (mistakes < maxMistakes) {
        cout << "\nWord: " << guess;
        cout << "\nEnter a letter: ";
        char ch;
        cin >> ch;

        found = false;
        for (int i = 0; i < len; i++) {
            if (secret[i] == ch) {
                guess[i] = ch;
                found = true;
            }
        }

        if (!found) {
            mistakes++;
            cout << "Wrong! Remaining chances: " << (maxMistakes - mistakes) << endl;
        }

        if (strcmp(secret, guess) == 0) {
            cout << "\nYou guessed the word: " << secret << endl;
            cout << "🎉 You win!\n";
            return 0;
        }
    }

    cout << "\n💀 You lost! The word was: " << secret << endl;
    return 0;
}
