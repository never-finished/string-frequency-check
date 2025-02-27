// Michael Lewis
// 02/23/2025
//

#ifndef BACKUPFILE_H
#define BACKUPFILE_H

#include <map>
#include <string>

// A small class which creates a backup file that also maps the words and includes their frequency
class BackupFile {
public:
    void createBackupFile(const std::map<std::string, int>& wordFreq);
};

#endif // BACKUPFILE_H