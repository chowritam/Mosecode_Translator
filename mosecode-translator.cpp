#include <iostream>
#include <string>
using namespace std;


string letters[] =
 {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.." 
};

string numbers[] =
 {
    "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."  
};


char morseToChar(string morse) 
{
    for (int i = 0; i < 26; i++) 
    {
        
        if (morse == letters[i]) return 'A' + i;
    }
    for (int i = 0; i < 10; i++)
     {
        if (morse == numbers[i]) return '0' + i;
    }
    return 0;
}


void textToMorse(string text) {
    for (char c : text) 
    {
        if (c >= 'A' && c <= 'Z') {
            cout << letters[c - 'A'] << " ";
        } else if (c >= 'a' && c <= 'z') {
            cout << letters[c - 'a'] << " ";
        } else if (c >= '0' && c <= '9') {
            cout << numbers[c - '0'] << " ";
        } else if (c == ' ') {
            cout << "   "; 
        }
    }
    cout << endl;
}


void morseToText(string morseInput) {
    string temp = "";
    int spaceCount = 0;

    for (size_t i = 0; i < morseInput.size(); i++) {
        char ch = morseInput[i];

        if (ch != ' ') {
            temp += ch;
            spaceCount = 0;
        } else {
            if (!temp.empty()) {
                cout << morseToChar(temp);
                temp = "";
            }
            spaceCount++;

           
            if (spaceCount == 3) {
                cout << " ";
                spaceCount = 0;
            }
        }
    }

    if (!temp.empty()) {
        cout << morseToChar(temp);
    }
    cout << endl;
}


int main() {
    int choice;
    string input;

    do {
        cout << "\n===== Morse Code Translator =====\n";
        cout << "1. Text to Morse\n";
        cout << "2. Morse to Text\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting...\n";
            break;
        }
        cin.ignore(); 

        if (choice == 1) {
            cout << "Enter Text: ";
            getline(cin, input);
            cout << "Morse Code: ";
            textToMorse(input);
        } 
        else if (choice == 2) {
            cout << "Enter Morse Code (space between letters, 3 spaces between words):\n";
            getline(cin, input);
            cout << "Translated Text: ";
            morseToText(input);
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
        } 
        else {
            cout << "Invalid choice, try again!\n";
        }

    } while (choice != 3);

    return 0;
}
