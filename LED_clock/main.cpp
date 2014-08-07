#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* funtion prototypes */
// function that given the number of minutes elapsed since midnight returns the number of segments lit up on the LED screen
int	nbSegments (int n); 

/* function definitions */
int nbSegments (int n)
{
	// we get the number of hours
	int nbHrs(n / 60);
	// the number of minutes
	int nbMins(n % 60);
	// we get the number of segments of the hours number
	// for this we need an array that gives the number of segments for each digit eg zero has 6 segments
	int T[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int nbSegmentsHrs(0);
	if (nbHrs < 10) // as the leading digit is blank if not used
	{
		nbSegmentsHrs = T[nbHrs];
	}
	else
	{
		nbSegmentsHrs = T[nbHrs / 10] + T[nbHrs % 10];
	}
	// we get the number of segments of the minutes number
	int nbSegmentsMins(T[nbMins / 10] + T[nbMins % 10]);
	return nbSegmentsHrs + nbSegmentsMins;
}

int main()
{
  	
	int supMin(24 * 60 - 1); // we go through all the minutes from midnight to 23.59 and take the borne sup of the set {minutes elasped since midnight}
	int i(0); // counter variable for the minutes elapsed since midnight
	int maxSegments(0); // running max variable with initial value 0 as regardless of the time, at least one segment will be lit up
	int maxMinutes(0); // the number of minutes at which the max number of segments occurred
	while (i < supMin + 1)
	{
		if (nbSegments(i) > maxSegments)
		{
			maxSegments = nbSegments(i); 
			int j(i); // dummy variable that allows us to copy over the value of i to maxMinutes
			maxMinutes = j;
		}
		i++;
	}
	// we want the period of time between when the room is at its lightest to its darkest
	// it is at its darkest at 1.11 (simple verification)
	int solutionInMins(fabs(71 - maxMinutes));
	cout << "The solution is " << solutionInMins / 60 << " hours and " << solutionInMins % 60 << " minutes" << endl;
	
	return 0;
}