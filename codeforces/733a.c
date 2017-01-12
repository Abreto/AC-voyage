/* Codeforces Round #378 (Div. 2). Problem A. by Abreto. */
#include <stdio.h>
#include <string.h>

int is_vowel(char x)
{
  switch (x)
  {
    case 'A':case 'E':case 'I':case 'O':case 'U':case 'Y':
      return 1;
    default:
      return 0;
  }
}

int main(void)
{
  int i = 0, len = 0;
  char str[128] = {0};
  int last_position = -1;
  int jump_ablity = 1;

  scanf("%s", str);
  len = strlen(str);

  for(i = 0;i < len;++i)
    if( is_vowel(str[i]) )
    {
      int t  = i - last_position;
      jump_ablity = (t > jump_ablity) ? t : jump_ablity;
      last_position = i;
    }

  jump_ablity = ( (len - last_position) > jump_ablity ) ? (len - last_position) : jump_ablity;

  printf("%d\n", jump_ablity);
  return 0;
}
