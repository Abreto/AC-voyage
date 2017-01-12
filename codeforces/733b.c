/* Codeforces Round #378 (Div. 2). Problem B. by Abreto. */
#include <stdio.h>
#include <stdlib.h>

#define ABS(x)  ( ((x)>0)?(x):(-(x)) )

int n = 0;
int diff[100001] = {0};
int order[100001] = {0};
int origin_beauty = 0;

int compar(const void * a, const void * b)
{
  return ( diff[*((int*)a)] - diff[*((int*)b)] );
}

int select_column(void)
{
  int max_beauty = ABS(origin_beauty);
  int cur_beauty = 0;
  int to_convert = 0;
  
  /* convert the first one */
  cur_beauty = ABS(origin_beauty - 2*diff[order[0]]);
  if( cur_beauty > max_beauty )
  {
    max_beauty = cur_beauty;
    to_convert = order[0] + 1;
  }
  /* convert the last one */
  cur_beauty = ABS(origin_beauty - 2*diff[order[n-1]]);
  if( cur_beauty > max_beauty )
  {
    max_beauty = cur_beauty;
    to_convert = order[n-1] + 1;
  }

  return to_convert;
}

int main(void)
{
  int i = 0;
  int l = 0, r = 0;

  scanf("%d", &n);
  for(i = 0;i < n; ++i)
  {
    scanf("%d %d", &l, &r);
    diff[i] = l - r;
    order[i] = i;
    origin_beauty += diff[i];
  }

  qsort(order, n, sizeof(int), compar);

  if( diff[order[0]] * diff[order[n-1]] >= 0 ) /* already maximized */
  {
    printf("0\n");
  }
  else
  {
    printf("%d\n", select_column());
  }

  return 0;
}
