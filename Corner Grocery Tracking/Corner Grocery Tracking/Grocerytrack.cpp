#include "Grocerytrack.h"
#include <fstream>
#include <iostream>
#include <Windows.h>

//Loads all items from text file
void GroceryTracker::LoadDataFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::string item;
    //Reads each item and process frequency
    while (inputFile >> item) {
        itemFrequency[item]++;
    }
    inputFile.close(); //closes file after reading
}
//frequency of specific item is returned
int GroceryTracker::GetItemFrequency(const std::string& item) {
    return itemFrequency[item];
}
//all items and numeric frequency is returned
void GroceryTracker::PrintAllFrequencies() const {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}
//Histogram display of item frequencies
void GroceryTracker::PrintHistogram() const {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";//prints an asterisk per each item occurence 
        }
        std::cout << std::endl;
    }
}
//Backup file
void GroceryTracker::WriteBackupFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << std::endl;
    }
    outFile.close();
}