/*
*	FILE			: DisneyCharacter.cpp
*	PROJECT			: DisneyCharacter
*	NAME			: Chowon Jung
*	FIRST VERSION	: 2019-02-09
*	DESCRIPTION		: This file contains all the method bodies of the DisneyCharacter class.
*					  The included methods are:
*					  1. Header file							: Line 17
*					  2. Two overloaded constructors			: Line 21
*					  3. One destructor							: Line 286
*					  4. Four accessors for each attributes		: Line 293
*					  5. Two mutators							: Line 315
*					  6. Three public methods					: Line 355
*/


/* Header */
#include "DisneyCharacter.h"


/* ****************************** Constructor ****************************** */
DisneyCharacter::DisneyCharacter(string newName, string newCreationDate, int newNumMovies, char newWhichPark)
{
	char stringYear[YEAR_NUM], stringMonth[MONTH_NUM], stringDay[DAY_NUM];
	int year, month, day = ZERO;
	bool validDate = false;
	int parkSeeker = 0;

	//Format name in length
	if ((newName.length()) > MAX_NAME_LEN)
	{
		newName.erase(OMIT_NAME_LEN, (newName.length()) - OMIT_NAME_LEN);
		newName.append(OMIT_SIGN);
	}
	name.insert(START, newName);

	//Check creation date sanity
	//Check total length
	if ((newCreationDate.length()) == MAX_DATE_LEN)
	{
		//Check if in format
		if (((newCreationDate.find(BAR, START)) == WHERE_BAR_1) &&
			((newCreationDate.find(BAR, WHERE_BAR_1 + 1)) == WHERE_BAR_2))
		{
			/* --------------- Date Sanity Check Start --------------- */
			// Prepare for date sanity check
			if ((newCreationDate._Copy_s(stringYear, YEAR_NUM, YEAR_NUM, START)) != NULL)
			{
				year = atoi(stringYear);
				if ((newCreationDate._Copy_s(stringMonth, MONTH_NUM, MONTH_NUM, WHERE_MON)) != NULL)
				{
					month = atoi(stringMonth);
					if ((newCreationDate._Copy_s(stringDay, DAY_NUM, DAY_NUM, WHERE_DAY)) != NULL)
					{
						day = atoi(stringDay);
						//Year Month sanity check
						if (((ZERO < month) &&
							(MAX_MONTH >= month)) &&
							(ZERO < year))
						{
							//If odd month
							if ((month % IF_ODD) == ODD)
							{
								//Jan, Mar, May, Jul have 31 days
								if (month < AUGUST)
								{
									if ((ZERO < day) &&
										(DAYS_31 >= day))
									{
										validDate = true;
									}
								}
								//Sep, Nov have 30 days
								else
								{
									if ((ZERO < day) &&
										(DAYS_30 >= day))
									{
										validDate = true;
									}
								}
							}
							else
							{
								//If even month
								if (month < AUGUST)
								{
									//If Feb
									if (FEBRUARY == month)
									{
										//If leap year
										if ((((year % FOUR_YEARS) == ZERO) &&
											((year % HUND_YEARS) != ZERO)) ||
											((year % FOURHUND_YEARS) == ZERO))
										{
											if ((ZERO < day) &&
												(DAYS_LEAP >= day))
											{
												validDate = true;
											}
										}
										//If not leap year
										else if ((ZERO < day) &&
											(DAYS_FEB > day))
										{
											validDate = true;
										}
									}
									//Apr, Jun has 30 days
									else if ((ZERO < day) &&
										(DAYS_30 >= day))
									{
										validDate = true;
									}
								}
								else
								{
									//Aug, Oct, Dec has 31 days
									if ((ZERO < day) &&
										(DAYS_31 >= day))
									{
										validDate = true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	/* --------------- Date Sanity Check End --------------- */
	//Set creation date
	if (validDate == true)
	{
		creationDate = newCreationDate;
	}
	else
	{
		creationDate = BLANK;
	}

	//Check and set number of movie
	if (newNumMovies > ZERO)
	{
		numMovies = newNumMovies;
	}
	else
	{
		numMovies = ZERO;
	}

	//Check and set which park in
	while (newWhichPark != parkInitial[parkSeeker])
	{
		parkSeeker++;
		if (parkSeeker == NOT_PLACED)
		{
			break;
		}
	}
	if (parkSeeker >= NOT_PLACED)
	{
		whichPark = parkInitial[NOT_PLACED];
	}
	else
	{
		whichPark = parkInitial[parkSeeker];
	}
}


DisneyCharacter::DisneyCharacter(string newName, string newCreationDate) : numMovies(ZERO), whichPark(parkInitial[NOT_PLACED])
{
	char stringYear[YEAR_NUM], stringMonth[MONTH_NUM], stringDay[DAY_NUM];
	int year, month, day = ZERO;
	bool validDate = false;

	//Format name in length
	if ((newName.length()) > MAX_NAME_LEN)
	{
		newName.erase(OMIT_NAME_LEN, (newName.length()) - OMIT_NAME_LEN);
		newName.append(OMIT_SIGN);
	}
	name.insert(START, newName);

	//Check creation date sanity
	//Check total length
	if ((newCreationDate.length()) == MAX_DATE_LEN)
	{
		//Check if in format
		if (((newCreationDate.find(BAR, START)) == WHERE_BAR_1) &&
			((newCreationDate.find(BAR, WHERE_BAR_1 + 1)) == WHERE_BAR_2))
		{
			/* --------------- Date Sanity Check Start --------------- */
			// Prepare for date sanity check
			if ((newCreationDate._Copy_s(stringYear, YEAR_NUM, YEAR_NUM, START)) != NULL)
			{
				year = atoi(stringYear);
				if ((newCreationDate._Copy_s(stringMonth, MONTH_NUM, MONTH_NUM, WHERE_MON)) != NULL)
				{
					month = atoi(stringMonth);
					if ((newCreationDate._Copy_s(stringDay, DAY_NUM, DAY_NUM, WHERE_DAY)) != NULL)
					{
						day = atoi(stringDay);
						//Year Month sanity check
						if (((ZERO < month) &&
							(MAX_MONTH >= month)) &&
							(ZERO < year))
						{
							//If odd month
							if ((month % IF_ODD) == ODD)
							{
								//Jan, Mar, May, Jul have 31 days
								if (month < AUGUST)
								{
									if ((ZERO < day) &&
										(DAYS_31 >= day))
									{
										validDate = true;
									}
								}
								//Sep, Nov have 30 days
								else
								{
									if ((ZERO < day) &&
										(DAYS_30 >= day))
									{
										validDate = true;
									}
								}
							}
							else
							{
								//If even month
								if (month < AUGUST)
								{
									//If Feb
									if (FEBRUARY == month)
									{
										//If leap year
										if ((((year % FOUR_YEARS) == ZERO) &&
											((year % HUND_YEARS) != ZERO)) ||
											((year % FOURHUND_YEARS) == ZERO))
										{
											if ((ZERO < day) &&
												(DAYS_LEAP >= day))
											{
												validDate = true;
											}
										}
										//If not leap year
										else if ((ZERO < day) &&
											(DAYS_FEB > day))
										{
											validDate = true;
										}
									}
									//Apr, Jun has 30 days
									else if ((ZERO < day) &&
										(DAYS_30 >= day))
									{
										validDate = true;
									}
								}
								else
								{
									//Aug, Oct, Dec has 31 days
									if ((ZERO < day) &&
										(DAYS_31 >= day))
									{
										validDate = true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	/* --------------- Date Sanity Check End --------------- */
}


/* ****************************** Destructor ****************************** */
DisneyCharacter::~DisneyCharacter()
{
	cout << name << " destroyed.\n\n";
}


/* ****************************** Accessors ****************************** */
string DisneyCharacter::GetName(void)
{
	return name;
}
string DisneyCharacter::GetCreationDate(void)
{
	return creationDate;
}
int DisneyCharacter::GetNumMovies(void)
{
	return numMovies;
}
char DisneyCharacter::GetWhichPark(void)
{
	return whichPark;
}


/* ****************************** Mutators ****************************** */
bool DisneyCharacter::SetNumMovies(int newNumMovies)
{
	if (newNumMovies >= ZERO)
	{
		numMovies = newNumMovies;
		return true;
	}
	else
	{
		return false;
	}
}

bool DisneyCharacter::SetWhichPark(char newWhichPark)
{
	int parkSeeker = 0;
	//Check and set which park in
	while (newWhichPark != parkInitial[parkSeeker])
	{
		parkSeeker++;
		if (parkSeeker == PARK_NUM)
		{
			break;
		}
	}
	//Set not if invalid park
	if (parkSeeker >= PARK_NUM)
	{
		return false;
	}
	//Set as it is if valid park
	else
	{
		whichPark = parkInitial[parkSeeker];
		return true;
	}
}


/* ****************************** Other required public methods ****************************** */
void DisneyCharacter::ShowInfo(void)
{
	int parkSeeker = 0;
	char park = GetWhichPark();

	//Print in format
	printf("\n");
	printf("%-35s", "   Name of the Character");
	cout << ": " << GetName() << "\n";
	printf("%-35s", "   Birthday of the Character");
	cout << ": " << GetCreationDate() << "\n";
	printf("%-35s", "   Number of Movies has been in");
	cout << ": " << GetNumMovies() << "\n";
	printf("%-35s", "   Can be found in");
	cout << ": ";

	//Print exact park name
	while (park != parkInitial[parkSeeker])
	{
		parkSeeker++;
		if (parkSeeker == NOT_PLACED)
		{
			break;
		}
	}
	if (parkSeeker >= NOT_PLACED)
	{
		cout << parkName[NOT_PLACED] << "\n\n";
	}
	else
	{
		cout << parkName[parkSeeker] << "\n\n";
	}
}


void DisneyCharacter::PlaceCharacter(char newWhichPark)
{
	int parkSeeker = 0;
	char park = 0;

	//Set and Notice Park name
	if ((SetWhichPark(newWhichPark)) == true)
	{
		cout << "\n   *** Now " << GetName() << " can be found in ";
	}
	//Notice that the place is not reset if invalid park
	else
	{
		printf("\n   *** Oops, that was an Invalid New Place :P \n");
		cout << "   *** Now " << GetName() << " is still living in ";
	}
	//Print exact park name
	park = GetWhichPark();
	while (park != parkInitial[parkSeeker])
	{
		parkSeeker++;
		if (parkSeeker == NOT_PLACED)
		{
			break;
		}
	}
	cout << parkName[parkSeeker] << " :) \n\n";
}


void DisneyCharacter::SameMovies(DisneyCharacter& anotherCharacter)
{
	//Set and notice the new number of movies
	if ((SetNumMovies(anotherCharacter.GetNumMovies())) == true)
	{
		cout << "\n   *** Now the Number of Movies " << GetName() << " had been in is " << GetNumMovies() << " :)\n\n";
	}
	//Notice if failed
	else
	{
		printf("\n   *** Oops, that was an Invalid New Number :P \n");
		cout << "   *** The Number of Movies " << GetName() << " had been in is still \"" << GetNumMovies() << "\"!\n\n";
	}
}