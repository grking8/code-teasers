#include <iostream>
#include <string>

using namespace std;

/* funtion prototypes */
// function that returns the number of digits in an integer
int numberOfDigits(int n, int i); //is the counter index, i = 1
// power function that works with integers
int power(int a, int b); // returns a^b
// function that takes a positive integer and returns an array with its digits
int * digitsArray(int n);
// function that sees if a number contains any zeros
bool anyZeros(int n, int i); // i is the counter index, i = 1, n > 0
// function that returns a special kind of sum for an array given eg {2, 5, 0, 2, 0, 1, 0} returns 25 + 2 + 1
int specialSum(int * T, int n); // n the size of T

/* funtion definitions */
int numberOfDigits(int n, int i) //is the counter index, i = 1
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

int power(int a, int b) // we return a^b
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

bool anyZeros(int n, int i) // i is the counter index, i = 1, n > 0
{
	// the first digit is non zero so we don't have to check it
	if (numberOfDigits(n, 1) == i)
	{
		return false;
	}
	else
	{
		if (n % power(10, i) == 0)
		{
			return true;
		}
		else
		{
			n = n - (n % power(10, i));
			return anyZeros(n, i + 1);
		}
	}
}

int specialSum(int * T, int n)
{
	int i(0); int j(0); int k(0); int sum(0); // we need 3 counter indices. i to run through the elements of T
	while (i < n)
	{
		while (T[i + k] != 0)
		{
			k++; // k tells us the position of the next zero in the array
		}
		while (j < k) // j is the index for this mini loop
		{
			sum += power(10, k - 1 - j) * T[i + j];
			j++;
		}
		i = i + k + 1; k = 0; j = 0;
	}
	return sum;
}

// main function
int main()
{
	// we break the sum into parts: numbers without zeros and numbers with zeros
	int i(1);
	int sum(0);
	while (i < 10001)
	{
		if (anyZeros(i, 1))
		{
			sum += specialSum(digitsArray(i), numberOfDigits(i, 1));
		}
		else
		{
			sum += i;
		}
		i++;
	}
	cout << "The solution is " << sum << endl; 
	
	return 0;
}
		
	


	