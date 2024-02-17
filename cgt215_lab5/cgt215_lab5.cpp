// cgt215_lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string translate(string text, vector<char> cypher) {

    vector<char> translated;
    string out;

    for (char& c : text) { //Loops through each character in text string.
        int charNum = int(c);
        if (65 <= charNum && charNum <= 90) { //If character is capital letter
            translated.push_back(cypher[charNum - 65]);
        } else if (97 <= charNum && charNum <= 122) { //If character is lowercase letter
            char temp = cypher[(charNum - 97)];
            int cap = int(temp) + 32;
            translated.push_back(char(cap));
        } else { //If character is not a letter
            translated.push_back(c);
        }
    }

    for (char& t : translated) { //Loops through translated vector and condenses characters into single cyphered string for return
        char addChar = t;
        string addString;
        addString = addChar;
        out += addString;
    }

    return out;

}

int main() {
    string text;
    vector<char> vect{'V','F','X','B','L','I','T','Z','J','R','P','H','D','K','N','O','W','S','G','U','Y','Q','M','A','C','E'};

    cout << "Input text to cypher: ";
    getline(cin, text);

    string out = translate(text, vect);
    cout << "Encoded message: \"" << out << "\"" << endl;
}