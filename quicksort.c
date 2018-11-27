#include<stdio.h>
#include<stdlib.h>

int partition(int*, int, int);
void swap(int*, int*);

void quicksort(int* A, int start, int end)
{
	if(start<end)
	{
		int pIndex = partition(A, start, end);
		quicksort(A, start, pIndex-1);
		quicksort(A, pIndex+1, end);	
	}
}


int partition(int* A, int start, int end)
{
	int pivot = A[end];
	int i, pIndex = start;

	for(i=start; i<end; i++)
	{
		if(A[i] <= pivot)
		{
			swap(&A[i], &A[pIndex]);
			pIndex = pIndex + 1;
		}
	}

	swap(&A[i], &A[pIndex]);
	return pIndex;
}

void swap(int* x, int* y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void display(int* A)
{
	for(int i=0;i<4;i++)
	{
		printf("%d, ", A[i]);
	}
}

void main()
{
	int A[] = { 3,5,4,1 };

	quicksort(A, 0, 3);
	display(A);
}

