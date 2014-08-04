#include <iostream>
#include <string>

using namespace std;
/* We have x/y = 1/3 <=> 3x = y. We are going to check each couple (x, 3x) starting from x=1 */

/* prototypes of functions that we will need */
// fonction that takes an array of nine digits and sees whether it is a permutation of {1, ..., 9}
bool isPerm(int * T);
// function that takes a positive integer and returns an array with its digits
int * digitsArray(int n);
// function that concatenates two arrays of integers
int * concaTwoArrays(int * T, int n, int * U, int m); // n and m the size of T and U respectively
// function that returns the number of digits in an integer
int numberOfDigits(int n, int i); //is the counter index, i = 1
// we will need a power function that works with integers
int power(int a, int b); // returns a^b

/* function definitions */
bool isPerm(int * T)
{
	// we create the array to compare
	// first we create an array of 9 zeros
	int Z[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i(0);
	while (i < 9)
	{
		Z[T[i] - 1]++;
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if (Z[i] == 1)
		{
			i++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int * digitsArray(int n)
{
	// we create the array
	int d(numberOfDigits(n, 1));
	int * T = new int[d];
	// we fill it in
	int i(0);
	while (i < d)
	{
		int p(n / power(10, d - 1 - i));	
		T[i] = p;
		n = n % power(10, d - 1 - i);
		i++;
	}
	return T;
}

int * concaTwoArrays(int * T, int n, int * U, int m) 
{
	int * C = new int[n + m];
	int i(0);
	while (i < n)
	{
		C[i] = T[i];
		i++;
	}
	i = 0;
	while (i < m)
	{
		C[n + i] = U[i]; 
		i++;
	}
	return C;
}

int numberOfDigits(int n, int i)
{
	if (n / power(10, i) == 0)
	{
		return i;
	}
	else
	{
		return numberOfDigits(n, i + 1);
	}
}

int power(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	if (b == 1)
	{
		return a;
	}
	else
	{
		return a * power(a, b - 1);
	}
}

/* main function */
int main()
{
	int i(1);
	while (i < 987654321) // we set an arbitrary upper bound that will work
	{
		int p(numberOfDigits(i, 1) + numberOfDigits(3 * i, 1)); // we check to see if we have in total 9 digits.
		if (p != 9)
		{
			i++; // don't have 9 digits so move on to the next value
		}
		else
		{
			int * T = concaTwoArrays(digitsArray(i), numberOfDigits(i, 1), digitsArray(3 * i), numberOfDigits(3 * i, 1));
			if (isPerm(T))
			{
				cout << i << "/" << 3 * i << " is a solution" << endl;
				return 0;
			}
			else
			{
				i++;
			}
		}
	}	
}