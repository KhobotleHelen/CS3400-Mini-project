#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;


// This function saves all laboratories into laboratories.txt.
bool FileManager::saveToFile(LinkedList& list, string filename)
{
  ofstream file(filename.c_str());


if (!file.is_open())
{
   cout << "DEBUG ERROR: Could not open file." << endl;
        cout << "Attempted path: " << filename << endl;
        cout << "Please check if you have permission to write to this folder." << endl;
        return false;
}

    
    // This variable will store the number of laboratories.
    int count;

    // Create a temporary dynamic array containing all laboratories.
    // The toArray function will put the number of laboratories into count.
    Laboratory*labs = list.toArray(count);



    // Go through every laboratory.
    for (int i = 0; i < count; i++)
    {
        // Write all seven laboratory fields into the file.
        // The | symbol separates the different fields.
        file << labs[i].getId() << "|"
             << labs[i].getName() << "|"
             << labs[i].getType() << "|"
             << labs[i].getBuilding() << "|"
             << labs[i].getCapacity() << "|"
             << labs[i].getStatus() << "|"
             << labs[i].getCondition()
             << endl;
    }

    // Delete the temporary array because we created it with new.
    delete[] labs;

    // Close the file.
    file.close();

    // Tell the program that saving was successful.
    return true;
}


// This function loads laboratories from laboratories.txt.
bool FileManager::loadFromFile(LinkedList& list, string filename)
{
  ifstream file(filename.c_str());


if (!file.is_open())
{
    cout << "DEBUG ERROR: Could not open file." << endl;
        cout << "Attempted path: " << filename << endl;
        cout << "Please check if you have permission to write to this folder." << endl;
        return false;
}


    // Remove the laboratories currently in memory.
    list.clear();

    // This variable will store one complete line from the file.
    string line;

    // Read the file one line at a time.
    while (getline(file, line))
    {
        // Variables for the seven laboratory fields.
        string id;
        string name;
        string type;
        string building;
        string capacityText;
        string status;
        string condition;

        // Find the positions of the | separators.
        size_t p1 = line.find("|");
        size_t p2 = line.find("|", p1 + 1);
        size_t p3 = line.find("|", p2 + 1);
        size_t p4 = line.find("|", p3 + 1);
        size_t p5 = line.find("|", p4 + 1);
        size_t p6 = line.find("|", p5 + 1);

        // If the line does not contain all separators,
        // ignore that line.
        if (p1 == string::npos ||
            p2 == string::npos ||
            p3 == string::npos ||
            p4 == string::npos ||
            p5 == string::npos ||
            p6 == string::npos)
        {
            continue;
        }

        // Extract each field from the line.
        id = line.substr(0, p1);

        name = line.substr(p1 + 1, p2 - p1 - 1);

        type = line.substr(p2 + 1, p3 - p2 - 1);

        building = line.substr(p3 + 1, p4 - p3 - 1);

        capacityText = line.substr(p4 + 1, p5 - p4 - 1);

        status = line.substr(p5 + 1, p6 - p5 - 1);

        condition = line.substr(p6 + 1);

        // Convert the capacity from text into an integer.
        int capacity = atoi(capacityText.c_str());

        // Create a Laboratory object.
        Laboratory lab(
            id,
            name,
            type,
            building,
            capacity,
            status,
            condition
        );

        // Add the laboratory to the linked list.
        list.addEnd(lab);
    }

    // Close the file.
    file.close();

    // Tell the program that loading was successful.
    return true;
}
