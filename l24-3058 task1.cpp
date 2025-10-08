#include <iostream>
#include <string.h> // for strlen
#include <conio.h>  // for _getch (Esc key)
using namespace std;

int main() {
    char str[100];
    cout << "=== Palindrome Checker ===\n";
    cout << "Press ESC anytime to exit.\n";

    while (true) {
        cout << "\nEnter a word: ";
        cin >> str;

        // Check for ESC key
        if (_kbhit()) {
            char key = _getch();
            if (key == 27) {
                cout << "\nExiting...\n";
                break;
            }
        }

        int len = strlen(str);
        bool isPal = true;

        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - i - 1]) {
                isPal = false;
                break;
            }
        }

        if (isPal)
            cout << "Palindrome\n";
        else
            cout << "Not Palindrome\n";
    }

    return 0;
}
