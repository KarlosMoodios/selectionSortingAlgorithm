// Selection sorting algorithm.
// Karl Moody 2019
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define SIZE 10000 /* Define the size of the data file here 
to avoid having to change the code in multiple areas */

void printit(void); // Function to print the array to the screen in format

int a[SIZE]; // Create integer array to hold the data

main(){

	FILE* f1;					// Create file pointer
	int x, i, j;				// Create variables
	DWORD starttime, endtime;	// Variables to store start and end times
	float totaltime;			// Variable for the total time

	// Open file for reading only
	if (SIZE == 10) fopen_s(&f1, "10.dat", "r");
	if (SIZE == 100) fopen_s(&f1, "100.dat", "r");
	if (SIZE == 1000) fopen_s(&f1, "1000.dat", "r");
	if (SIZE == 10000) fopen_s(&f1, "10000.dat", "r");

	// Save file to array
	for (i = 0; i < SIZE; i++) 
	{
		fscanf_s(f1, "%d\n", &x);
		a[i] = x; 
	}
	// Close the file
	fclose(f1);

	// Print the unsorted array
	cout << "The unsorted data in the array: \n";
	//printit();

	cout << "Press any key to begin sorting...\n";
	_getch();

	starttime = GetTickCount(); /* Get the start time from just
	before the sorting of the data takes place. */

	// Selection
	for (j = 0; j < SIZE; j++)
	{
		int min = a[j];	// Set a minimum to be the first element in the list
		int ms = j;		// Set minimum sorted value array index
		
		// Loop to check for minimum
		for (i = j + 1; i < SIZE; i++) 
		{
			if (a[i] < min)
			{
				min = a[i];
				ms = i; // Save the array position of the minimum slot
			}
		}// End of i loop

		// Store min value
		a[ms] = a[j];
		a[j] = min;

		//cout << " J = " << j << endl;
		//cout << " Min = " << min << endl;
		//printit();
		// _getch();
	} // End of j loop

	// Get finish time
	endtime = GetTickCount();

	// Print sorted array
	cout << "-- Sorted array --\n" << endl;
	//printit();

	// calc time
	totaltime = ((float)endtime - (float)starttime) / 1000.0; // calc total time in secs
	cout << "Total time taken to sort the data = " << totaltime << " mins.\n";
	_getch();
	
}//end of main



void printit(void) // print function to display the array in the console
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << " Array slot a[" << i+1 << "]=" << a[i] << endl;
	}
	cout << endl;
}