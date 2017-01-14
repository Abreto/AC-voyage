/* Codecraft-17 and Codeforces Round #391. Problem B, by Abreto. */
#include <stdio.h>

int is_prime(int x)
{
  int i = 0;
  for(i = 2;i*i <= x;++i)
    if( 0 == x%i )
      return 0;
  return 1;
}

int main(void)
{
  int i = 0;
  int n = 1;

  printf("{2");
  for(i = 3;i < 1e5;++i)
    if( is_prime(i) )
    {
      printf(",%d", i);
      n++;
    }

  printf("};\nTotal: %d.\n", n);
  return 0;
}
