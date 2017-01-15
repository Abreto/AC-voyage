/* Try to learn segment tree. */
#include <stdio.h>
#include <stdlib.h>

typedef struct _segtree
{
    int *s;
    int n;  /* Root of the tree belongs to the interval [0, n) (0-based). */
}segtree, *p_segtree;

void st_init(p_segtree st, size_t maxn)
{
    st->s = (int *)malloc(5 * maxn * sizeof(int));
    st->n = maxn;
}

void __st_build(p_segtree st, int data[], int id, int l, int r)
{
    if( l+1 == r )
    {
        st->s[id] = data[l];
    }
    else
    {
        int mid = (l+r)/2;
        __st_build(st, data, id*2, l, mid);
        __st_build(st, data, id*2+1, mid, r);
        st->s[id] = st->s[id*2] + st->s[id*2+1];
    }
}

int __st_query(segtree st, int x, int y, int id, int l, int r)
{
    if( y <= l || x >= r )  return 0;
    if( x <= l && r <= y )  return st.s[id];
    else  
    {
        int mid = (l+r)/2;
        return __st_query(st, x, y, id*2, l, mid)
            + __st_query(st, x, y, id*2+1, mid, r);
    }
}

void st_build(p_segtree st, int data[])
{
    __st_build(st, data, 1, 0,st->n);
}

int st_query(segtree st, int x, int y)
{
    return __st_query(st, x, y, 1, 0, st.n);
}

int main(void)
{
    int i = 0;
    segtree t;
    int a[12] = {1,4,5,3,4,6,5,4,2,2,1,5};

    st_init(&t, 12);
    st_build(&t, a);
    ;
    i = st_query(t, 0,12);
    i = st_query(t, 4,7);
    i = st_query(t, 8,10);

    return 0;
}
