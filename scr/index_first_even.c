#include <stdio.h>  
#include <stdlib.h>  
#define N 100  
 
int index_first_even(int* array) { 
 int first_index_even; 
 for (int i = 0; i < N; i++) { 
  if (abs(array[i]) % 2 == 0) { 
   first_index_even = i; 
   break; 
  } 
 } 
 return first_index_even; 
} 
