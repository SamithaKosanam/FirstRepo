#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <string>

inline long long systemTimeNanoseconds(){
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::time_point_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now()
            ).time_since_epoch()
    ).count();
}

inline std::vector<std::string>& getStringData(){
    static std::vector<std::string> stringDataSet;
    if (stringDataSet.size() == 0)    {
        char tempSet[6] = "     ";
        for (tempSet[0] = 'a'; tempSet[0] <= 'z'; tempSet[0]++)
            for (tempSet[1] = 'a'; tempSet[1] <= 'z'; tempSet[1]++)
                for (tempSet[2] = 'a'; tempSet[2] <= 'z'; tempSet[2]++)
                    for (tempSet[3] = 'a'; tempSet[3] <= 'z'; tempSet[3]++)
                        for (tempSet[4] = 'a'; tempSet[4] <= 'z'; tempSet[4]++)
                            stringDataSet.push_back(std::string(tempSet));
    }
    return stringDataSet;
}

using namespace std;

int linearSearch(vector<string> dataSet, string element);

int binarySearch(vector<string> dataSet, string element);

int main() {
    // initialize dataSet string vector
    vector<string> dataSet = getStringData();

    // invoke linearSearch and binarySearch methods for each of the three desired strings
    // output time taken for each method to run each time
    //auto startLinearSearch = std::chrono::system_clock::now();

    auto startLinearSearch = chrono::system_clock::now();
    linearSearch(dataSet, "not_here");
    auto endLinearSearch = chrono::system_clock::now();
    auto timeTaken = chrono::duration_cast<chrono::nanoseconds>(endLinearSearch- startLinearSearch);

    cout << "\nLinear search time for 'not_here': " << timeTaken.count();

    auto startBinarySearch = chrono::system_clock::now();
    binarySearch(dataSet, "not_here");
    auto endBinarySearch = chrono::system_clock::now();
    timeTaken = chrono::duration_cast<chrono::nanoseconds>(endBinarySearch-startBinarySearch);

    cout << "\nBinary search time for 'not_here': " << timeTaken.count();

    startLinearSearch = chrono::system_clock::now();
    linearSearch(dataSet, "mzzzz");
    endLinearSearch = chrono::system_clock::now();
    timeTaken = chrono::duration_cast<chrono::nanoseconds>(endLinearSearch-startLinearSearch);

    cout << "\nLinear search time for 'mzzzz': " << timeTaken.count();

    startBinarySearch = chrono::system_clock::now();
    binarySearch(dataSet, "mzzzz");
    endBinarySearch = chrono::system_clock::now();
    timeTaken = chrono::duration_cast<chrono::nanoseconds>(endBinarySearch-startBinarySearch);

    cout << "\nBinary search time for 'mzzzz': " << timeTaken.count();

    startLinearSearch = chrono::system_clock::now();
    linearSearch(dataSet, "aaaaa");
    endLinearSearch = chrono::system_clock::now();
    timeTaken = chrono::duration_cast<chrono::nanoseconds>(endLinearSearch-startLinearSearch);

    cout << "\nLinear search time for 'aaaaa': " << timeTaken.count();

    startBinarySearch = chrono::system_clock::now();
    binarySearch(dataSet, "aaaaa");
    endBinarySearch = chrono::system_clock::now();
    timeTaken = chrono::duration_cast<chrono::nanoseconds>(endBinarySearch-startBinarySearch);

    cout << "\nBinary search time for 'aaaaa': " << timeTaken.count();

    return 0;
}



int linearSearch(vector<string> dataSet, string element)
{
    for (int i=0;i<dataSet.size();i++)
    {
        if (dataSet.at(i) == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<string> dataSet, string element) {
    int leftEndPoint = 0;
    int rightEndPoint = dataSet.size() - 1;

    while (leftEndPoint <= rightEndPoint) {
        int currentMid = leftEndPoint + (rightEndPoint - leftEndPoint) / 2; // Calculates the current middle-index value

        if (dataSet.at(currentMid) == element)
            return currentMid;

        if (dataSet.at(currentMid).compare(element) > 0) // returns a positive number if currentMid comes after element
            rightEndPoint = currentMid - 1;
        else
            leftEndPoint = currentMid + 1;
    }
    return -1;
}