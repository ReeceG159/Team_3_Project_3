#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

int main() {

    ifstream fin("Morse_Code.txt");

    if (!fin.is_open()) {
        cout << "Could not open file" << endl;
    }
    else {

        string line;
        while (getline(fin, line)) { //Gets each line from the input file

        }

        string option = "r";
        //the menu is in a while loop until the option selected is q
        //the menu only reads the first character of the input as the option
        while (option.at(0) != 'q') {
            cout << "MENU" << endl;
            cout << "e - Encode a string" << endl;
            cout << "d - Decode morse code" << endl;
            cout << "q - Quit" << endl;
            cout << endl;
            cout << "Choose an option: " << endl;
            cin >> option;

            //Encode a string of lowercase letters with no spaces
            if (option.at(0) == 'e') {
                cout << "Text here: " << endl;
                //do it
            }

            //Decode morse code with spaces as delimiters
            if (option.at(0) == 'd') {
                cout << "Text here: " << endl;
                //do it
            }

        }

    }//end else
}//end main

/** Encodes a string of lowercase letters into morse code.
    @param str: string of lowercase letters
    @return: morse code string of a string of lowercase letters (no spaces)
*/
string& encode(string& str) {
    return str;
}

/** Decodes morse code into a string of lowercase letters.
    @param str: string of morse code delimited with spaces
    @return: string of lowercase letters
*/
string& decode(string& str) {
    return str;
}