// Michael Lewis
// 02/23/2025
//

#include "Menu.h"
#include <iostream>
#include <limits>

    Menu::Menu(const std::map<std::string, int>& wordFreq) : wordFreq(wordFreq) {}

    // Function to get a valid integer input from the user within a specific range
    int Menu::getValidChoice() {
        int choice;
        // Loops until the user makes a selection of 1-4
        while (true) {
            std::cout << "Enter your choice (1-4): ";
            if (std::cin >> choice && choice >= 1 && choice <= 4) {
                return choice;
            }
            else {
                std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
            }
        }
    }

    // Function to find frequency of a specific word
    void Menu::findWordFrequency() {
        std::string word;
        std::cout << "Enter the word you wish to look for: ";
        std::cin >> word;

        // Output if word is found
        if (wordFreq.find(word) != wordFreq.end()) {
            std::cout << "The word \"" << word << "\" appears " << wordFreq.at(word) << " times." << std::endl;
        }
        // Output if word is not found
        else {
            std::cout << "The word \"" << word << "\" does not appear in the file." << std::endl;
        }
    }

    // Function to print word frequencies
    void Menu::printWordFrequencies() {
        for (const auto& item : wordFreq) {
            std::cout << item.first << " " << item.second << std::endl;
        }
    }

    // Function to print a histogram of word frequencies
    void Menu::printHistogram() {
        for (const auto& item : wordFreq) {
            // Ouputs the item followed by a space
            std::cout << item.first << " ";
            // Ouputs a * for the number of times provided in wordFreq
            std::cout << std::string(item.second, '*') << std::endl;
        }
    }

    // Function to display the menu and handle user choices
    void Menu::displayMenu() {
        int choice;
        // Loops the menu until user exits
        do {
            std::cout << "\nMenu:\n";
            std::cout << "1. Find frequency of a specific word\n";
            std::cout << "2. Print list of word frequencies\n";
            std::cout << "3. Print histogram of word frequencies\n";
            std::cout << "4. Exit\n";

            // Gets a valid choice from the user
            choice = getValidChoice();

            // Chooses appopriate action based on choice
            switch (choice) {
            case 1:
                findWordFrequency();
                break;
            case 2:
                printWordFrequencies();
                break;
            case 3:
                printHistogram();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
                // The default case shouldn't get hit due to error checking if input
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }