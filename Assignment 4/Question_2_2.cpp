#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void performBubbleSort(vector<int>& array) 
{
    int size = array.size();
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }
}

int main() 
{
    vector<int> numbers(10000);
    for (int i = 0; i < 10000; ++i)
        numbers[i] = 10000 - i;

    auto startTime = chrono::high_resolution_clock::now();

    performBubbleSort(numbers);

    auto endTime = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);
    cout << "Bubble Sort Execution Time: " << duration.count() << " microseconds\n";

    cout << "First 10 integers: ";
    for (int i = 0; i < 10; ++i)
        cout << numbers[i] << " ";
    cout <<endl;

    cout << "Last 10 integers: ";
    for (int i = 9990; i < 10000; ++i)
        cout << numbers[i] << " ";
    cout <<endl;

    return 0;
}
