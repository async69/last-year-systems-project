#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1000

int filter(FILE *input, FILE *output)
{

  while (!feof(input))
  {
    if (ferror(input))
    {
      return 1;
    }
    char ch;
    char buffer[BUFFER_SIZE];

    while ((fgets(buffer, BUFFER_SIZE, input)) != NULL)
    {
      if (buffer[0] != '\n')
        fputs(buffer, output);
    }
  }
  return 0;
}

int main(void)
{
  const int retval = filter(stdin, stdout);
  fflush(stdout);
  return retval;
}