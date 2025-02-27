// CornerGrocerML.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Michael Lewis
// 02/23/2025
//


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "BackupFile.h"
#include "Menu.h"

// Function to count word frequencies from the input file
std::map<std::string, int> countWordFrequencies(const std::string& filename) {
    std::map<std::string, int> wordFreq;
    std::ifstream inFile(filename);
    std::string word;

    while (inFile >> word) {
        wordFreq[word]++;
    }

    return wordFreq;
}

// Main function
int main() {
    std::map<std::string, int> wordFreq = countWordFrequencies("CS210_Project_Three_Input_File.txt");

    // Using the BackupFile class to create a backup file
    BackupFile backup;
    backup.createBackupFile(wordFreq);

    // Using the Menu class to display the menu and handle user choices
    Menu menu(wordFreq);
    menu.displayMenu();

    return 0;
}

