/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2
INPUTS: Integer array and length of the array.
OUTPUT: Element that occurs only once.
ERROR CASES: Return -1 for invalid inputs.
NOTES:
*/
#include<stdio.h>
void quicksort(int *str, int first, int last){
	int pivot, j, temp, i;

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (str[i] <= str[pivot] && i<last)
				i++;
			while (str[j]>str[pivot])
				j--;
			if (i<j){
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}

		temp = str[pivot];
		str[pivot] = str[j];
		str[j] = temp;
		quicksort(str, first, j - 1);
		quicksort(str, j + 1, last);

	}
}
int findSingleOccurenceNumber(int *A, int len) {
	int i;
	if (A == NULL)
		return -1;
	quicksort(A, 0, len - 1);
	for (i = 0; i < len; i = i + 3)
	{
		if (!(A[i] == A[i + 1] && A[i + 1] == A[i + 2]))
		{
			return A[i];
		}
	}

}

