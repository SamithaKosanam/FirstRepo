#include <iostream>
#include <vector>
#include "StringData.h"
using namespace std;

int linearSearch(vector<string> dataSet, string element);

int binarySearch(vector<string> dataSet, string element);

int main() {

    vector<string> stringData = getStringData();

    auto start = chrono::system_clock::now();
    linearSearch(stringData, "not_here");
    auto end = chrono::system_clock::now();
    chrono::duration <double> diff = end-start;
    cout << "Linear search results for not_here " << diff.count() << endl;

    start = chrono::system_clock::now();
    binarySearch(stringData, "not_here");
    end = chrono::system_clock::now();
    diff = end-start;
    cout << "Binary search results for not_here " << diff.count() << endl;

    start = chrono::system_clock::now();
    linearSearch(stringData, "mzzzz");
    end = chrono::system_clock::now();
    diff = end-start;
    cout << "Linear search results for mzzzz " << diff.count() << endl;

    start = chrono::system_clock::now();
    binarySearch(stringData, "mzzzz");
    end = chrono::system_clock::now();
    diff = end-start;
    cout << "Binary search results for mzzzz " << diff.count() << endl;

    start = chrono::system_clock::now();
    linearSearch(stringData, "aaaaa");
    end = chrono::system_clock::now();
    diff = end-start;
    cout << "Linear search results for aaaaa " << diff.count() << endl;

    start = chrono::system_clock::now();
    binarySearch(stringData, "aaaaa");
    end = chrono::system_clock::now();
    diff = end-start;
    cout << "Binary search results for aaaaa " << diff.count() << endl;

    return 0;
}

int linearSearch(vector<string> dataSet, string element)
{
    for (int i = 0; i < dataSet.size(); i++)
    {
        if(dataSet[i] == element)
        {
            return i;
        }
    }

    return 0;
}

int binarySearch(vector<string> dataSet, string element)
{
    int low = 0, mid = 0;
    int high = dataSet.size()-1;

    while (high >= low)
    {
        mid = (low + (high-low)/2);

        if (element.compare(dataSet[mid]) > 0)
        {
            low = mid + 1;
        } else if (element.compare(dataSet[mid]) < 0)
        {
            high = mid - 1;
        } else if (element.compare(dataSet[mid]) == 0)
        {
            return mid;
        }
    }

    return 0;
}

