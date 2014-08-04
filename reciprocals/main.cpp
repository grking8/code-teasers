#include <iostream>
#include <string>

using namespace std;

/* the equation to solve is equivalent to b*c*d*e*f + a*c*d*e*f + a*b*d*e*f + a*b*c*e*f + a*b*c*d*f + a*b*c*d*e = a*b*c*d*e*f
we try first {2, 3, 4, 5, 6, 7} as solution because {1, ..., 6} cannot be a solution as 1/1 +... + 1/6 > 1
we then try {2, 3, 4, 5, 6, 8}, {2, 3, 4, 5, 6, 9}, ..., {2, 3, 4, 5, 6, 999} then {2, 3, 4, 5, 7, 8}, ..., {2, 3, 4, 5, 7, 999} then
{2, 3, 4, 5, 8, 9} and so on which allows us to test all possibilites under 1000. We hope that a solution exists in this set. If not we replace 1000
with 10000, 100000, etc. */
int main()
{
	int a, b, c, d, e, f;
	a = 2, b = 3, c = 4, d = 5, e = 6, f = 7;
	while (a < 1000)
	{
		while (b < 1000)
		{
			while (c < 1000)
			{
				while (d < 1000)
				{
					while (e < 1000)
					{
						while (f < 1000)
						{
							if (b * c * d * e * f + a * c * d * e * f + a * b * d * e * f + a * b * c * e * f + a * b * c * d * f + a * b * c * d * e == a * b * c * d * e * f)
							{
								cout << "A solution is " << a << ", " << b << ", " << c << ", " << d << ", " << e << ", " << f << ", ";
								return 0;
							}
							else
							{
								f++;
							}
						}
						e++;
						f = e + 1;
					}
					d++;
					e = d + 1;
				}
				c++;
				d = c + 1;
			}
			b++;
			c = b + 1;
		}
		a++;
		b = a + 1;
	}
}
	
	