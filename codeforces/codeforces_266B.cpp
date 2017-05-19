#include <iostream>
using namespace std;

void main()
{
	size_t n, t;
	cin >> n >> t;
	char input;
	char data[50], updatedData[50];
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		data[i] = input;
		updatedData[i] = input;
	}
	for (size_t i = 0; i < t; i++)
	{
		for (size_t j = 1; j < n; j++)
		{
			if (data[j] == 'G' && data[j - 1] == 'B')
			{
				updatedData[j - 1] = 'G';
				updatedData[j] = 'B';
			}
		}
		for (size_t j = 0; j < n; j++)
		{
			data[j] = updatedData[j];
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << data[i];
	}
}