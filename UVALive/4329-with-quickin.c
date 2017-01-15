/* UVALive 4329. Asia - Beijing 2008 Regional. by Abreto. */
#include <stdio.h>

#define MAXN 20048
#define MAXA 100004
#define lowbit(x)   ((x)&(-(x)))

typedef long long int ll;

#define isdigit(x)  ((x>='0')&&(x<='9'))

int readn(void)
{
    int x = 0; char c = getchar();
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar()) x = x*10+c-'0';
    return x;
}

int N = 0;
int a[MAXN] = {0};  /* 0-based */
int maxa = 0;
/* c[i] stands for the number of plays who are before and worse than a[i],
   d[i] stands for the number of plays who are after and worse than a[i] */
int c[MAXN] = {0}, d[MAXN] = {0};
int x[MAXA] = {0};
int cx[MAXA] = {0};

void bit_init(void)
{
    int i = 0;
    for(i = 0;i <= maxa;++i)
        x[i] = cx[i] = 0;
}

void update(int ai)
{
    while( ai <= maxa )
    {
        cx[ai] += 1;
        ai += lowbit(ai);
    }
}

int sum(int ai)
{
    int s = 0;
    while( ai > 0 )
    {
        s += cx[ai];
        ai -= lowbit(ai);
    }
    return s;
}

void calculate_ci(void)
{
    int i = 0;
    bit_init();
    update(a[0]);
    for(i = 1;i < N-1;++i)
    {
        c[i] = sum(a[i]);
        update(a[i]);
    }
}

void calculate_di(void)
{
    int i = 0;
    bit_init();
    update(a[N-1]);
    for(i = N-2;i > 0;--i)
    {
        d[i] = sum(a[i]);
        update(a[i]);
    }
}

void proccess(void)
{
    int i = 0;
    ll ans = 0;
    
    N = readn();
    for(i = 0;i < N;++i)
    {
        a[i] = readn();
        if( a[i] > maxa )   maxa = a[i];
    }

    calculate_ci(); calculate_di();

    for(i = 1;i < N-1;++i)
    {
        ans += c[i] * (N-1-i-d[i]);
        ans += d[i] * (i - c[i]);
    }

    printf("%lld\n", ans);
}

int main(void)
{
    int T = 0;

    T = readn();
    while(T--)
        proccess();

    return 0;
}
