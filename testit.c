#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define COMBINTATORIC_IMPL
#include "combinatori.h"

#define DIMS 3
#define VALS 3

int main(int argc, char **argv)
{
  printf("Hello, World\n");
  size_t buffer[DIMS];
  combinatoric_combination_iterator_t iter = combinatoric_combination_iterator(VALS, DIMS, buffer);
  size_t next[DIMS];
  size_t cnt = 0;
  while(combinatoric_combination_iterator_next(&iter, next))
  {
    cnt++;
    printf("%4zu: ", cnt); 
    for(size_t i=0; i<DIMS; i++)
    {
      printf("%2zu ", next[i]); 
    }
    printf("\n");
  }
  return 0;
}
