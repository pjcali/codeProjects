#include <stdio.h>
#include <stdlib.h>

int bsR(int a[], int n, int x);

int main(int argc, char *argv[])
{
   //make sorted array
   int s = 1000;
   int key = 42;
   int arr[s];
   int i;
   //printf("The original array:\n");
   for (i=0; i<s; i++)
   {  // assign array and print
      arr[i]=i;
      //printf("[%d]", arr[i]);
   }
   int j;
   printf("Don't worry, the program is still running...\n\n");
   if ( bsR(arr, s, key) > 0) {
      //test program
      for(j=0; j<atoi(argv[1]); j++)
         for(i=0; i<s; i++) if(bsR(arr,s,i) != i) printf("\nERROR\n");
      printf("DONE.\n\n");
   }
   else printf("The program is broken.");  
 
}//end main

int bsR(int a[], int size, int key)
{
   int low=0, high=size-1, mid=high+low/2;
   if(low > high) 
   { //printf("\nThe key was...%d, and isn't in the array!\n\n", key); 
     return -1;	//NOT in array
   } else 
   {
      if (key == a[mid]) 
      { //printf("\nThe key was...%d, and found at index: %d\n", key, mid); 
        return mid; }
      else if (key>a[mid]) bsR(a, (high-low), key);
      else bsR(a, (mid-low), key);
   }//end else
}//end bs
