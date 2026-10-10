// It provides the user with a menu to manage laboratories,
// search laboratories, sort laboratories, and save/load data.
#include <iostream>
#include <string>
#include "Laboratory.h"
// Provides the Laboratory class.
#include "LinkedList.h"
// Provides our custom dynamic Linked List.
#include "Searching.h"
// Provides linear and binary searching.
#include "Sorting.h"
// Provides Bubble Sort and Merge Sort.
#include "FileManager.h"
// Provides saving and loading from text files.
using namespace std;

// This function asks the user to enter all seven laboratory attributes and then creates a Laboratory object.
Laboratory enterLaboratory()
{
    string id;
    // Stores the laboratory ID.

    string name;
    // Stores the laboratory name.

    string type;
    // Stores the laboratory type.

    string building;
    // Stores the building.

    int capacity;
    // Stores the capacity.

    string status;
    // Stores the status.

    string condition;
    // Stores the condition.

    cout << "\nEnter Laboratory ID: ";
    // Ask the user for the ID.
    getline(cin, id);
    // Read the entire ID (allows spaces like "lab ict").
    

    cout << "Enter Laboratory Name: ";
    // Ask for the name.

    getline(cin, name);
    // Read the complete name.
    
	cout << "Enter Building: ";
    // Ask for the building.
    

    getline(cin, building);
    // Read the complete building name.
    
    cout << "Enter Laboratory Type: ";
    // Ask for the type.

    getline(cin, type);
    // Read the complete type.


    cout << "Enter Capacity: ";
    // Ask for the capacity.

    cin >> capacity;
    // Read the capacity.

    cin.ignore();
    // Remove the leftover newline.

    cout << "Enter Status: ";
    // Ask for the availability status.

    getline(cin, status);
    // Read the status.

    cout << "Enter Condition: ";
    // Ask for the condition.

    getline(cin, condition);
    // Read the condition.

    Laboratory lab(
        id,
        name,
        type,
        building,
        capacity,
        status,
        condition
    );
    // Create the Laboratory object.

    return lab;
    // Give the completed Laboratory back to main().
}
void displayLaboratory(Laboratory lab)
{
    cout << "\nID: " << lab.getId() << endl;
    // Display the ID.

    cout << "Name: " << lab.getName() << endl;
    // Display the name.

    cout << "Type: " << lab.getType() << endl;
    // Display the type.

    cout << "Building: " << lab.getBuilding() << endl;
    // Display the building.

    cout << "Capacity: " << lab.getCapacity() << endl;
    // Display the capacity.

    cout << "Status: " << lab.getStatus() << endl;
    // Display the status.

    cout << "Condition: " << lab.getCondition() << endl;
    // Display the condition.
}

