#include <stdio.h>  
#include <stdlib.h>  
#define N 100  
#include "index_first_even.h"
#include "index_last_odd.h"

int sum_between_even_odd(int* array) { 
 int sum_between_even_odd = 0; 
 for (int i = index_first_even(array); i < index_last_odd(array); i++) { 
  sum_between_even_odd += abs(array[i]); 
 } 
 return sum_between_even_odd; 
} 
