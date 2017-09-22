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

int get_coords(int *x, int *y, int maxX, int maxY){
  // gets coordinate input from user, converts to ints and 
  // enters data into passed pointers
  char indices[] = {'0','1','2','3','4','5','6','7','8','9',    \
                    'a','b','c','d','e','f'};
                    
  
  printf("enter x index: ");
  int badNumber = 1; //set flag for x coordinate
  while(badNumber){
    char index = single_char_input();
    for(int i=0;i<sizeof(indices)/sizeof(char);i++){
      if(indices[i] == index){
        if(i < maxX){
          *x = i;
          badNumber = 0;
        }
        break;
      }
    }
    if(badNumber){
      printf("please enter a valid x coordinate based on the board size \n");
    }
  }
  
  badNumber = 1; //set flag for y coordinate
  
  printf("enter y index: ");
  while(badNumber){
    char index = single_char_input();
    for(int i=0;i<sizeof(indices)/sizeof(char);i++){
      if(indices[i] == index){
        if(i < maxY){
          *y = i;
          badNumber = 0;
        }
        break;
      }
    }
    if(badNumber){
      printf("please enter a valid y coordinate based on the board size \n");
    }
  }
  
  return 0;
}
