//
// Created by Carl on 10/2/17.
//

#ifndef PROJECT_1_ORDEREDLIST_H
#define PROJECT_1_ORDEREDLIST_H

#include <fstream>
#include <string>
using namespace std;

class OrderedList
{
public:
    int *orderedArray;
    int size;

    OrderedList(string);
    void readFromFile(string);
    void mergeSort(int[], int, int);
    void merge(int[], int, int);
    int binarySearch(int);

};

OrderedList::OrderedList(string filePath)
{
    readFromFile(filePath);
    mergeSort(orderedArray, 0, size);
}

void OrderedList::readFromFile(string filePath)
{
    ifstream dataFile;

    // Opens file and makes sure it is valid.
    dataFile.open(filePath.c_str());
    if(dataFile.good())
    {
        // Reads size into size.
        dataFile >> size;

        // Reads data into array.
        for(int i = 0; i < size; i++)
        {
            dataFile >> orderedArray[i];
        }
    }
    else
    {
        cout << "error with file" << endl;
        dataFile.close();
        exit(0);
    }

}

void OrderedList::mergeSort(int data[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(data, first, mid);
        mergeSort(data, mid+1, last);
        merge(data, first, last);
    }
}

void OrderedList::merge(int data[], int first, int last)
{
    int mid = (first + last) / 2;
    int leftLength = mid - first + 1;
    int rightLength =  last - mid;

    // Creates temp arrays for left and right half of array.
    int L[leftLength], R[rightLength];

    // Copies data from array to left and right halves.
    for (int i = 0; i < leftLength; i++)
        L[i] = data[first + i];
    for (int j = 0; j < rightLength; j++)
        R[j] = data[mid + 1+ j];

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
            k++;
        }
        else
        {
            data[k] = R[j];
            j++;
            k++;
        }
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

#endif //PROJECT_1_ORDEREDLIST_H
