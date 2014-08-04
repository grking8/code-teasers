#include <iostream>
#include <string>

using namespace std;

// function that reverses a string
void reverseString(string & A)
{
	string B = A;
	int i(0);
	while (i < A.size())
	{
		A[i] = B[A.size() - 1 - i];
		i++;
	}
}

// function that checks if two strings are equal
bool areStringsEqual(string & A, string & B)
{
	if (A.size() != B.size())
	{
		return false;
	}
	else
	{
		int i(0);
		while (i < A.size())
		{
			if (A[i] != B[i])
			{
				return false;
			}
			else
			{
				i++;
			}
		}
		return true;
	}
}
// function that checks if a string is a palindrome
bool isPalindrome(string & A)
{
	string B = A;
	reverseString(A);
	if (areStringsEqual(A, B))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* function that checks if a string has all unique characters. If the first member of an array is not repeated elsewhere in the array, then the array consists of unique members <=>
the array formed by removing the first member is unique. Thus we can use a recursive function */
// function that removes the first letter of a string
void removeFirstLetter(string & A)
{
	string B = A;
	A.resize(A.size() - 1);
	int i(0);
	while (i < A.size())
	{
		A[i] = B[i + 1];
		i++;
	}
}
// main function
bool isUnique(string & A)
{
	if (A.size() == 1)
	{
		return true;
	}
	else
	{
		//check to see the first letter is unique
		int i(1);
		while (i < A.size())
		{
			if (A[0] == A[i])
			{
				return false;
			}
			else
			{
				i++;
			}
		}
		removeFirstLetter(A);
		return isUnique(A);
	}
}
		

// function that does ROTI 13 on a string
// preliminary function that gives the position of a letter in the alphabet where the position of a is zero
int posInAlphabet(char c, int n) //n is always entered as zero
{
	string A = "abcdefghijklmnopqrstuvwxyz";
	if (c == A[n])
	{
		return n;
	}
	else
	{
		return posInAlphabet(c, n + 1);
	}
}
	
void roti13(string & A)
{
	string B = "abcdefghijklmnopqrstuvwxyz";
	int i(0);
	while (i < A.size())
	{
		int m(posInAlphabet(A[i], 0));
		A[i] = B[(m + 13) % 26];
		i++;
	}
}

/*function that given two strings checks if one is a permutation of the other.
firstly we notice that A is a permutation of B <=> each letter l of the alphabet 
appears the same number of times in A and B*/

// preliminary function which for a given string returns the number of occurrences of each letter eg "aabc" returns {2, 1, 1, 0, ..., 0}
int * encode(string & A)
{
	// we create an array of zeros of length 26
	int * T = new int [26];
	int i(0);
	while (i < 26)
	{
		T[i] = 0;
		i++;
	}
	i = 0;
	// now we fill in T
	while (i < A.size())
	{
		T[posInAlphabet(A[i], 0)]++;
		i++;
	}
	return T;
}
// main function
bool isPermutationStrings(string & A, string & B)
{
	int i(0);
	while (i < 26)
	{
		if (encode(A)[i] != encode(B)[i])
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}



// function that returns the nth number in the Fibonacci sequence
int Fib(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fib(n - 2) + Fib(n - 1);
	}
}

// function that sorts an array of integers in increasing order
// firstly we define a function that returns the the position of the minimum of an array of integers 
// for this, we use the function isMin below
bool isMin(int i, int * T, int n) // n is the length of the array T, T[i] is the entry that we are checking for
{
	int j(0);
	while (j < n)
	{
		if (T[i] > T[j])
		{
			return false;
		}
		else
		{
			j++;
		}
	}
	return true;
}

int minArrayOfIntegers(int * T, int n) // we use a pointer to avoid copying the array T
{
	int i(0);
	while (i < n)
	{
		if (isMin(i, T, n))
		{
			return i + 1; 
		}
		else
		{
			i++;
		}
	}
}
// the main function that sorts an array in increasing order
// we need also a function that swaps two entries in an array
void swap(int * T, int k, int l) // k and l the entries to swap
{
	int a(T[k - 1]);
	T[k - 1] = T[l - 1];
	T[l - 1] = a;
}

void sortArray(int * T, int n, int i) // n is the size of the array, i is the counter variable, i = 1
{
	if (i < n)
	{
		int * U = new int[n - i + 1]; // we create a new array truncated
		int j(0);
		while (j < n - i + 1)
		{
			U[j] = T[i - 1 + j];
			j++;
		}
		swap(T, i, minArrayOfIntegers(U, n - i + 1) + i - 1);
		delete U; U = 0; // we no longer need U so we free the memory
		sortArray(T, n, i + 1);
	}
}

// function to show an array of length n
template <typename T>
void showArray(T * A, int n)
{
	int i(0);
	while (i < n)
	{
		cout << A[i] << " ";
		i++;
	}
	cout << endl;
}	

// function that converts a non negative integer into a string eg 204 returns "two zero four" (for integers up to a trillion)
// preliminary functions
// function that raises a positive integer to a power and returns an integer
long int unsigned power(int a, int b) // we return a^b
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
int numberOfDigits(long int unsigned n, int i) //is the counter index, i = 1
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
// function that for a given non negative integer returns its digits in an array eg 2242 returns [2 2 4 2]
long int unsigned * digitsArray(long int unsigned n)
{
	// we create the array
	int d(numberOfDigits(n, 1));
	long int unsigned * T = new long int unsigned[d];
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
string T[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
// function that converts [2 2 4 2] into ["two" "two" "four" "two"]
string * convert(long int unsigned * U, int n) // n is the length of T
{
	string * V = new string[n];
	int i(0);
	while (i < n)
	{
		V[i] = T[U[i]];
		i++;
	}
	return V;
}



// function that for a given positive integer returns number of postive divisors
int numberOfDiv(int n)
{
	int i(1); int j(0); // j to count the number of divisors
	while (i < n + 1)
	{
		if (n % i == 0)
		{
			j++;
		}
		i++;
	}
	return j;
}
// function that returns an array of divisors of a given positive integer
int * divisors(int n)
{
	// creation of the array to fill
	int * T = new int[numberOfDiv(n)];
	int i(1); int j(0);
	while (i < n + 1)
	{
		if (n % i == 0)
		{
			T[j] = i;
			j++;
		}
		i++;
	}
	return T;
}

// function that returns the gcd of two positive integers. We use Euclid's algorithm and assume that a < b
int gcd(int a, int b)
{
	if (b % a == 0)
	{
		return a;
	}
	else
	{
		int r(b % a);
		return gcd(r, a);
	}
}
		
// function that lists all Pythagorean triples up to n
// function that tests if a triple is Pythagorean
bool isPythTriple(int a, int b, int c)
{
	if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b))
	{
		return true;
	}
	else
	{
		return false;
	}
}
// main function	
void listPythTriples(int n)
{
	int p(0); // p will be the number of triples at the end
	int i, j, k; i = 2; j = 3; k = 4;
	while (i < n + 1)
	{
		while (j < n + 1)
		{
			while(k < n + 1)
			{
				if (isPythTriple(i, j, k))
				{
					cout << i << " " << j << " " << k << endl;
					p++;
				}
				k++;
			}
			j++;
			k = j + 1;
		}
		i++; j = i + 1; k = i + 2;
	}
	cout << "The number of triples is " << p << endl;
}
// function that tests if a Pythagorean triple is primitive ie the triple is coprime <=> only common divisor is 1 <=> 
// there exists a couple coprime 
void listPrimPythTriples(int n)
{
	int p(0); // p will be the number of triples at the end
	int i, j, k; i = 2; j = 3; k = 4;
	while (i < n + 1)
	{
		while (j < n + 1)
		{
			while(k < n + 1)
			{
				if (isPythTriple(i, j, k) && (gcd(i, j) == 1 || gcd(i, k) == 1 || gcd(j, k) == 1))
				{
					cout << i << " " << j << " " << k << endl;
					p++;
				}
				k++;
			}
			j++;
			k = j + 1;
		}
		i++; j = i + 1; k = i + 2;
	}
	cout << "The number of triples that are primitive is " << p << endl;
}


int main()
{
	string A = "hello";
	cout << A << endl;
	reverseString(A);
	cout << A << endl;
	roti13(A);
	cout << A << endl;
	cout << Fib(8) << endl;
	int T[] = {1, -1, 4, 4, 5, 2, -13, -110, 5, 8, 18, 3, -17};
	sortArray(T, 13, 1);
	showArray(T, 13);
	string B = "shape"; string C = "phase";
	if (isPermutationStrings(B, C))
	{
		cout << "yes they are permutations" << endl;
	}
	else
	{
		cout << "no they are not" << endl;
	}
	string D = "dairymyriad";
	if (isPalindrome(D))
	{
		cout << "is a palindrome" << endl;
	}
	else
	{
		cout << "is not a palindrome" << endl;
	}
	if (isUnique(D))
	{
		cout << "is unique" << endl;
	}
	else
	{
		cout << "is not unique" << endl;
	}
	showArray(digitsArray(9264870000004), numberOfDigits(9264870000004, 1));
	showArray(convert(digitsArray(9264870000004), numberOfDigits(9264870000004, 1)), numberOfDigits(9264870000004, 1));
	listPrimPythTriples(100);
	showArray(divisors(8), numberOfDiv(8));
	cout << gcd(16, 40) << endl;
	

	
		
	return 0;
}