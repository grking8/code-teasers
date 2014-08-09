#include <iostream>
#include <string>

using namespace std;


/* function prototypes */
// function that takes a couple of integers and returns whether their sum is a square
bool isSumASquare(int p, int q);

/* function definitions */
bool isSumASquare(int p, int q)
{
	int T[] = {4, 9, 16, 25};
	int sum(p + q);
	int i(0);
	while (i < 4)
	{
		if (sum == T[i])
		{
			return true;
		}
		else
		{
			i++;
		}
	}
	return false;
}

int main()
{
	// we are going to go through all distinct pairs of {1, ..., 17} and print the pair if the sum is a square
	int i, j; i = 1; j = 2;
	while (i < 17)
	{
		while (j < 18)
		{
			if (isSumASquare(i, j))
			{
				cout << i << ", " << j << endl;
			}
			j++;
		}
		i++; j = i + 1;
	}
	return 0;	
}

// From this printed list we deduce that the only solution is 16, 9, 7, 2, 14, 11, 5, 4, 12, 13, 3, 6, 10, 15, 1, 8, 17