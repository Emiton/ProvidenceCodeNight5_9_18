// In C we must inlcude any libraries which contain functions that we use
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Every C program has a main function that must return an int
int main(void)
{
  // Create a key
  int given_key = 1;
  // Create a plain text string
  char *input_text = "Hello";

  //If the key is negative, then will give an error message and quit the program
  if (given_key < 0)
  {
    printf("Error: Key must be a positive value");
    return 1;
  }

  // Print the first parts of the message
  printf("Plain text: %s\n", input_text);
  printf("Cipher text: ");

  // Get the number of letters in the plain text string
  int length = strlen(input_text);

  // Make sure the key is not greater than 26
  int key = given_key % 26;


  // This loop check every letter in the string and
  for (int i = 0; i < length; i++)
  {
    //The start of the alphabet for a given letter
    int start = 0;
    int current_char = 0;

    //Check if it is a letter
    if (isalpha(input_text[i]))
    {

      //Check if lower case
      if (islower(input_text[i]))
      {
        start = 'a';
      }
      //Check if upper case
      else if (isupper(input_text[i]))
      {
        start = 'A';
      }

      current_char = (((input_text[i] - start) + key) % 26) + start;
      printf("%c", current_char);

    }
    //If it's not a letter, then just print it
    else
    {
      printf("%c", input_text[i]);
    }


  }

  //Just to make sure the next output is on a new line
  printf("\n");

  return 0;
}
