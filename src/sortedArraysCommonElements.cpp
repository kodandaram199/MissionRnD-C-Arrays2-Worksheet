/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int cmpdate(char *date1, char* date2);

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int SIZE;
	if (A == NULL || B == NULL)
		return NULL;
	if (ALen > BLen)
	{
		SIZE = ALen;
	}
	else
	{
		SIZE = BLen;
	}
	struct transaction * cmnelems = (struct transaction *)malloc(sizeof(struct transaction)*SIZE);
	int ATrans, BTrans, commonElementIndex=0;
	for (ATrans = 0; ATrans < ALen; ATrans++)
	{
		for (BTrans = 0; BTrans < BLen; BTrans++)
		{	
			int res = cmpdate(A[ATrans].date, B[BTrans].date);
			if (res==1)
			{
				cmnelems[commonElementIndex++] = A[ATrans];

			}
		}
	}
	if (commonElementIndex == 0)
	{
		return NULL;
	}

	return cmnelems;
}