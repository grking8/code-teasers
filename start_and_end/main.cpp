#include <iostream>
#include <string>
#include <cmath>

using namespace std;
// we will need a power function that works with integers
int power(int a, int b); // returns a^b
// a function that for a natural number that ends in six will erase the six and place it in front of the remaining digits
int eraseAndMove(int n);
// we need to know the number of digits that n has
int numberOfDigits(int n, int i); // i = 1
// which has for definition
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
// definition of power
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
// definition of eraseAndMove
int eraseAndMove(int n)
{
	int p(numberOfDigits(n, 1));
	int solution(n);
	// we erase 
	solution /= 10;
	// we store the last digit
	int q(n % 10);
	// we move
	return solution + q * power(10, p - 1);
}

int main()
{
	int i(1);
	while ((i % 10 != 6) || (eraseAndMove(i) != 4 * i))
	{
		i++;
	}
	cout << "The solution is " << i << endl;
	
	return 0;
}

	
	
	



	
	