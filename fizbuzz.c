#include <stdio.h>

/* This is a short program that prints out the numbers 1-100 (inclusive) as required by the prompt. 
It is formatted so that the output is cleanly indented.

The program is written in C and is compiled with a gcc compiler.
*/

int main (){
   int i, max=100;			//for extensibility
 
   for (i=1; i<=max;i++){
	if (i<10)			//ensures output is all lined up
	   printf("  ");	
	else if (i<100 && i>9)
	   printf(" ");
					
	if ( (i%3 == 0) && (i%5==0) )
	   printf("%d FizzBuzz\n", i);	//in the case of divisible by 3 AND 5
	else if ( i%3 == 0 )
	   printf("%d Fizz\n", i);	//in the case of divisible by 3 ONLY
        else if( i%5 == 0 )
	   printf("%d Buzz\n", i);	//in the case of divisible by 5 ONLY
	else 
	   printf("%d\n", i);		//ONLY prints number
   }//end for
}//end main
