#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// 1…N Fenwick
struct Fenwick {
    int N;
    vector<int> f;
    Fenwick(int _N): N(_N), f(N+1, 0) {}

    // add v at index i
    void update(int i, int v) {
        for (; i <= N; i += i & -i)
            f[i] += v;
    }
    // sum of [1..i]
    int query(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }
    // sum of [l..r]
    int range(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int M = 2 * N;
    vector<int> seq(M);
    for(int i = 0; i < M; i++){
        cin >> seq[i];
        --seq[i];
    }

    Fenwick bit(M);
    vector<int> firstPos(N, -1);
    ll crossings = 0;

    for(int i = 0; i < M; i++){
        int cow = seq[i];
        if(firstPos[cow] == -1) {
            // mark the first occurrence
            firstPos[cow] = i + 1;  
            bit.update(i + 1, +1);
        } else {
            // closing this chord
            int L = firstPos[cow];
            int R = i + 1;
            // count other opens strictly between L and R
            crossings += bit.range(L+1, R-1);
            // remove its open-mark
            bit.update(L, -1);
        }
    }

    cout << crossings << "\n";
    return 0;
}
