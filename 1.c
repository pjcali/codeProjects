#include <stdio.h>
#include <stdlib.h>

int maxLen(int b[], int n);

int main()
{
    int ans=0;
    int n = 21;
    int a[] = {1,1,1,1,1,1,1,1,1,1,2,3,3,5,6,6,6,6,7,9,9};
    int i;
    for (i=0; i<n; i++) printf("[%d]", a[i] );
    ans = maxLen(a, n);
    printf("\n\nnThe longest sequence of numbers is: %d. \n\nDone.\n\n", ans);
    return 0;
}

int maxLen(int b[], int n) //finds the sequence with the longest list. Assumption: array is sorted.
{
    int temp = b[0];
    int length=0, oldLength=0;
    int i;

    for(i=0; i<n; i++)
    {//	printf("i=%d\n", i);
        if (b[i] == temp){ // if next element is same as current
            length++;	     // increment counter
        }
	else if (b[i+1] > temp && b[i-1] ==temp){
	   temp = b[i];	// assign new key
	   if (length >= oldLength){
       	      //printf("%d Old Length", oldLength);
              //printf("%d New Length", length);
	      oldLength=length;		//keep the longer length
	      length=0;
	   }
	}   
    }//end for loop

    if (oldLength > length) //return the biggest length
	length = oldLength;
    return length;
}//end maxLen

