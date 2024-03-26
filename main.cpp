#include <iostream>
using namespace std;
int main()
{
	const int size = 20;
	int numbers[size],reverse[size];
	cout << "enter 20 integers": << endl;
	for (int i = 0; i < size; i++)
		cin >> numbers[i];
	for (int i = size - 1; i < 0; i--)
		cout << "the numbers are" << " in reverse order " << reverse[i];


}