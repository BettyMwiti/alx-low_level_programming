#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet.
ROT13 is an example of the Caesar cipher.

This function takes a string and returns the string ciphered with Rot13. 
If there are numbers or special characters included in the string, they are returned as they are. 
Only letters from the latin/english alphabet are shifted, like in the original Rot13 "implementation".
*/

char *rot13(const char *src)
{
    if(src == NULL){
      return NULL;
    }

   char* result = malloc(strlen(src));

    if(result != NULL){
      strcpy(result, src);
      char* current_char = result;

      while(*current_char != '\0'){
        //Only increment alphabet characters
        if((*current_char >= 97 && *current_char <= 122) || (*current_char >= 65 && *current_char <= 90)){
          if(*current_char > 109 || (*current_char > 77 && *current_char < 91)){
            //Characters that wrap around to the start of the alphabet
            *current_char -= 13;
          }else{
            //Characters that can be safely incremented
           *current_char += 13;
         }
       }
       current_char++;
     }
   }
    return result;
}
