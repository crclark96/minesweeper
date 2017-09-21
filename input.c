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

int single_integer_input(){
  int value;
  value = scanf("%d", &value);
  return value;
}

int get_coords(int *x, int *y){
  // gets coordinate input from user, converts to ints and 
  // enters data into passed pointers
  printf("enter x index: ");
  *x = single_integer_input();
  
  printf("enter y index: ");
  *y = single_integer_input();
  
  return 0;
}
