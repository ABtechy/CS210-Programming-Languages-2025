#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

class GroceryTracker {
private:
    //Stores item and matching purchase frequency
    std::map<std::string, int> itemFrequency;

public:
    //load data from input file 
    void LoadDataFromFile(const std::string& filename);
    //returns purchase frequency
    int GetItemFrequency(const std::string& item);
    //prints all items with frequency 
    void PrintAllFrequencies() const;
    //Histogram of item frequency 
    void PrintHistogram() const;
    //back up file is written
    void WriteBackupFile(const std::string& filename) const;
};

#endif