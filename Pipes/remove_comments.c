#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int filter(FILE *input, FILE *output)
{

  while (!feof(input))
  {
    if (ferror(input))
    {
      return 1;
    }
    int ch;
    int nextCh;

    nextCh = fgetc(input);
    while (nextCh != EOF)
    {
      ch = nextCh;
      nextCh = fgetc(input);

      if ((ch == '/') && (nextCh == '*'))
      {
        nextCh = fgetc(input);
        while ((ch != '*') && (nextCh != '/'))
        {
          ch = nextCh;
          nextCh = fgetc(input);
        }
        ch = fgetc(input);
        nextCh = fgetc(input);
      }
      putc(ch, output);
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