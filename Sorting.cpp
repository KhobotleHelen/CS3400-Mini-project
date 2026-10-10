// This file implements Bubble Sort and Merge Sort.
#include "Sorting.h"
// means Include our sorting declarations.

void bubbleSortById(Laboratory array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        // Repeat passes through the array.

        for (int j = 0; j < size - i - 1; j++)
        {
            // Compare neighbouring laboratories.

            if (array[j].getId() > array[j + 1].getId())
            {
                // If they are in the wrong order

                Laboratory temporary = array[j];
                // Temporarily store the first Laboratory.

                array[j] = array[j + 1];
                // Move the second Laboratory into the first position.

                array[j + 1] = temporary;
                // Move the first Laboratory into the second position.
            }
        }
    }
}
void mergeSortById(Laboratory array[], int left, int right)
{
    if (left < right)
    {
        // Continue only when there is more than one item.

        int middle = (left + right) / 2;
        // Find the middle of the current section.

        mergeSortById(array, left, middle);
        // Sort the left half.

        mergeSortById(array, middle + 1, right);
        // Sort the right half.

        merge(array, left, middle, right);
        // Combine the two sorted halves.
    }
}

//Merge
void merge(Laboratory array[], int left, int middle, int right)
{
    int leftSize = middle - left + 1;
    // Calculate the size of the left half.

    int rightSize = right - middle;
    // Calculate the size of the right half.

    Laboratory* leftArray = new Laboratory[leftSize];
    // Dynamically create an array for the left half.

    Laboratory* rightArray = new Laboratory[rightSize];
    // Dynamically create an array for the right half.

    for (int i = 0; i < leftSize; i++)
    {
        // Copy the left half.

        leftArray[i] = array[left + i];
        // Store each left-side Laboratory.
    }

    for (int j = 0; j < rightSize; j++)
    {
        // Copy the right half.

        rightArray[j] = array[middle + 1 + j];
        // Store each right-side Laboratory.
    }

    int i = 0;
    // Start of left array.

    int j = 0;
    // Start of right array.

    int k = left;
    // Start position in the original array.

    while (i < leftSize && j < rightSize)
    {
        // Continue while both halves still contain items.

        if (leftArray[i].getId() <= rightArray[j].getId())
        {
            // If the left ID should come first...

            array[k] = leftArray[i];
            // Put the left Laboratory into the original array.

            i++;
            // Move to the next left Laboratory.
        }
        else
        {
            // Otherwise the right Laboratory comes first.

            array[k] = rightArray[j];
            // Put the right Laboratory into the original array.

            j++;
            // Move to the next right Laboratory.
        }

        k++;
        // Move to the next position in the original array.
    }

    while (i < leftSize)
    {
        // Copy any remaining left-side laboratories.

        array[k] = leftArray[i];
        // Copy the remaining Laboratory.

        i++;
        // Move forward.

        k++;
        // Move forward in the original array.
    }

    while (j < rightSize)
    {
        // Copy any remaining right-side laboratories.

        array[k] = rightArray[j];
        // Copy the remaining Laboratory.

        j++;
        // Move forward.

        k++;
        // Move forward in the original array.
    }

    delete[] leftArray;
    // Free the temporary left array.

    delete[] rightArray;
    // Free the temporary right array.
}
