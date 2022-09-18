#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct smth
{
	bool a_1;
	long long a_7;
	char a_2;
	double a_8;


	short a_3;
	int a_4;
	long a_5;
	float a_6;
};

int main(int argc, char* argv[])
{
	cout << sizeof(smth) << endl;

	int sum = 0;
	vector<int> a(8);
	a = { 1, 1, 2, 4, 4, 4, 8, 8 };
	do
	{
		int t_sum = 0;
		for (int i = 0; i < 8; ++i)
		{
			if (t_sum % a[i] == 0)
			{
				t_sum += a[i];
			}
			else
			{
				t_sum += a[i] - (t_sum % a[i]) + a[i];
			}
		}
		sum = max(sum, t_sum);
	} while (next_permutation(a.begin(), a.end()));

	cout << "proving that this is max: " << sum << endl;

	return EXIT_SUCCESS;
}