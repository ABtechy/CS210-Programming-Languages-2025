// Corner Grocery Tracking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Name: Adrianne Scott-Brown
// Class: CS 210 
// Project: Corner Grocery Tracker (Project Three)
//
//This program is designed to keep a record of the purchase frequency of produce products being sold. The results from the program will
// assist in creating a more effective merchandising strategy. 
//

#include <iostream>
#include <string>
#include "Grocerytrack.h"

int main() {
    GroceryTracker tracker;
    //Load input file
    tracker.LoadDataFromFile("CS210_Project_Three_Input_File.txt");
    //writes data frequency to a backup file
    tracker.WriteBackupFile("frequency.dat");

    int choice;
    std::string item;
    //Displays all menu options
    do {
        std::cout << "\n===Corner Grocer Tracking Menu ===\n";
        std::cout << "1. Search item frequency\n";
        std::cout << "2. Display all item frequencies\n";
        std::cout << "3. Display Produce Histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Please enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            //Prompts user to input item name 
            std::cout << "Please Enter item name: ";
            std::cin >> item;
            std::cout << item << " purchased " << tracker.GetItemFrequency(item) << " times.\n";
            break;
        case 2:
            //All produce and frequency displayed in a list
            tracker.PrintAllFrequencies();
            break;
        case 3:
            //Display Frequency Histogram for Produce
            tracker.PrintHistogram();
            break;
        case 4:
            //Exits the program
            std::cout << "Exiting. Thank you and Goodbye!\n";
            break;
        default:
            //For invalid inputs
            std::cout << "Invalid option. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}