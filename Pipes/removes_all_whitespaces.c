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

    while ((ch = fgetc(input)) != EOF)
    {
      if (ch == ' ')
      {
        break;
      }
      fputc(ch, output);
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