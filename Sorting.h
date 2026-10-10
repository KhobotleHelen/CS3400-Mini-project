//declares bubble sort O(N^2) and Merge sort O(nlogn)

#ifndef SORTING_H
#define SORTING_H

#include "Laboratory.h"
// Sorting algorithms work with Laboratory objects.

void bubbleSortById(Laboratory array[], int size);
// Bubble Sort arranges laboratories by ID.

void mergeSortById(Laboratory array[], int left, int right);
// Merge Sort arranges laboratories by ID.

void merge(Laboratory array[], int left, int middle, int right);
// merge() combines two sorted sections.

#endif
