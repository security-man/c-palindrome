#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* int_to_base_2(int value) {
	char *base_2_array = malloc(8);
	int temp_division = value;
	int temp_remainder;
	for(int i = 0; i < 8; i++) {
		temp_remainder = temp_division % 2; 
		temp_division = temp_division / 2;
		if(temp_remainder == 1) {
			base_2_array[7 - i] = 1;
		} else {
			base_2_array[7 - i] = 0;
		}
	}
	return base_2_array;
}

void palindrome(char value[]) {
	int array_size = 8 * (strlen(value) - 1);	
	char *binary_input = malloc(array_size);
	char *binary_input_reversed = malloc(array_size);
	char *base_2_array = malloc(8);
	for(int i = 0; i < strlen(value) - 1; i++) {
		int char_as_num = (int)value[i];
		base_2_array = int_to_base_2(char_as_num);
		for(int j = 0; j < 8; j++) {
			binary_input[(i*8) + j] = base_2_array[j];
		}
	}
	for(int i = 0; i < array_size; i++) {
		binary_input_reversed[array_size - i - 1] = binary_input[i];
	}
	int palindrome_checker = 0;
	for(int i = 0; i < array_size; i++) {
		if(binary_input_reversed[i] != binary_input[i]) {
			palindrome_checker = 1;
		}
	}
	for(int i = 0; i < strlen(value) - 1; i++) {
		printf("    %c    ",value[i]);
	}
	printf("\n");
	for(int i = 0; i < strlen(value) - 1; i++) {
		for(int j = 0; j < 8; j++) {
			printf("%i",binary_input[(i*8) + j]);
		}
		printf(" ");
	}
	printf("\n");
	for(int i = 0; i < strlen(value) - 1; i++) {
		for(int j = 0; j < 8; j++) {
			printf("%i",binary_input_reversed[(i*8) + j]);
		}
		printf(" ");
	}
	printf("\n");	
	if(palindrome_checker == 0) {
		printf("\nInput is a palindrome in base-2 binary!\n");
	}
}

int main() {
	printf("$ ");
    fflush(stdout);
    char input[100];
    fgets(input, 100, stdin);
	printf("\n");
	palindrome(input);
	printf("\n");
	return 0;
}
