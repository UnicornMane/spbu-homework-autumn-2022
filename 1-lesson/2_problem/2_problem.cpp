#include <iostream>

using namespace std;

class smth
{
    int x = 3;
    int y = 5;
    int z = 2;
    void printX();
    void printY();
    void printZ();
};

void smth::printX()
{
    cout << 3 << endl;
}
void smth::printY()
{
    cout << 5 << endl;
}
void smth::printZ()
{
    cout << 2 << endl;
}



int main()
{
    smth A;

    cout << &A << endl;

    int* tmp = (int*)(&A);

    cout << *tmp << "->";
    *tmp = 10;
    cout << *tmp << endl;
    tmp += 1;

    cout << *tmp << "->";
    *tmp = 10;
    cout << *tmp << endl;
    tmp += 1;

    cout << *tmp << "->";
    *tmp = 10;
    cout << *tmp << endl;
    tmp += 1;
    

    void (*tmp1)() = (void(*)())((int)&main + 4696);

    tmp1();


    tmp1 = (void(*)())((int)&main + 2552);

    tmp1();


    tmp1 = (void(*)())((int)&main + 4856);

    tmp1();
}