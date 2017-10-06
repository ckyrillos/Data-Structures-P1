/*
 * Ethics Statement:
 * Other than anything noted in the disclosures below, the code submitted is of my design and my design alone.
 * I recieved no help nor used any references, resources, and had no discussion with other classmates.
 * I understand the University policy concerning ethics and
 * understand that violating this policy will result in drastic repercussions.
 *
 * Disclosures:
 * No disclosures.
*/


#include <iostream>
#include <ctime>
#include <iomanip>
#include "OrderedList.h"
#include "MTFList.h"
using namespace std;

int main(int argc, const char *argv[])
{
    // Creates ints for  length of list, number of queries, temp variable to skip to queries, and int to store key.
    int lengthList;
    int numQueries;
    int temp;
    int key;

    // Timing variables
    clock_t timeBegin, timeEnd;
    double olTotalTime = 0.0;
    double mtflTotalTime = 0.0;

    // Takes in file path and stores in both lists.
    string filePath = string(argv[1]);

    //BEGIN ORDERED LIST TEST
    timeBegin = clock();
    OrderedList orderedList(filePath);

    // Creates ifstream object and opens the file.
    ifstream dataFile;
    dataFile.open(filePath.c_str());

    // Get length of list and skips to the queries.
    dataFile >> lengthList;
    for (int i = 0; i < lengthList; i++)
    {
        dataFile >> temp;
    }

    // Gets number of queries and searches data structure for
    dataFile >> numQueries;
    for (int i = 0; i < numQueries; i++)
    {
        dataFile >> key;
        orderedList.binarySearch(key);
    }

    timeEnd = clock();
    olTotalTime = (double)(timeEnd - timeBegin)/CLOCKS_PER_SEC;
    dataFile.close();
    //END ORDERED LIST TEST


    //BEGIN MTF LIST TEST
    MTFList mtfList(filePath);
    timeBegin = clock();

    // Creates ifstream object and opens the file.
    ifstream dataFile2;
    dataFile2.open(filePath.c_str());

    // Get length of list and skips to the queries.
    dataFile2 >> lengthList;
    for (int i = 0; i < lengthList; i++)
    {
        dataFile2 >> temp;
    }

    //Gets number of queries and searches data structure for
    dataFile2 >> numQueries;
    for (int i = 0; i < numQueries; i++)
    {
        dataFile2 >> key;
        mtfList.mtfSearch(key);
    }

    timeEnd = clock();
    mtflTotalTime = (double)(timeEnd - timeBegin)/CLOCKS_PER_SEC;
    dataFile2.close();
    //END MTF LIST TEST

    // Outputs results
    cout << "Time to Complete Sequence of Retrievals for Ordered Array = " << setprecision(8) << olTotalTime << endl;
    cout << "Time to Complete Sequence of Retrievals for MTF Linked List = " << setprecision(8) << mtflTotalTime << endl;

    // Checks which way is faster and outputs results.
    if (olTotalTime > mtflTotalTime)
    {
        cout << "The MTF Linked List was faster." << endl;
    }
    else
    {
        cout << "The Ordered Array was faster." << endl;
    }

    return 0;
}
