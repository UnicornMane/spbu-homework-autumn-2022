#include <iostream>
#include<cmath>

struct foo
{
    int *data = nullptr; //не просто так вводили нулевые указатели
    int size = 0;

    foo(int n)
    {
        size = n;
        data = new int[2 * n];
    }

    foo(foo &A) //нужен &, чтобы не пользоваться инструктором копирования, которого ещё нет
    {
        size = A.size;
        data = new int[2 * size]; // data -> int, потому что мы делаем аналогично foo(int)

        for (int i = 0; i < 2 * size; ++i) //у нас тут нет "n" + i/2 будет работать некорректно, если size = 3
        {
            data[i] = A.data[i];
        }
    }
    ~foo()
    {
        delete []data; //A -> data + [] for arrays
    }
    foo &operator=(foo &A) //needs to be updated
    {
        //swap needs to be defined
        delete []data;
        size = A.size;
        data = new int[2 * size];

        for (int i = 0; i < 2 * size; ++i)
        {
            data[i] = A.data[i];
        }

        return *this;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    foo a(3);
    a.data[0] = 3;
    foo b = a;
    std::cout << b.data[0] << std::endl;
    foo c(b);
    std::cout << c.data[0];
    return 0;
}
