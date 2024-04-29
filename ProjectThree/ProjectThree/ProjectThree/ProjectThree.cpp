#include <iostream>
#include <limits> // Add this header for clearing the input buffer
#include <fstream>
#include <string>
#include <map>
using namespace std;

// Function to read input file and populate frequency map
void readInputFile(map<string, int>& frequencyMap) {
    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        exit(1);
    }

    string item;
    while (inputFile >> item) {
        frequencyMap[item]++;
    }

    inputFile.close();
}

// Function to print frequency of a specific word
void printFrequency(const map<string, int>& frequencyMap, const string& word) {
    if (frequencyMap.find(word) != frequencyMap.end()) {
        cout << "Frequency of '" << word << "': " << frequencyMap.at(word) << endl;
    }
    else {
        cout << "'" << word << "' not found." << endl;
    }
}

// Function to print frequency of all items
void printAllFrequencies(const map<string, int>& frequencyMap) {
    cout << "Frequencies of all items:" << endl;
    for (const auto& pair : frequencyMap) {
        cout << pair.first << " " << pair.second << endl;
    }
    cout << endl;
}

// Function to print histogram of frequency of all items
void printHistogram(const map<string, int>& frequencyMap) {
    cout << "Histogram of frequencies:" << endl;
    for (const auto& pair : frequencyMap) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to create backup file
void createBackupFile(const map<string, int>& frequencyMap) {
    ofstream outputFile("frequency.dat");
    if (!outputFile) {
        cerr << "Error creating backup file." << endl;
        return;
    }

    for (const auto& pair : frequencyMap) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}

int main() {
    map<string, int> frequencyMap;
    readInputFile(frequencyMap);

    int choice;
    do {
        cout << "Menu:\n1. Frequency of a specific word\n2. Frequency of all items\n3. Histogram of frequencies\n4. Exit\nEnter your choice: ";
        cin >> choice;

        // Clear the input buffer to prevent infinite loop
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            string word;
            cout << "Enter word: ";
            cin >> word;
            printFrequency(frequencyMap, word);
            break;
        }
        case 2:
            printAllFrequencies(frequencyMap);
            break;
        case 3:
            printHistogram(frequencyMap);
            break;
        case 4:
            createBackupFile(frequencyMap);
            cout << "Backup file 'frequency.dat' created." << endl;
            cout << "Exiting program." << endl << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
