/* Hello World program */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main (int argc, char *argv[])
{
  bool interrupts = false;
  int time = 5;
  char *message = "Annoying message";

  int temp;
   for(temp = 0; temp < argc; temp++) {
      //read in the params
     if (strcmp(argv[temp], "+i") == 0) {
       interrupts = true;
     } else if (strcmp(argv[temp], "+t") == 0) {
       time = atoi(argv[temp  + 1]);
     } else if (strcmp(argv[temp], "-m") == 0) {
       message = argv[temp + 1];
     }
   }
  printf(interrupts ? "true" : "false");
  printf("\n%d\n", time);
  printf("message: %s", message);


  return 0;
}

