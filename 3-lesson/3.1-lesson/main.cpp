#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <ctime>
#include <random>


using namespace std;

template<typename Iterator, typename T>
void qSort(const Iterator &begin, const Iterator &end, bool (*cmp)(T, T));


bool customCmp(int a, int b);

template<typename Iterator, typename T>
void genSort(const Iterator &begin, const Iterator &end,
             void (*algo)(const Iterator &begin, const Iterator &end, bool (*cmp)(T, T)), bool (*cmp)(T, T));


int main(int argc, char *argv[])
{
    srand(time(nullptr));
    vector<int> f(4);
    for (auto &i: f)
    {
        i = rand() % 10;
        cout << i << " ";
    }
    cout << endl;
    genSort(f.begin(), f.end(), qSort, customCmp);
    for (auto i: f)
    {
        cout << i << " ";
    }

    return EXIT_SUCCESS;
}


template<typename Iterator, typename T>
void genSort(const Iterator &begin, const Iterator &end,
             void (*algo)(const Iterator &begin, const Iterator &end, bool (*cmp)(T, T)), bool (*cmp)(T, T))
{
    algo(begin, end, cmp);
}


bool customCmp(int a, int b)
{
    return a >= b;
}


template<typename Iterator, typename T>
void qSort(const Iterator &begin, const Iterator &end, bool (*cmp)(T, T))
{
    for (auto i = begin; i != end; ++i)
    {
        for (auto j = begin; j != end; ++j)
        {
            if (cmp(*i, *j))
            {
                swap(*i, *j);
            }
        }
    }
}