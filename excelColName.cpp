#include <iostream>
#include <string>
#include <fstream> 
using namespace std;

string excelColumnName(unsigned int col) {
    string result = "";

    while (col > 0) {
        col--; 
        int remainder = col % 26;         // The remainder is calculated to determine the current letter
        char letter = 'A' + remainder;    // The corresponding character is determined using ASCII value of 'A'
        result = letter + result;         // The character is prepended to the result string
        col = col / 26;                   // The column number is reduced to move to the next position
    }
    return result;
}

int main() {
    unsigned int input;
    cout << "Enter column number: ";
    cin >> input;

    string output = excelColumnName(input);
    cout << "Excel Column Name: " << output << endl; 

    ofstream file("output.txt"); 
    if (file.is_open()) {
        file << "Excel Column Name: " << output << endl;
        file.close();  
        cout << "Output saved to output.txt" << endl;
    } else {
        cout << "Failed to open output.txt for writing." << endl;
    }
    return 0;
}