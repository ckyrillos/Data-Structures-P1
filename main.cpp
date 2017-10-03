#include <iostream>
#include "OrderedList.h"
using namespace std;

int main()
{
    string filePath = "uniform_small2.in";

    OrderedList list(filePath);
    cout << endl << "list.size = " << list.size << endl;
    for (int i = 0; i < list.size; i++)
    {
        cout << list.orderedArray[i] << " " ;
    }

    cout << "search " << list.binarySearch(101) << endl;


    return 0;
}
