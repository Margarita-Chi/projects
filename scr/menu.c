#include <stdio.h>  
#include <stdlib.h>  
#define N 100  
#include "action.h"
#include "input_action.h"
#include "input_array.h"

int main(void) { 
 char value = input_action(); 
 int* array = input_array(); 
 action(value, array); 
 return 0; 
}
