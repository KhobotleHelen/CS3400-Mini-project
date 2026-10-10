//implementing linear and binary searching.
#include "Searching.h"
// Include the declarations of our searching functions.

//Linear Search
Laboratory* linearSearch(Laboratory array[], int size, string id)
{
    for (int i = 0; i < size; i++)
    {
        // Check every laboratory from the beginning to the end.

        if (array[i].getId() == id)
        {
            // Compare the current laboratory's ID with the requested ID.

            return &array[i];
            // Return the address of the matching Laboratory.
        }
    }

    return NULL;
    // The ID was not found.
}
//Binary Search
int binarySearch(Laboratory array[], int size, string id)
{
    int low = 0;
    // low represents the first possible position.

    int high = size - 1;
    // high represents the last possible position.

    while (low <= high)
    {
        // Continue while there is still a possible search area.

        int middle = (low + high) / 2;
        // Find the middle position.

        if (array[middle].getId() == id)
        {
            // Check whether the middle laboratory is the one we want.

            return middle;
            // Return its position.
        }

        if (array[middle].getId() < id)
        {
            // If the middle ID comes before the requested ID...

            low = middle + 1;
            // ...ignore the left half.
        }
        else
        {
            // Otherwise the requested ID is before the middle.

            high = middle - 1;
            // Ignore the right half.
        }
    }

    return -1;
    // The ID was not found.
}
