/* Codecraft-17 and Codeforces Round #391. Problem A, by Abreto. */
#include <stdio.h>

int main(void)
{
  int i = 0;
  char wordtoform[] = "Bulbasaur";
  int count[255] = {0};
  int nBulbasaurs = 1e5+1;

  while( (i = getchar()) != 0x0A )
    count[i] ++;

  count['u'] /= 2;
  count['a'] /= 2;
  for(i = 0;i < 9;++i)
    if( count[wordtoform[i]] < nBulbasaurs )
      nBulbasaurs = count[wordtoform[i]];

  printf("%d\n", nBulbasaurs);
  return 0;
}
