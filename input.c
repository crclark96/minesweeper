#include <stdio.h>
#include "input.h"

char single_char_input(){
  // get a single character of input from user
  int num_chars = 5; // arbitrary > 1
  char input,c;

  while(num_chars > 1){
    num_chars = 0;
    c = '\0';
    input = getchar();
    while(c!='\n'){
      c = getchar();
      num_chars++;
    }
    if(num_chars > 1){
      printf("please enter a single character command \n");
    }
  }
  return input;
}
