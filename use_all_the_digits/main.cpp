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
// function that for 3 digits given (excluding zero) returns the sum of all numbers that can be made from those 3 digits
int sumOfAllNumbersFromDigits(int p, int q, int r);
// function that given an array of 5 digits (excluding zero) returns the sum of all numbers that can be made from the digits in the array
int runningSum(int * T);
// function that checks if an array of 5 digits has distinct elements. If the first member of an array is not repeated elsewhere in the array, then the array consists of 
// unique members <=> the array formed by removing the first member is unique. Thus we can use a recursive function. We need a function that removes the first element of an array
int * removeFirstElement(int * T); // T has 5 elements
// and the main function
bool isUnique(int * T, int n); // n is a counter, n is the size of T, so we set n = 5
// function that sees if a number contains any zeros
bool anyZeros(int n, int i); // i is the counter index, i = 1, n > 0

/* function definitions */
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

int sumOfAllNumbersFromDigits(int p, int q, int r)
{
	int sum(0);
	int i(0);
	while (i < 3)
	{
		sum += (p + q + r) * 2 * power(10, i);
		i++;
	}
	
	return sum;
}

int runningSum(int * T)
{
	// we are going to go through the combinations of 3 numbers chosen from T
	int i, j, k; i = 0; j = 1; k = 2;
	int sum(0);
	while (i < 3)
	{
		while (j < 4)
		{
			while (k < 5)
			{
				sum += sumOfAllNumbersFromDigits(T[i], T[j], T[k]);
				k++;
			}
			j++; k = j + 1;
		}
		i++; j = i + 1; k = i + 2;
	}
	return sum;
}

int * removeFirstElement(int * T)
{
	int * U = new int[4];
	int i(0);
	while (i < 4)
	{
		U[i] = T[i + 1];
		i++;
	}
	return U;
}

bool isUnique(int * T, int n) 
{
	if (n == 1) // T contains only element so the array is unique
	{
		return true;
	}
	else
	{
		//check to see the first letter is unique
		int i(1);
		while (i < n)
		{
			if (T[0] == T[i])
			{
				return false;
			}
			else
			{
				i++;
			}
		}
		int * U = removeFirstElement(T);
		return isUnique(U, n - 1);
	}
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

int main()
{
	int i(12345);
	while (i < 98766)
	{
		if (anyZeros(i, 1) || not isUnique(digitsArray(i), 5))
		{
			i++;
		}
		else
		{
			if (runningSum(digitsArray(i)) == i)
			{
				cout << "The solution is " << i << endl;
				return 0;
			}
			else
			{
				i++;
			}
		}
	}
}