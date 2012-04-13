#include <stdio.h>
#include <stdlib.h>

long int bsI(long int a[], long int n, long int x);

long int main(long int argc, char *argv[])
{
   //make sorted array
   long int s = 1000;
   long int key = 42;
   long int arr[s];
   long int i;
  // printf("The original array:\n");
   for (i=0; i<s; i++)
   {  // assign array and print
      arr[i]=i;
      //printf("[%ld]", arr[i]);
   }
   
   int j;
   printf("Don't worry, the program is still running...\n\n");
   if ( bsI(arr, s, key) > 0) {
      //test program
      for(j=0; j<atoi(argv[1]); j++)
         for(i=0; i<s; i++) if(bsI(arr,s,i) != i) printf("\nERROR\n");
      printf("DONE.\n\n");
   }
   else printf("The program is broken.");  
 
}//end main

long int bsI(long int a[], long int size, long int key)
{
   long int low=0, hi=size-1;
   long int mid;
   while(low <= hi)
   {
      mid=(hi+low)/2;
      if(a[mid] == key) {
         //printf("Key %ld found at index: %ld\n\n", key, mid);
         return mid;
      }
      else if (a[mid] < key) low = mid+1;
      else hi = mid-1;

   }//end while loop

   //if all else fails, its not in the array, return -1.
   return -1;
}//end bs
