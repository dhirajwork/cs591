/*
ALGORITHM:

MATRIX-CHAIN-ORDER(p)
1 n  length[p] - 1 
2 for i  1 to n
3      do m[i, i]  0 
4 for l  2 to n
5      do for i  1 to n -  l + 1 
6             do j  i + l-1 
7                m[i, j] 
8                for k  i to j - 1 
9                    do q m[i, k] + m[k + 1,j] +pi - 1pkpj
10                       if q < m[i, j]
11                          then m[i, j]  q 
12                               s[i, j]  k 
13 return m and s

*/

#include<stdio.h>
#include<stdlib.h>

int MatrixChainOrder(intp[], intn) 
{    
	int m[n][n];     
	int i, j, k, L, q;         
	for(i=1; i<n; i++)         
		m[i][i] = 0;     // L is chain length.     
	for(L=2; L<n; L++)    
	{        		
		for(i=1; i<n-L+1; i++)         
		{             
			j = i+L-1;             
			m[i][j] = INT_MAX;             
			for(k=i; k<=j-1; k++)             
			{                 
				// q = cost/scalar multiplications                 
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];                 
				if(q < m[i][j])                     
					m[i][j] = q;             
			}         
		}     
	}
	     
	return m[1][n-1]; 
} 

int main() 
{     
	int arr[] = {1, 2, 3, 4};     
	int size = sizeof(arr)/sizeof(arr[0]);     
	printf("Minimum number of multiplications is %d ",                        
	MatrixChainOrder(arr, size));     
	getchar();     
	return 0; 
}

