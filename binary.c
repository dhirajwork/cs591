#include<stdio.h>
#include<stdlib.h>


int non_rec(int x, int *A)
{
	int l=0,u=4;
	
	while(l<=u)
	{
		int mid = (u-l)/2;
		
		if(x == A[mid])
			return mid;
		
		else if(x < A[mid])
		{
			u = mid-1;
		}
		
		else if(x > A[mid])
		{
			l = mid + 1;
		}
	}
	
	return -1;
}

int rec(int x, int *A)
{
	static int l=0, u=4;
	
	int mid = (u-l)/2;
	
	if(x==A[mid])
		return mid;
	else if(x<A[mid])
		u = mid - 1;
	else if(x>A[mid])
		l = mid + 1;
	
	if(l<=u)
		rec(x, A);
}

void main()
{
	int A[] = { 1,2,3,4,5 };
	int pos = non_rec(3, A);
	int pos2 = rec(3, A);

	printf("\nRecursive:- %d", pos2);
	printf("\nNon-recursive:- %d\n\n", pos);
}
