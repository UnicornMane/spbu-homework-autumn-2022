#include <iostream>

using namespace std;

class A
{
public:
    int *a = new int[10];
    A(int t = 0)
    {
        a[5] = t;
    }
    ~A()
    {
        delete[] a;
        cout << "~A\n";
    }
};

class B : public A
{
public:
    B(int t = 0) : A(t)
    {

    }
    ~B()
    {
        a[5] = 0;
        cout << "~B\n";
    }
};

int main()
{
    B b(5);
    cout << b.a[5] << endl;

    return 0;
}
