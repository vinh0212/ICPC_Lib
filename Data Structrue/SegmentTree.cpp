#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree
{
private:
    int n;          // n = (int)A.size()
    vi A, st, lazy; // the arrays

    int lc(int p) { return p << 1; }       // go to left child
    int rc(int p) { return (p << 1) + 1; } // go to right child

    int conquer(int a, int b)
    {
        if (a == -1)
            return b; // corner case
        if (b == -1)
            return a;
        return min(a, b); // choose type of query here, maybe max, sum, etc
    }

    void build(int p, int l, int r)
    { // O(n)
        if (l == r)
            st[p] = A[l]; // base case
        else
        {
            int mid = (l + r) / 2;
            build(lc(p), l, mid);
            build(rc(p), mid + 1, r);
            st[p] = conquer(st[lc(p)], st[rc(p)]);
        }
    }

    void propagate(int p, int l, int r)
    {
        if (lazy[p] != -1)
        {                                          // has a lazy flag
            st[p] = lazy[p];                       // [l..r] has same value
            if (l != r)                            // not a leaf
                lazy[lc(p)] = lazy[rc(p)] = lazy[p]; // propagate downwards
            else                                   // l == r, a single index
                A[l] = lazy[p];                    // time to update this
            lazy[p] = -1;                          // erase lazy flag
        }
    }

    int query(int p, int l, int r, int i, int j)
    {                       // O(log n)
        propagate(p, l, r); // lazy propagation
        if (i > j)
            return -1; // infeasible
        if ((l >= i) && (r <= j))
            return st[p]; // found the segment
        int mid = (l + r) / 2;
        return conquer(query(lc(p), l, mid, i, min(mid, j)),
                       query(rc(p), mid + 1, r, max(i, mid + 1), j));
    }

    void update(int p, int l, int r, int i, int j, int val)
    {                       // O(log n)
        propagate(p, l, r); // lazy propagation
        if (i > j)
            return;
        if ((l >= i) && (r <= j)) //[l,r] in [i,j]
        {                       // found the segment
            lazy[p] = val;      // update this
            propagate(p, l, r); // lazy propagation
        }
        else
        {
            int mid = (l + r) / 2;
            update(lc(p), l, mid, i, min(mid, j), val);
            update(rc(p), mid + 1, r, max(i, mid + 1), j, val);
            int lsubtree, rsubtree;
            if (lazy[lc(p)] != -1)
                lsubtree = lazy[lc(p)];
            else
                lsubtree = st[lc(p)];
            if (lazy[rc(p)] != -1)
                rsubtree = lazy[rc(p)];
            else
                rsubtree = st[rc(p)];
            st[p] = conquer(lsubtree, rsubtree);
        }
    }

public:
    SegmentTree(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n, -1) {}

    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size())
    {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int query(int i, int j) { return query(1, 0, n - 1, i, j); }
};

// Example Code

int main()
{
    vi A = {18, 17, 13, 19, 15, 11, 20, 99}; // make n a power of 2
    SegmentTree st(A);

    cout << "              idx    0, 1, 2, 3, 4, 5, 6, 7" << endl;
    cout << "              A is {18,17,13,19,15,11,20,oo}" << endl;
    cout << "query(1, 3) = " << st.query(1, 3) << endl; // 13
    cout << "query(4, 7) = " << st.query(4, 7) << endl; // 11
    cout << "query(3, 4) = " << st.query(3, 4) << endl; // 15

    st.update(5, 5, 77); // update A[5] to 77
    cout << "              idx    0, 1, 2, 3, 4, 5, 6, 7" << endl;
    cout << "Now, modify A into {18,17,13,19,15,77,20,oo}" << endl;
    cout << "query(1, 3) = " << st.query(1, 3) << endl; // remains 13
    cout << "query(4, 7) = " << st.query(4, 7) << endl; // now 15
    cout << "query(3, 4) = " << st.query(3, 4) << endl; // remains 15

    st.update(0, 3, 30); // update A[0..3] to 30
    cout << "              idx    0, 1, 2, 3, 4, 5, 6, 7" << endl;
    cout << "Now, modify A into {30,30,30,30,15,77,20,oo}" << endl;
    cout << "query(1, 3) = " << st.query(1, 3) << endl; // now 30
    cout << "query(4, 7) = " << st.query(4, 7) << endl; // remains 15
    cout << "query(3, 4) = " << st.query(3, 4) << endl; // remains 15

    st.update(3, 3, 7); // update A[3] to 7
    cout << "              idx    0, 1, 2, 3, 4, 5, 6, 7" << endl;
    cout << "Now, modify A into {30,30,30, 7,15,77,20,oo}" << endl;
    cout << "query(1, 3) = " << st.query(1, 3) << endl; // now 7
    cout << "query(4, 7) = " << st.query(4, 7) << endl; // remains 15
    cout << "query(3, 4) = " << st.query(3, 4) << endl; // now 7

    return 0;
}