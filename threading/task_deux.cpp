#include <iostream>
#include <future>   // pair of a promise and a future
#include <vector>

using namespace std;

template<typename T>
T cube(T num) {
    return num*num*num;
}


int main()
{
    cout << "Threading using tasks ... \n\n";
    // vector of 10 tasks
    vector<future<int>> tasks(21);
    // Sum of cubes
    int sumOfCubes = 0;
    for(int i=0; i<21; i++)
    {
        tasks[i] = async(&cube<int>, i);
        sumOfCubes += tasks[i].get();
    }
    cout << "Sum(1^3 + 2^3 + 3^3 + ... + 20^3) = " << sumOfCubes << endl;

    return 0;
}
// Compilation :: g++ task_deux.cpp -lpthread -std=c++11 -o task_deux 