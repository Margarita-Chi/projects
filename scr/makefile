all: menu 
 
menu: menu.o input_action.o input_array.o action.o index_first_even.o index_last_odd.o sum_between_even_odd.o sum_before_even_and_after_odd.o 
	gcc -std=gnu99 menu.o input_action.o input_array.o action.o index_first_even.o index_last_odd.o sum_between_even_odd.o sum_before_even_and_after_odd.o -o menu
 
menu.o: menu.c 
	gcc -std=gnu99 -c menu.c 
 
input_action.o: input_action.c 
	gcc -std=gnu99 -c input_action.c 
 
input_array.o: input_array.c 
	gcc -std=gnu99 -c input_array.c 
 
index_first_even.o: index_first_even.c 
	gcc -std=gnu99 -c index_first_even.c 
 
index_last_odd.o: index_last_odd.c 
	gcc -std=gnu99 -c index_last_odd.c 
 
sum_between_even_odd.o: sum_between_even_odd.c 
	gcc -std=gnu99 -c sum_between_even_odd.c 
 
sum_before_even_and_after_odd.o: sum_before_even_and_after_odd.c 
	gcc -std=gnu99 -c sum_before_even_and_after_odd.c 

action.o: action.c 
	gcc -std=gnu99 -c action.c  

clean:  
	rm -rf *.o menu
