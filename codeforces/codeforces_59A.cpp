// using char array

#include <iostream>
using namespace std;

#define UPPER_LOWER_DIFF 32 // ('a' - 'A')

void main()
{
	char input[101] = { 0 }, upper[101] = { 0 }, lower[101] = { 0 };
	int size = 0, lowerCount = 0, upperCount = 0;
	while (cin >> input[size])
	{
		if (input[size] > 96) // Lower > 'a'
		{
			lower[size] = input[size];
			upper[size] = input[size] - UPPER_LOWER_DIFF;
			lowerCount++;
		}
		else
		{
			lower[size] = input[size] + UPPER_LOWER_DIFF;
			upper[size] = input[size];
			upperCount++;
		}
		size++;
	}
	if (lowerCount >= upperCount)
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << lower[i];
		}
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << upper[i];
		}
	}
}

// Using string

#include <iostream>
#include <string>
using namespace std;

void main()
{
	string input;
	int upper = 0, lower = 0;
	cin >> input;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (islower(input[i]))
			lower++;
		else
			upper++;
	}
	if (lower >= upper)
	{
		for (size_t i = 0; i < input.size(); i++)
		{
			cout << (char)tolower(input[i]);
		}
	}
	else
	{
		for (size_t i = 0; i < input.size(); i++)
		{
			cout << (char)toupper(input[i]);
		}
	}
}