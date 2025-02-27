// Michael Lewis
// 02/23/2025
//

#ifndef MENU_H
#define MENU_H

#include <map>
#include <string>

class Menu {
public:
    // constructor
    Menu(const std::map<std::string, int>& wordFreq);

    // public functions
    void displayMenu();
    void findWordFrequency();
    void printWordFrequencies();
    void printHistogram();

private:
    // pricate variables
    std::map<std::string, int> wordFreq;

    // private functions
    int getValidChoice();
};

#endif // MENU_H
