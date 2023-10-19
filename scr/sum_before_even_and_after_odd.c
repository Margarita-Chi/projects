#include <stdio.h>  
#include <stdlib.h>  
#define N 100  
#include "index_first_even.h"
#include "index_last_odd.h"

int sum_before_even_and_after_odd(int* array) { 
 int sum_before_even_after_odd = 0; 
 for (int i = 0; i < index_first_even(array); i++) { 
  sum_before_even_after_odd += abs(array[i]); 
 } 
 for (int i = index_last_odd(array); i < N; i++) { 
  sum_before_even_after_odd += abs(array[i]); 
 } 
 return sum_before_even_after_odd; 
} 
 
