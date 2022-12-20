#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int Sum = 0;

void compute()
{
    vector<int> a(8);
    a = {1, 1, 2, 4, 4, 4, 8, 8};
    do
    {
        int t_sum = 0;
        for (int i = 0; i < 8; ++i)
        {
            if (t_sum % a[i] == 0)
            {
                t_sum += a[i];
            } else
            {
                t_sum += a[i] - (t_sum % a[i]) + a[i];
            }
        }
        Sum = max(Sum, t_sum);
    } while (next_permutation(a.begin(), a.end()));
}

int OddSum = 0;

void findOdd()
{
    for (int i = 1; i <= 1900000000; ++i)
    {
        if ((i % 2) == 1)
        {
            ++OddSum;
        }
    }
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    compute();
    findOdd();
    cout << Sum << endl << OddSum << endl;

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<float> duration = end - start;
    cout << "Duration: " << duration.count() << 's' << endl;

    return 0;
}
