#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// Used KMP algorithm
// inputReversed + # + input
// F[length - 1] indicates the max palindrome length found at the end of the string
// Given that KMP computes the longest proper prefix that is also a suffix,
// reversing the input does the trick
// # is added to make sure the F calculations are separated from the inputReversed
//
// It can be solved used Rabin Karp algorithm

const int N = (1e5 * 2) + 5;

int n;
char input[N], str[N];
int F[N];

int getNewLen(int len, char c)
{
	while (len && c != str[len])
		len = F[len - 1];
	if (c == str[len])
		++len;
	return len;
}

void computeF()
{
	F[0] = 0;
	for (int i = 1; str[i]; ++i)
		F[i] = getNewLen(F[i - 1], str[i]);
}

int main()
{
	while (~scanf("%s", input))
	{
		int inputLength = strlen(input);
		strcpy(str, input);
		reverse(str, str + inputLength);
		strcat(str, "#");
		strcat(str, input);
		computeF();
		int maxPalLength = F[strlen(str) - 1];
		printf("%s", input);
		for (int i = inputLength - maxPalLength - 1; i > -1; --i)
		{
			printf("%c", input[i]);
		}
		printf("\n");
	}
	return 0;
}

// Rabin Karp solution

// #include <iostream>
// #include <cstring>
// using namespace std;

// const int N = 1e5 + 5, MOD = 1e9 + 7, base = 59;

// int n;
// char str[N];

// inline void addLDigit(long long& h, int base, long long mod, char digit)	// 517 = (51*10 + 7)
// {
// 	h = ((h*base) % mod + digit) % mod;
// }

// inline void addMDigit(long long& h, long long p, long long mod, char digit)	//517 = (17 + 5*100)
// {
// 	h = (h + (digit*p) % mod) % mod;
// }

// int main()
// {
// #ifdef AYMAN_PC
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	while (~scanf("%s", str))
// 	{
// 		long long h1 = 0, h2 = 0, p = 1, maxPalindrome = 0;
// 		n = strlen(str);
// 		for (int i = n - 1; ~i; --i)
// 		{
// 			addLDigit(h1, base, MOD, str[i] - 'A');
// 			addMDigit(h2, p, MOD, str[i] - 'A');
// 			if (h1 == h2)  maxPalindrome = i;
// 			p = (p*base) % MOD;
// 		}
// 		printf("%s", str);
// 		for (int i = maxPalindrome - 1; ~i; --i)
// 			printf("%c", str[i]);
// 		printf("\n");
// 	}
// 	return 0;
// }
