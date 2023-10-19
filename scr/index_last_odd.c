#include <stdio.h>  
#include <stdlib.h>  
#define N 100  

int index_last_odd(int* array) { 
 int last_index_odd; 
 for (int i = 0; i < N; i++) { 
  if (abs(array[i]) % 2 == 1) { 
   last_index_odd = i; 
  } 
 } 
 return last_index_odd; 
} 
