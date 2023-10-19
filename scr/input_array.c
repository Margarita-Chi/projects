#include <stdio.h>  
#include <stdlib.h>  
#define N 100  

int* input_array(void) { 
 static int array[N]; 
 int i = 0; 
 char space = ' '; 
 while (i < N && space == ' ') { 
  scanf("%d%c", &array[i], &space); 
  i++; 
 } 
 for (i; i < N; i++) { 
  array[i] = 0; 
 } 
 return array; 
} 
 