int main()
{
    LinkedList list;
    // Create the Linked List that will store laboratories.

    FileManager fm;
    // Create a FileManager object to handle saving and loading.
	string filename = "C:\\DSASave\\laboratories.txt";
    // This is where our laboratory information will be saved.
    fm.loadFromFile(list, filename);
    // Try to load previously saved laboratories when the program starts.

    int choice;
    // Stores the user's menu choice.

    do
    {
        cout << "\n============================================" << endl;
        cout << " NUL SMART LABORATORY MANAGEMENT SYSTEM" << endl;
        cout << "============================================" << endl;

        cout << "1. Add laboratory at beginning" << endl;
        // Menu option for addFront.

        cout << "2. Add laboratory at end" << endl;
        // Menu option for addEnd.

        cout << "3. Add laboratory at position" << endl;
        // Menu option for addAtPosition.

        cout << "4. Display laboratories" << endl;
        // Menu option for display.

        cout << "5. Remove laboratory" << endl;
        // Menu option for deletion.

        cout << "6. Update laboratory" << endl;
        // Menu option for updating.

        cout << "7. Linear search" << endl;
        // Menu option for linear search.

        cout << "8. Bubble Sort by ID" << endl;
        // Menu option for Bubble Sort.

        cout << "9. Merge Sort by ID" << endl;
        // Menu option for Merge Sort.

        cout << "10. Binary search by ID" << endl;
        // Menu option for Binary Search.

        cout << "11. Save laboratories" << endl;
        // Menu option for saving.

        cout << "12. Reload laboratories" << endl;
        // Menu option for loading.

        cout << "13. Exit" << endl;
        // Exit option.

        cout << "\nEnter your choice: ";
        // Ask the user for a menu choice.

        cin >> choice;
        // Read the choice.
        cin.ignore(); 

        if (choice == 1)
        {
            Laboratory lab = enterLaboratory();
            // Ask the user to create a Laboratory.

            list.addFront(lab);
            // Add the Laboratory at the beginning.

            cout << "\nLaboratory added successfully." << endl;
            // Tell the user the operation succeeded.
        }
        

        else if (choice == 2)
        {
            Laboratory lab = enterLaboratory();
            // Ask the user for laboratory information.

            list.addEnd(lab);
            // Add the Laboratory at the end.

            cout << "\nLaboratory added successfully." << endl;
            // Confirm success.
        }


        else if (choice == 3)
        {
            Laboratory lab = enterLaboratory();
            // Ask the user for laboratory information.

            int position;
            // Stores the desired position.

            cout << "Enter position: ";
            // Ask for the position.

            cin >> position;
            // Read the position.
            cin.ignore();

            list.addAtPosition(lab, position);
            // Insert the Laboratory at that position.

            cout << "\nLaboratory added at position "
                 << position << "." << endl;
            // Confirm the insertion.
        }


        else if (choice == 4)
        {
            cout << "\n===== LABORATORIES =====" << endl;
            // Print a heading.

            list.display();
            // Traverse and display every laboratory.
        }

        else if (choice == 5)
        {
            string id;
            // Stores the ID of the laboratory to remove.

            cout << "Enter Laboratory ID to remove: ";
            // Ask the user for the ID.

            cin >> id;
            // Read the ID.
            cin.ignore();

            if (list.removeById(id))
            {
                // Try to remove the laboratory.

                cout << "\nLaboratory removed successfully." << endl;
                // Tell the user removal worked.
            }
            else
            {
                cout << "\nLaboratory not found." << endl;
                // Tell the user no matching ID existed.
            }
        }


        else if (choice == 6)
        {
            string id;
            // Stores the ID to update.

            cout << "Enter Laboratory ID to update: ";
            // Ask which laboratory should be updated.

            cin >> id;
            // Read the ID.
            cin.ignore();

            Laboratory* found = list.searchById(id);
            // Search the linked list for the laboratory.

            if (found != NULL)
            {
                // Check whether it was found.

                cout << "\nEnter the new laboratory information:" << endl;
                // Tell the user to enter replacement information.

                Laboratory updatedLab = enterLaboratory();
                // Create the updated Laboratory.

                if (list.updateById(id, updatedLab))
                {
                    // Replace the old laboratory.

                    cout << "\nLaboratory updated successfully." << endl;
                    // Confirm success.
                }
            }
            else
            {
                cout << "\nLaboratory not found." << endl;
                // Tell the user the ID does not exist.
            }
        }


        else if (choice == 7)
        {
            string id;
            // Stores the ID to search for.

            cout << "Enter Laboratory ID to search: ";
            // Ask for the ID.

            cin >> id;
            // Read the ID.
            cin.ignore();

            int number;
            // Stores the number of laboratories.

            Laboratory* array = list.toArray(number);
            // Convert the linked list into a dynamic array.

            Laboratory* result = linearSearch(array, number, id);
            // Perform linear search.

            if (result != NULL)
            {
                // Check whether the laboratory was found.

                cout << "\nLaboratory found:" << endl;
                // Print a heading.

                displayLaboratory(*result);
                // Display the matching laboratory.
            }
            else
            {
                cout << "\nLaboratory not found." << endl;
                // Tell the user it was not found.
            }

            delete[] array;
            // Free the temporary array.
        }

        else if (choice == 8)
        {
            int number;
            // Stores the number of laboratories.

            Laboratory* array = list.toArray(number);
            // Convert the list into a dynamic array.

            if (number > 0)
            {
                // Make sure there are laboratories to sort.

                bubbleSortById(array, number);
                // Sort the array using Bubble Sort.

                cout << "\nSorted laboratories:" << endl;
                // Display a heading.

                for (int i = 0; i < number; i++)
                {
                    // Go through the sorted array.

                    displayLaboratory(array[i]);
                    // Display each laboratory.

                    cout << "-------------------" << endl;
                    // Separate laboratories.
                }
            }
            else
            {
                cout << "\nThere are no laboratories to sort." << endl;
                // Tell the user the list is empty.
            }

            delete[] array;
            // Free the temporary array.
        }

        else if (choice == 9)
        {
            int number;
            // Stores the number of laboratories.

            Laboratory* array = list.toArray(number);
            // Convert the linked list into a dynamic array.

            if (number > 0)
            {
                // Make sure there are laboratories.

                mergeSortById(array, 0, number - 1);
                // Sort the array using Merge Sort.

                cout << "\nSorted laboratories:" << endl;
                // Print heading.

                for (int i = 0; i < number; i++)
                {
                    // Go through the sorted array.

                    displayLaboratory(array[i]);
                    // Display each laboratory.

                    cout << "-------------------" << endl;
                    // Separate laboratories.
                }
            }
            else
            {
                cout << "\nThere are no laboratories to sort." << endl;
                // Tell the user the list is empty.
            }

            delete[] array;
            // Free the temporary array.
        }

        else if (choice == 10)
        {
            int number;
            // Stores the number of laboratories.

            Laboratory* array = list.toArray(number);
            // Convert the list to an array.

            if (number > 0)
            {
                // Make sure there are laboratories.

                mergeSortById(array, 0, number - 1);
                // Binary Search requires the array to be sorted first.

                string id;
                // Stores the ID to search for.

                cout << "Enter Laboratory ID to search: ";
                // Ask for the ID.

                cin >> id;
                // Read the ID.
                cin.ignore();

                int position = binarySearch(array, number, id);
                // Perform Binary Search.

                if (position != -1)
                {
                    // Check whether the ID was found.

                    cout << "\nLaboratory found:" << endl;
                    // Print heading.

                    displayLaboratory(array[position]);
                    // Display the found laboratory.
                }
                else
                {
                    cout << "\nLaboratory not found." << endl;
                    // Tell the user it was not found.
                }
            }
            else
            {
                cout << "\nThere are no laboratories to search." << endl;
                // The list is empty.
            }

            delete[] array;
            // Free the temporary array.
        }

        else if (choice == 11)
        {
            if (fm.saveToFile(list, filename))
            {
                // Try to save the data.

                cout << "\nLaboratories saved successfully." << endl;
                // Confirm success.
            }
            else
            {
                cout << "\nCould not save laboratories." << endl;
                // Report failure.
            }
        }

        else if (choice == 12)
        {
            if (fm.loadFromFile(list, filename))
            {
                // Try to load the saved data.

                cout << "\nLaboratories loaded successfully." << endl;
                // Confirm success.
            }
            else
            {
                cout << "\nCould not load laboratories." << endl;
                // Report failure.
            }
        }

        else if (choice == 13)
        {
            fm.saveToFile(list, filename);
            // Automatically save the laboratories before exiting.

            cout << "\nData saved. Goodbye!" << endl;
            // Tell the user the program is closing.
        }


        else
        {
            cout << "\nInvalid choice." << endl;
            // Tell the user their menu choice was invalid.
        }

    }
    while (choice != 13);
    // Continue displaying the menu until the user chooses Exit.

    return 0;
    // End the program successfully.
}
