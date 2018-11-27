#include<stdio.h>
#include<stdlib.h>

void merge(int *L, int l, int *R, int r, int *A)
{
	int i=0, j=0, k=0;

	while(i<l && j<r)
	{
		if(L[i] <= R[j])
		{
			A[k++] = L[i++]; 
		}
		else
		{
			A[k++] = R[j++];
		}
	}

	while(i<l)
	{
		A[k++] = L[i++];
	}

	while(j<r)
	{
		A[k++] = R[j++];
	}
}

void mergesort(int *A, int n)
{
	if(n==1)
		return;
	else
	{
		int mid = n/2;
		int l = mid;
		int r = n-mid;
		int i;

		int *L = (int*)malloc(sizeof(int)*l);
		int *R = (int*)malloc(sizeof(int)*r);

		for(i=0; i<mid; i++)
		{
			L[i] = A[i];
		}

		for(i=mid; i<n; i++)
		{
			R[i-mid] = A[i];
		}

		mergesort(L, l);
		mergesort(R, r);
		merge(L, l, R, r, A);
	}
}

void display(int *a, int n)
{
	for(int i=0; i<n; i++)
		printf("%d, ", a[i]);
}

void main()
{
	int A[] = { 3,5,4,1 };
	mergesort(A, 4);
	display(A, 4);
}

