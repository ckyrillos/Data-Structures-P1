/*
 * OrderedList.h
 *
 * COSC 160 Fall 2017
 * Project #1
 *
 * Due on: OCT 4, 2017
 * Author: Carl Kyrillos
 *
 *
 * In accordance with the class policies and Georgetown's
 * Honor Code, I certify that, with the exception of the
 * class resources and those items noted below, I have neither
 * given nor received any assistance on this project.
 *
 * References not otherwise commented within the program source code.
 * Note that you should not mention any help from the TAs, the professor,
 * or any code taken from the class textbooks.
 */


#ifndef PROJECT_1_ORDEREDLIST_H
#define PROJECT_1_ORDEREDLIST_H

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class OrderedList
{
public:
    OrderedList(string);
    ~OrderedList();
    void readFromFile(string);
    void mergeSort(int[], int, int);
    void merge(int[], int, int, int);
    int binarySearch(int);
    void print();

private:
    int *orderedArray;
    int size;
};

// Constructor both reads in file and sorts it
OrderedList::OrderedList(string filePath)
{
    readFromFile(filePath);
    mergeSort(orderedArray, 0, size-1);
}

// Destructor
OrderedList::~OrderedList()
{
    delete []orderedArray;
}

// Reads file int array
void OrderedList::readFromFile(string filePath)
{
    ifstream dataFile;

    // Opens file and makes sure it is valid.
    dataFile.open(filePath.c_str());

    if(dataFile.good() && dataFile.is_open())
    {
        // Reads size into size.
        dataFile >> size;

        // Allocates memory for the dynamic array
        int * temp = new int[size];

        // Reads data into temp array.
        for(int i = 0; i < size; i++)
        {
            dataFile >> temp[i];
        }

        // Assigns to real array.
        orderedArray = temp;

        // Closes file after successfully reading data into array.
        dataFile.close();
    }
    else
    {
        // Closes files since something went wrong.
        // Normally I would include a cout here but the project stated there should be no other output.
        dataFile.close();
    }
}

// Mergesorts the array
void OrderedList::mergeSort(int data[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(data, first, mid);
        mergeSort(data, mid+1, last);
        merge(data, first, mid, last);
    }
}

// Merge is called by mergesort
void OrderedList::merge(int data[], int first, int mid, int last)
{
    int leftLength = mid - first + 1;
    int rightLength =  last - mid;

    // Creates temp arrays for left and right half of array.
    int L[leftLength], R[rightLength];

    // Copies data from array to left and right halves.
    for (int i = 0; i < leftLength; i++)
    {
        L[i] = data[first + i];
    }
    for (int j = 0; j < rightLength; j++) {
        R[j] = data[mid + 1 + j];
    }

    // Resets iterators
    int i = 0;
    int j = 0;
    int k = first;

    // Merges temp arrays back into main array.
    while (i < leftLength && j < rightLength)
    {
        if (L[i] <= R[j])
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    // Load remaining elements from left array.
    for (i; i < leftLength; i++, k++)
    {
        data[k] = L[i];
    }

    // Load remaining elements from right array.
    for (j; j < rightLength; j++, k++)
    {
        data[k] = R[j];
    }
}

// Binary search, returns index but for this project the return just says if successful or not
int OrderedList::binarySearch(int key)
{
    int low = 0;
    int mid;
    int high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key < orderedArray[mid])
        {
            high = mid - 1;
        }
        else if (key > orderedArray[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

// Simple print function for debugging
void OrderedList::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << orderedArray[i] << " ";
    }
    cout << endl;
}

#endif //PROJECT_1_ORDEREDLIST_H
