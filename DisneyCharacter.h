/*
*	FILE			: DisneyCharacter.h
*	PROJECT			: DisneyCharacter
*	NAME			: Chowon Jung
*	FIRST VERSION	: 2019-02-09
*	DESCRIPTION		: This file is the header file for the project DisneyCharacter.
*					  This file contains :
*					  1. One Pragma								: Line 15
*					  2. Two Libraries and one namespace		: Line 19
*					  3. Thirty-One Constants					: Line 25
*					  4. DisneyCharacter Class definition		: Line 62
*/


/* Pragma */
#pragma once


/* Libraries */
#include <iostream>
#include <string>
using namespace std;


/* Constants for Date Value Validation Start */
#define IF_ODD 2
#define ODD 1
#define FOUR_YEARS 4
#define HUND_YEARS 100
#define FOURHUND_YEARS 400
#define FEBRUARY 2
#define YEAR_NUM 4
#define MONTH_NUM 2
#define DAY_NUM 2
#define WHERE_MON 5
#define WHERE_DAY 8
#define DAYS_FEB 28
#define DAYS_LEAP 29
#define DAYS_31 31
#define DAYS_30 30
#define MAX_MONTH 12
#define AUGUST 8
/* Constants for Date Value Validation End */
/* Other Constants */
#define ZERO 0
#define START 0
#define WHERE_BAR_1 4
#define WHERE_BAR_2 7
#define MAX_NAME_LEN 50
#define MAX_DATE_LEN 10
#define OMIT_NAME_LEN 46
#define OMIT_SIGN " ..."
#define BAR "-"
#define BLANK ""
#define PARK_NUM 6
#define NOT_PLACED 5
const char parkInitial[PARK_NUM] = { 'M', 'S', 'A', 'E', 'C', 'N' };
const string parkName[PARK_NUM] = { "Magic Kingdom", "Disney Studios", "Animal Kingdom",
"Epcot", "California Adventure", "Not Placed" };


/* ****************************** Class ****************************** */
class DisneyCharacter
{
private:
	/* Data members */
	string name;						//Name of the character: maximum 50 characters
	string creationDate;				//Date of the creation of the character in format of yyyy-mm-dd
	int numMovies;						//Number of the movies the character has been in: minimum value of 0
	char whichPark;						//Place where the character can be found
										/* Accessors */
	string GetName(void);				//Name getter
	string GetCreationDate(void);		//Creation Date getter
	int GetNumMovies(void);				//Number of movies in getter
	char GetWhichPark(void);			//Place can be found getter
										/* Mutators */
	bool SetNumMovies(int numMovies);	//Number of movies setter
	bool SetWhichPark(char whichPark);	//Place can be found setter

public:
	/* Constructors */
	DisneyCharacter(string newName, string newCreationDate, int newNumMovies, char newWhichPark);
	DisneyCharacter(string newName, string newCreationDate);
	/* Destructor */
	~DisneyCharacter();

	/* ****************************** Other required public methods ****************************** */
	/*
	*	Method		: ShowInfo()
	*	Purpose		: This method reads and prints out the information of the character for user.
	*	Parameters	: void
	*	Return		: void
	*	Body		: DisneyCharacter.cpp (Line: 356)
	*/
	void ShowInfo(void);

	/*
	*	Method		: PlaceCharacter()
	*	Purpose		: This method attempts to reset the place can be found of the character.
	*	Parameters	: char newWhichPark	: single character indicates which park the character will be in
	*	Return		: void
	*	Body		: DisneyCharacter.cpp (Line: 392)
	*/
	void PlaceCharacter(char newWhichPark);

	/*
	*	Method		: SameMovies()
	*	Purpose		: This method attemps to copy the number of movie has been in
	*				  of the character passed in to the invoking character.
	*	Parameters	: DisneyCharacter& anotherCharacter : DisneyCharacter object holds the data to be copied
	*	Return		: void
	*	Body		: DisneyCharacter.cpp (Line: 422)
	*/
	void SameMovies(DisneyCharacter& anotherCharacter);
};