#include <stdio.h>
#include <stdint.h>


/* read n bytes from stdin including newline char + null char */
extern void getns(char *buf, int32_t n)
{
  fgets(buf, n, stdin);
}

/* put char-seq onto stdout */
extern void putcs(char *buf, int32_t n)
{
  /* '\0' may not evaluate to 0
   * therefore, *buf must be checked against '\0' */
  while(n-- && *buf != '\0') putchar(*(buf++));
  fflush(stdout);
}
