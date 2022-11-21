#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "selfVector.h"

using namespace std;


int main()
{
    int n = 0;
    cin >> n;
    selfVector<int> f(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> f[i];
    }

    ofstream of("MyTxt.txt");

    of.rdbuf()->sputn(reinterpret_cast<char*>(&n), sizeof(n));

    for(int i = 0; i < n; ++i)
    {
        of.rdbuf()->sputn(reinterpret_cast<char*>(&f[i]), sizeof(int));
    }

}
