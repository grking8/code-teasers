#include <iostream>
#include <string>
#include <cmath>

using namespace std;
// power function because the one in cmath returns a double and we want an integer
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

// function that returns the number of digits of an integer
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

// function that sees if a number contains any zeros
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
// main function
int solution(int n) // n = 1 million
{
	int i(1);
	while (i < 1000)
	{
		if (anyZeros(i, 1))
		{
			i++;
		}
		else
		{
			if (n % i == 0 && anyZeros(n / i, 1) == false)
			{
				return i;
			}
			i++;
		}
	}
}
// print solution
int main()
{
	cout << solution(1000000) << ", " << 1000000 / solution(1000000) << endl;
	
	return 0;
}
	
		
