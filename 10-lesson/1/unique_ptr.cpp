#include <iostream>
#include<memory>

using namespace std;

int main()
{
    //example from: https://learn.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-unique-ptr-instances?view=msvc-170
    // Create a unique_ptr to an array of 5 integers.
    auto p = make_unique<int[]>(5);

// Initialize the array.
    for (int i = 0; i < 5; ++i)
    {
        p[i] = i;
        cout << p[i] << endl;
    }
}
