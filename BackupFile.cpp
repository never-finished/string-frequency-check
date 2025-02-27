// Michael Lewis
// 02/23/2025
//

#include "BackupFile.h"
#include <fstream>

// Function to creatre the backup file which contains the words and their frequency
void BackupFile::createBackupFile(const std::map<std::string, int>& wordFreq) {
    std::ofstream outFile("frequency.dat");
    for (const auto& item : wordFreq) {
        outFile << item.first << " " << item.second << std::endl;
    }
}