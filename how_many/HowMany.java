/* we assume we have a function digitsAreDistinct
As ABCDEFGHIJ = x has all its digits distinct, we have 1023456789 <= x <= 9876543210
As 1023456789 is not divisible by 11111 we are going to go through (1023456789 / 11111
+ 1) * 11111 to 9876543210 at intervals of 11111 and we count the number of times the number 
has all its digits distinct */

import java.util.*;

public class HowMany
{
	// function that given a non negative integer returns the number of digits
	public static long nbDigits(long n, long a, long b) // n is the integer, a = 10, b = 1
	{
		if (n / a == 0)
		{
			return b;
		}
		else
		{
			return nbDigits(n, a * 10, b + 1);
		}
	}
	
	// function that given a non negative integer returns an array filled with its digits eg 123 returns the array [1 2 3]
	public static int [] arrayDigits(long n)
	{
		long p = nbDigits(n, 10, 1);
		int []result = new int[(int) p];
		int i = 0;
		long q = 1; // to calculate the powers of 10 we use a running product
		while (i < p)
		{
			q *= 10;
			result[(int) (p - 1 - i)] = (int) ((n % q) / (q / 10));
			i++;
		}	
		return result;
	}
	
	public static boolean digitsAreDistinct(long n)
	{
		// array of 10 zeros
		int []zeros = new int [10];
		int i;
		for (i = 0; i < 10; i++)
		{
			zeros[i] = 0;
		}
		for (i = 0; i < 10; i++)
		{
			zeros[arrayDigits(n)[i]]++;
		}
		for (i = 0; i < 10; i++)
		{
			if (zeros[i] != 1)
			{
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] arg)
	{
		
		int result = 0; long i; long p = (1023456789 / 11111 + 1) * 11111; long q = 9876543211L;
		for (i = p; i < q; i += 11111)
		{
			if (digitsAreDistinct(i))
			{
				result++;
			}
		}
		System.out.println("The solution is " + result);
	}	
}			
			