/* UESTC 2017 Winter Training #1. Problem D, by Abreto. */
#include <stdio.h>

typedef long long int ll;

#define MAXN    1024

int R = 0, C = 0;
int g[MAXN][MAXN] = {{0}};    /* the girds */
int top[MAXN][MAXN] = {{0}};    /* the number of continuous same element above g[i][j] */

/*
lemma: if h is greater than the blocks' height before it, the sum should be add to the sum of
    blocks whose right-bottom corner is *it*.
*/
ll get_ans(void)
{
    int i = 0, j = 0;
    ll ans = 0;

    for(i = 1;i <= R;++i)
    {
        ll sum = 0; /* the sum of matrices whose right-gottom corner is g[i][j]. */
        int hs[MAXN] = {0}, ws[MAXN] = {0}; /* (h and w)s which is before g[i][j] in the same row; */
        size_t stop = 0;    /* size of (h and w)s. */
        for(j = 1;j <= C;++j)
        {
            int h = (( g[i][j] == g[i-1][j] ) ? ( top[i-1][j] +1 ) : 1);
            int w = 1;
            
            top[i][j] = h;
            if( g[i][j] != g[i][j-1] )  sum = stop = 0; /* clear sum and stacks */
            while( stop && (h <= hs[stop]) )
            {
                sum -= hs[stop] * ws[stop]; /* this part cannot be adjected to the current gird. */
                w += ws[stop--];    /* but the left can */
            }

            hs[++stop] = h; ws[stop] = w;
            sum += hs[stop] * ws[stop];
            ans += sum;
        }
    }

    return ans;
}

int main(void)
{
    int T = 0;

    scanf("%d", &T);
    while(T--)
    {
        int i = 0, j = 0;

        scanf("%d %d", &R, &C);
        for(i = 1;i <= R;++i)
            for(j = 1;j <= C;++j)
                scanf("%d", &(g[i][j]));

        printf("%lld\n", get_ans());
    }

    return 0;
}
