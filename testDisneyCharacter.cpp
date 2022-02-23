/*
*	FILE			: testDisneyCharacter.cpp
*	PROJECT			: DisneyCharacter
*	NAME			: Chowon Jung
*	FIRST VERSION	: 2019-02-09
*	DESCRIPTION		: This file is the test harness for the DisneyCharacter class practice.
*					  This test harness contains :
*					  1. Header file														: Line 18
*					  2. Main function														: Line 22
*					  3. Two instantiation of the class										: Line 25
*					  4. One class data member copy between two classes instantiated in #1	: Line 31
*					  5. Two dumping of class data instantiated in #1						: Line 35
*					  6. One class data member reset instantiated in #1						: Line 41
*					  7. And the verification dumping of #4									: Line 44
*/


/* Header */
#include "DisneyCharacter.h"


/* Main */
void main(void)
{
	//Instantiation test
	cout << "TESTING: Instantiating < mickey > ...\n";
	DisneyCharacter mickey("Mickey", "1929-01-01", 100, 'M');
	cout << "TESTING: Instantiating < minnie > ...\n";
	DisneyCharacter minnie("Minnie", "1930-01-01");

	//Equal movie number setter test
	cout << "TESTING: Setting minnie's Number of Movies as the same as mickey's ...\n";
	minnie.SameMovies(mickey);

	//Dumping test
	cout << "TESTING: Dumping out <mickey> ...\n";
	mickey.ShowInfo();
	cout << "TESTING: Dumping out <minnie> ...\n";
	minnie.ShowInfo();

	//Place reset test
	cout << "TESTING: Setting minnie's Place as the Epcot Park ...\n";
	minnie.PlaceCharacter('E');
	//Verify reset test
	cout << "TESTING: Dumping out <minnie> to verify the change ...\n";
	minnie.ShowInfo();
}