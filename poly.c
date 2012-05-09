#include <stdio.h>
#include <stdlib.h>

/*function prototypes
design note: since we only care about the coefficients of polynomials
             I decided to use an array, and any zero indicates it is a 
	     place holder.
	     Additionally, operations are done right to left
	     to preserve x^3 + x^2 + x + 1.
*/

void add(int poly1[], int poly2[], int size1, int size2);
void multiply(int poly1[], int poly2[], int size1, int size2);
void derivative(int poly1[], int size1);
void integrate(int poly1[], int size1);

//this program tests the functions defined below for polynomials.
int main (int argc, char* argv[] ){
   int i;
   int arr1[4] = {1,2,3,4};
   int arr2[3] = {1,0,2};

   //print out array
   printf("\nArray1: ");
   for(i=0;i<4;i++) printf("[%d]", arr1[i]);
   printf("\nArray2: ");
   for(i=0;i<3;i++) printf("[%d]", arr2[i]);
   printf("\n\n");

   add(arr1, arr2, 4, 3);
   multiply(arr1, arr2, 4,3);
   derivative(arr1, 4);
   integrate(arr2, 3);
   printf("\n\nDONE\n");
}//end main


void add(int poly1[], int poly2[], int size1, int size2){
   int newSize=0, smSize=0, i,j;
   if (size1>size2){
      newSize = size1;
      smSize=size2;
   }
   else {
      newSize = size2;
      smSize = size1;
   }

   int results[newSize];
   for(i=0;i<newSize;i++) results[i] = 0;

   //calculate sum
   for (i=newSize-1, j=smSize-1;i>-1;i--, j--)
      results[i] = poly1[i] + poly2[j];

   //print results
   printf("\nArray1 + Array2 =  ");
   for (i=0;i<newSize;i++) 
      printf("[%d]", results[i]);
   printf("\n");
} //end add


void multiply(int poly1[], int poly2[], int size1, int size2){
   int newSize = size1 + size2 - 1, i, j;
   int results[newSize];
   
   for(i=0;i<newSize;i++) results[i] = 0;
   for (i=0;i<size1;i++)
      for(j=0;j<size2;j++)
         results[i+j] += poly1[i] * poly2[j];

  //print results
  printf("\nArray1 * Array2 = ");
  for (i=newSize-1;i>-1;i--) 
     printf("[%d]", results[i]);
  printf("\n");
} //end multiply


void derivative(int poly1[], int size1){
   int newSize = size1-1, i;
   int results[newSize];

   for(i=1;i<size1;i++)
      results[i-1] = poly1[i]*i;

   //print results
   printf("\n(d/dx)Array1 = ");
   for (i=newSize-1;i>-1;i--) 
      printf("[%d]", results[i]);
   printf("\n");
   
} //end derivative


void integrate(int poly1[], int size1){
   int newSize = size1-1, i;
   double results[newSize];

   for(i=0;i<size1;i++)
      results[i+1] = poly1[i]/(i+1.);

   //print results
   printf("\nIntegrate Array2 = ");
   for (i=newSize-1;i>-1;i--) 
      printf("[%f]", results[i]);
   printf("\n");
}//end integrate
