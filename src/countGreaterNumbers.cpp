/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int cmpdate(char *date1, char* date2){
	int i = 0;
	while (date1[i++] != '\0')
		if (date1[i] != date2[i])
			return 0;
	return 1;
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0, count = 0,compare=0;
	for (i = 0; i < len; i++){
		int resdate = cmpdate(Arr[i].date, date);
		if (resdate == 1){
			compare = 1;
			continue;
		}
		if (resdate == 0 && compare == 1)
			count++;
	}
	return count;
}
