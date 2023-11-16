#include <stdio.h>

int main(void) {
	int array[3];
	int i = 0;
	while (i < 3) {
		scanf("%d", &array[i]);
		i++;
	}
	printf("%d", array[0]);
	return 0;
}