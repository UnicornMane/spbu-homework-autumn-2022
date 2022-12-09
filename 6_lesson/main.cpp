#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "selfVector1.h"

using namespace std;


int main(int argc, char  *argv[])
{
//    ofstream fout;
//    fout.exceptions(ofstream::badbit | ofstream::failbit);
//
//    string fileName = "";
//    cin >> fileName;
//    try
//    {
//        fout.open(fileName);
//    }
//    catch (const ofstream::failure &ex)
//    {
//        cout << "bad file name\n";
//    }


    string tmp = "";
    cin >> tmp;
    int n = 0;
    n = stoi(tmp);
//    try
//    {
//        n = stoi(tmp);
//    }
//    catch (const invalid_argument &ex)
//    {
//        cout << "not an int type\n";
//    }
    selfVector<int> f(n);

    cout << f[0];



    return EXIT_SUCCESS;
}
