/*
 * MTFList.h
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

#ifndef PROJECT_1_MTFLIST_H
#define PROJECT_1_MTFLIST_H

#include <fstream>
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;

class MTFList
{
public:
    MTFList(string);
    MTFList();
    ~MTFList();
    void readFromFile(string);
    int mtfSearch(int);
    void print();

private:
    Node *headPtr;
    int size;
};

MTFList::MTFList(string filePath)
{
    headPtr = NULL;
    size = 0;
    readFromFile(filePath);
}

MTFList::~MTFList()
{
    while(headPtr != NULL)
    {
        Node * ptr = headPtr;
        headPtr = headPtr->next;
        delete ptr;
    }

}

void MTFList::readFromFile(string filePath)
{
    ifstream dataFile;
    int nodeData;

    // Opens file and makes sure it is valid.
    dataFile.open(filePath.c_str());

    if(!dataFile)
    {
        cout << "error with file2" << endl;
        return;
    }


    if(dataFile.good())
    {
        // Reads size into size.
        dataFile >> size;
        for (int i = 0; i < size+1; i++)
        {
            dataFile >> nodeData;
            if (headPtr == NULL)
            {
                headPtr = new Node(nodeData, NULL);
            }
            else
            {
                Node *ptr = headPtr;
                while(ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = new Node(nodeData, NULL);
            }
        }

        // Closes file after successfully reading data into linked list.
        dataFile.close();
    }
    else
    {
        // Closes files since something went wrong.
        // Normally I would include a cout here but the project stated there should be no other output.
        dataFile.close();
    }
}

int MTFList::mtfSearch(int key)
{

    Node *current = headPtr;
    Node *prev = current;
    while(current != NULL)
    {
        if (current->data == key)
        {
            if(current != prev)
            {
                prev->next = current->next;
                current->next = headPtr;
                headPtr = current;
            }
            return 1;
        }

        prev = current;
        current = current->next;
    }
    return 0;
}

void MTFList::print()
{
    Node *ptr = headPtr;
    while(ptr->next != NULL)
    {
        cout << ptr->data << " " << endl;
        ptr = ptr->next;
    }
}

MTFList::MTFList() {
    size = 0;
    headPtr = NULL;
}

#endif //PROJECT_1_MTFLIST_H
