#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "selfVector.h"

using namespace std;

int main()
{
    ifstream of("MyTxt.txt");
    selfVector<int> rf;
    int size = 0;
    of.rdbuf()->sgetn(reinterpret_cast<char*>(&size), sizeof(size));
    rf.resize(size);
    for (int i = 0; i < size; ++i)
    {
        of.rdbuf()->sgetn(reinterpret_cast<char*>(&rf[i]), sizeof(int));
    }

    for (int i = 0; i < size; ++i)
    {
        cout << rf[i] << " ";
    }
}