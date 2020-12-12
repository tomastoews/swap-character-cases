#include <stdio.h>
#include "utils.h"

// TODO: Implement a function that removes all white spaces from a string.

int custom_strlen(char str[]) {
   if (str == NULL) {
      return 0;
   }
   int length = 0;
   for (int i = 0; str[i] != '\0'; i++) {
      length++;
   }
   return length;
}

int main() {
  int size = 100;
  char input[size];

  // Get user input
  printf("Please enter a text (Format: UTF-8, max characters: 100):\n");
  fgets(input, size, stdin);

  // Check if any characters where entered
  printf("%d\n", custom_strlen(input));
  if (custom_strlen(input) == 1) {
    printf("Exit\n");
    return 0;
  }

  char result[custom_strlen(input)];

  for (int i = 0; i < custom_strlen(input); i++) {
    // Convert char into int (ASCII decimal number)
    int char_number = (int)input[i];

    // Check if the ASCII number is between the ones of a-z or A-Z.
    // Check if the character is either lower case or upper case. Then swap it
    if (char_number >= alphabet_uppercase_min && char_number <= alphabet_uppercase_max) {
        result[i] = (char)char_number+32;
    } else if (char_number >= alphabet_lowercase_min && char_number <= alphabet_lowercase_max) {
        result[i] = (char)char_number-32;
    } else {
        result[i] = input[i];
    }
  }

  printf("Result: %s\n", result);

  return 0;
}
