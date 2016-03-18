/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }
INPUTS: Two bank statements (array of transactions).
OUTPUT: Combined statement ordered by transaction date.
ERROR CASES: Return NULL for invalid inputs.
NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int cmpDate(char *date1, char* date2){
	int year1 = ((date1[6]) * 1000 + (date1[7]) * 100 + (date1[8]) * 10 + (date1[9]));
	int year2 = ((date2[6]) * 1000 + (date2[7]) * 100 + (date2[8]) * 10 + (date2[9]));
	int year = year1 - year2;
	if (year == 0)
	{
		int month1 = ((date1[3]) * 10 + (date1[4]));
		int month2 = ((date2[3]) * 10 + (date2[4]));
		int month = month1 - month2;
		if (month == 0)
		{
			int day1 = ((date1[0]) * 10 + (date1[1]));
			int day2 = ((date2[0]) * 10 + (date2[1]));
			int day = day1 - day2;
			return day;
		}
		else
		{
			return month;
		}
	}
	else
	{
		return year;
	}

}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction * mergedSortedArray = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	int transA = 0, transB = 0, transRes = 0;
	while (transA<ALen&&transB<BLen)
	{
		int res = cmpDate(A[transA].date, B[transB].date);
		if (res<0){
			mergedSortedArray[transRes] = A[transA];
			transA++;
			transRes++;
		}
		else if (res>0){
			mergedSortedArray[transRes] = B[transB];
			transB++;
			transRes++;
		}
		else
		{
			mergedSortedArray[transRes] = A[transA];
			transA++;
			transRes++;
			mergedSortedArray[transRes] = B[transB];
			transB++;
			transRes++;
		}
	}
	while (transA < ALen)
	{
		mergedSortedArray[transRes] = A[transA];
		transA++;
		transRes++;
	}
	while (transB<BLen)
	{
		mergedSortedArray[transRes] = B[transB];
		transB++;
		transRes++;
	}
	return mergedSortedArray;
}