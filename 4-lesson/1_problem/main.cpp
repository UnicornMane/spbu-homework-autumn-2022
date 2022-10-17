#include <iostream>

using namespace std;


class character
{
    virtual void hair() = 0;
};

class A
{
public:
    A()
    {
        cout << "A\n";
    }
    ~A()
    {
        cout << "~A\n";
    }
    void out()
    {
        cout << "A_out\n";
    }
};

class B : public A
{
public:
    B(string a)
    {
        cout << a << " \t";
        cout << "B\n";
    }
    ~B()
    {
        cout << "~B\n";
    }
    void out()
    {
        cout << "B_out\n";
    }
};

class C : public B
{
public:
    C(string s):B(s)
    {
        cout << "C\n";
    }
    ~C()
    {
        cout << "~C\n";
    }
    void out()
    {
        cout << "C_out\n";
    }
};


int main(int argc, char *argv[])
{

    C c("hell0");
    c.out();

    return EXIT_SUCCESS;
}
