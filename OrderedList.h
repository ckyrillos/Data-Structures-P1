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
    int *orderedArray;
    int size;

    OrderedList(string);
    ~OrderedList();
    void readFromFile(string);
    void mergeSort(int[], int, int);
    void merge(int[], int, int, int);
    int binarySearch(int);
    void print();

};

OrderedList::OrderedList(string filePath)
{
    readFromFile(filePath);
    mergeSort(orderedArray, 0, size-1);
}

OrderedList::~OrderedList()
{
    delete []orderedArray;
}

void OrderedList::readFromFile(string filePath)
{
    ifstream dataFile;

    // Opens file and makes sure it is valid.
    dataFile.open(filePath.c_str());

    if(!dataFile)
    {
        cout << "error with file1" << endl;
        return;
    }

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

void OrderedList::merge(int data[], int first, int mid, int last)
{
    int leftLength = mid - first + 1;
    int rightLength =  last - mid;

    // Creates temp arrays for left and right half of array.
    int L[leftLength], R[rightLength];
//    int * L = new int[leftLength];
//    int * R = new int[rightLength];

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

void OrderedList::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << orderedArray[i] << " ";
    }
    cout << endl;
}

#endif //PROJECT_1_ORDEREDLIST_H
