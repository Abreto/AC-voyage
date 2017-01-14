/* UESTC 2017 Winter Training #1. Problem C, by Abreto. */
#include <stdio.h>
#include <string.h>

#define MAXN    100004

int points[MAXN] = {0};

int find_winner(int n)
{
    int i = 0;
    int winner = 1, maxpoints = points[1];
    for(i = 2;i <= n;++i)
        if( points[i] > maxpoints )
        {
            winner = i;
            maxpoints = points[i];
        }
    return winner;
}

int handle_logs(int n, int q)
{
    int i = 0;
    int winner = 1;
    int ans = 0;

    for(i = 0;i < q;++i)
    {
        int X = 0, P = 0;
        scanf("%d %d", &X, &P);
        points[X] += P;
        if( X == winner )
        {
            if( P < 0 )
            {
                int newinner = find_winner(n);
                if( newinner != winner )
                {
                    ans = i+1;
                    winner = newinner;
                }
            }
        }
        else if ( P > 0 )
        {
            if( (points[X] > points[winner]) || 
                (points[X] == points[winner] && X < winner) )
            {
                ans = i+1;
                winner = X;
            }
        }
    }

    return ans;
}

void process(void)
{
    int N = 0, Q = 0;

    scanf("%d %d", &N, &Q);
    memset(points, 0, (N+1) * sizeof(int));
    printf("%d\n", handle_logs(N, Q));
}

int main(void)
{
    int T = 0;

    scanf("%d", &T);
    while(T--)
        process();

    return 0;
}
