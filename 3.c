#include <stdio.h>
#include <stdlib.h>

int reduce(int a[], int size);

int main(){
	int s = 16;
	int arr[] = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};
	int r;
	
	printf("the original array:\n");
	for(r=0; r<s; r++)
	   printf("[%d] ", arr[r]);

	int ns = reduce(arr, s);
	printf("\n\nDONE.\n\n");
}//end main

int reduce(int a[] , int size){
	int newSize=0, i, first=0, second=0, third=0;	

	//step 1: find the 3 largest values in array
	for (i=0; i <size; i++)
	{
	   if (a[i]>first) { 
		third=second; 
		second=first; 
		first=a[i]; 
		}
	   else if (a[i]>second && a[i] != first) { 
		third=second; 
		second=a[i]; 
	   }
	   else if (a[i] > third && a[i] != second && a[i] != first){ 
		third = a[i]; 
	   }
	}//end for
	
	//step 2: copy remaining elements into new array
	
	for(i=0; i<size; i++)
	{
	   if (a[i] != first && a[i] != second && a[i] != third) newSize++;
	}//end for
	
	int b[newSize];
	int k=0;
	for(i=0; i<size; i++)
	{
	   if (a[i] != first && a[i] != second && a[i] != third){ //ok to put in new array
	     b[k]=a[i];
	     k++;
	   }
	}//end for

	a = malloc (newSize);
	a=b;
	
	printf("\ntop 3 values: %d, %d, %d\n", first, second, third);
	printf("\nthe resulting array is...\n");
	for(i=0; i<newSize; i++)
	{
	   printf("[%d] ", a[i]);
	}//end for

	return newSize;
}//end reduce
