#include <iostream>

using namespace std;


struct smth
{
	bool a_1;
	char a_2;
	short a_3;
	int a_4;
	long a_5;
	float a_6;
	long long a_7;
	double a_8;
};

int main(int argc, char* argv[])
{
    cout << "size of class: " << sizeof(smth) << endl;
	cout << sizeof(bool) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(long long) << endl;
	cout << sizeof(double) << endl;
	//32 -- is the sum of all fields;
    return EXIT_SUCCESS;
}