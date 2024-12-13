#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
using namespace std;

struct Node {
    int mostFreq; // most frequent element
    int freq; // frequency of the most frequent element
    int leftVal; // leftmost value
    int leftFreq; // frequency of the leftmost value
    int rightVal; // rightmost value
    int rightFreq; // frequency of the rightmost value
};

vector<Node> segtree;
vector<int> arr;
vector<int> lazy;
int n;

Node merge(Node left, Node right) {
    Node res;
    res.leftVal = left.leftVal;
    res.leftFreq = (left.leftVal == right.leftVal) ? left.leftFreq + right.leftFreq : left.leftFreq;
    res.rightVal = right.rightVal;
    res.rightFreq = (right.rightVal == left.rightVal) ? right.rightFreq + left.rightFreq : right.rightFreq;

    if (left.rightVal == right.leftVal) {
        int combinedFreq = left.rightFreq + right.leftFreq;
        if (combinedFreq > left.freq && combinedFreq > right.freq) {
            res.mostFreq = left.rightVal;
            res.freq = combinedFreq;
        } else if (left.freq > right.freq) {
            res.mostFreq = left.mostFreq;
            res.freq = left.freq;
        } else {
            res.mostFreq = right.mostFreq;
            res.freq = right.freq;
        }
    } else {
        if (left.freq > right.freq) {
            res.mostFreq = left.mostFreq;
            res.freq = left.freq;
        } else {
            res.mostFreq = right.mostFreq;
            res.freq = right.freq;
        }
    }

    return res;
}

void apply(int v, int tl, int tr, int val) {
    segtree[v].mostFreq = (segtree[v].mostFreq + val) % 9;
    segtree[v].leftVal = (segtree[v].leftVal + val) % 9;
    segtree[v].rightVal = (segtree[v].rightVal + val) % 9;

    if (tl != tr) {
        lazy[v * 2] += val;
        lazy[v * 2 + 1] += val;
    }
}

void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
        apply(v, tl, tr, lazy[v]);
        lazy[v] = 0;
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        segtree[v] = {arr[tl], 1, arr[tl], 1, arr[tl], 1};
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        segtree[v] = merge(segtree[v * 2], segtree[v * 2 + 1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > r)
        return {-1, 0, -1, 0, -1, 0};
    if (l == tl && r == tr)
        return segtree[v];
    int tm = (tl + tr) / 2;
    return merge(query(v * 2, tl, tm, l, min(r, tm)),
                 query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    push(v, tl, tr);
    if (l > r)
        return;
    if (l == tl && r == tr) {
        apply(v, tl, tr, addend);
    } else {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), addend);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        segtree[v] = merge(segtree[v * 2], segtree[v * 2 + 1]);
    }
}

int main() {
    _
    int Q;
    cin >> n >> Q;

    arr.resize(n, 1); // Initialize all notes to 1
    segtree.resize(4 * n);
    lazy.resize(4 * n, 0);

    build(1, 0, n - 1);

    while (Q--) {
        int a, b;
        cin >> a >> b;
        Node res = query(1, 0, n - 1, a, b);
        update(1, 0, n - 1, a, b, res.mostFreq);
    }

    for (int i = 0; i < n; ++i) {
        Node res = query(1, 0, n - 1, i, i);
        cout << res.mostFreq << endl;
    }

    return 0;
}

