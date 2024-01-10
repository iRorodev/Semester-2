#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

int main() 
{
    vector<int> numbers(10000);

    for (int i = 0; i < 10000; ++i)
        numbers[i] = 10000 - i;

    auto startTime = chrono::high_resolution_clock::now();
   
    sort(numbers.begin(), numbers.end());
   
    auto endTime = chrono::high_resolution_clock::now();
   
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);
    
    cout << "STL Sort Execution Time: " << duration.count() << " microseconds\n";
    
    cout << "First 10 integers: ";
    for (int i = 0; i < 10; ++i)
        cout << numbers[i] << " ";

    cout << "\nLast 10 integers: ";
    for (int i = 9990; i < 10000; ++i)
        cout << numbers[i] << " ";

    return 0;
}
