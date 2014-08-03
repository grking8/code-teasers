#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int x(1); int y(1); int z(1);
	while (x < 10)
	{
		while (y < 10)
		{
			while (z < 10)
			{
				if (99 * x + y - 80 * z == 0)
				{
					cout << x << y << z << " is a solution" << endl;
				}
				z++;
			}
			y++; z = 1;
		}
		x++; y = 1; z = 1;
	}
	return 0;
}