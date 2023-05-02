#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

struct Tree_Node {
    int val;
    Tree_Node* left, * right;
    Tree_Node(int val, Tree_Node* left = NULL, Tree_Node* right = NULL) :
        val(val), left(left), right(right) {}
};

/** Takes one letter of morse code and inserts the ascii value of the letter it represents into a binary tree.
    @param line: string of morse code
    @param pos: represents how far through line the recursion has gotten
    @param root: the head of the morse code binary tree
*/
Tree_Node* treeBuilder(string line, int pos, Tree_Node* root) {
    pos++;
    bool finished = false;
    //if root is now at the position to insert the new letter, do it
    if (pos == line.length()) {
        finished = true;
        if (!root) {
            Tree_Node* newNode = new Tree_Node(line.at(0));
            root = newNode;
        }
        else {
            root->val = line.at(0);
        }

    }
    //if we are not finished, recursively travel left for '.' and right for '-'
    if (finished == false) {
        if (line.at(pos) == '.') {
            if (!root) {
                //if we must travel through nodes that are not yet generated, generate them with val '0'
                //if any '0's remain after the function's completion, then the tree must not be filled out completely
                Tree_Node* newNode = new Tree_Node('0');
                root = newNode;
                root->left = treeBuilder(line, pos, root->left);
            }
            else {
                root->left = treeBuilder(line, pos, root->left);
            }
        }

        if (line.at(pos) == '-') {
            if (!root) {
                Tree_Node* newNode = new Tree_Node('0');
                root = newNode;
                root->right = treeBuilder(line, pos, root->right);
            }
            else {
                root->right = treeBuilder(line, pos, root->right);
            }
        }
    }
    return root;
}//end treeBuilder

void treeBuilder(string line, Tree_Node* head) {
    treeBuilder(line, 0, head);
}//end treeBuilder



int main() {

    ifstream fin("Morse_Code.txt");

    if (!fin.is_open()) {
        cout << "Could not open file" << endl;
    }
    else {
        Tree_Node* head = new Tree_Node(' ');
        string line;
        while (getline(fin, line)) { //Gets each line from the input file
            cout << line << endl;
            treeBuilder(line, head);
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
    string temp;
    string returnstr = "";
    int i = 0;
    ifstream fin ("Morse_Code.txt");
    if (!fin.is_open()){
        cout<< "Could not open file"<<endl;
    }
    else{
        while(str[i]){
            getline(fin, temp);
            if (str[i] == temp[0]){
                temp[0] = ' ';
                returnstr.append(temp);
                i++;
                fin.clear();
                fin.seekg(0);
            }
        }
        return returnstr;
    }
}

/** Decodes morse code into a string of lowercase letters.
    @param str: string of morse code delimited with spaces
    @return: string of lowercase letters
*/
string& decode(string& str) {
    return str;
}
