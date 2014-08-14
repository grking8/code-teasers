/* we are looking for (x,y) in {1, 2, ..., 65502}^2 s.t. x != y,
xy + x + y = 1 + ... + 65502 */

import java.util.*;

public class ProductAndSum
{
	public static int f(int x, int y)
	{
		return x * y + x + y;
	}
	
	public static int g(int n)
	{
		int sum = 0;
		int i;
		for (i = 1; i < n + 1; i++)
		{
			sum += i;
		}
		return sum;
	}
	
	public static void main(String[] arg)
	{
		int i, j; i = 1; j = 2;
		int k = g(65502);
		while (i < 65502)
		{
			while (j < 65503)
			{
				if (f(i, j) == k)
				{
					System.out.println("The solution is (" + i + ", " + j + ")");
				}
				j++;
			}
			i++; j = i + 1;
		}
	}
}