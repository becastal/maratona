#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct trie {
    vector<vector<int>> to;
    vector<int> cnt, mn;

    trie() {
        to.push_back(vector<int>(2, -1));
        cnt.push_back(0);
        mn.push_back(INF);
    }
    void insert(int x, int idx) {
        int u = 0;
        mn[u] = min(mn[u], idx);
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (to[u][bit] == -1) {
                to[u][bit] = to.size();
                to.push_back(vector<int>(2, -1));
                cnt.push_back(0);
                mn.push_back(INF);
            }
            u = to[u][bit];
            cnt[u]++;
            mn[u] = min(mn[u], idx);
        }
    }
    int query(int K, int x) {
        int ret = INF;
        int u = 0;
        for (int i = 30; i >= 0; i--) {
            int bitK = (K >> i) & 1;
            int bitX = (x >> i) & 1;
            if (bitK == 1) {
                u = to[u][!bitX];
                if(u == -1) return INF;
            } else {
                if(to[u][!bitX] != -1) ret = min(ret, mn[to[u][!bitX]]);
                u = to[u][bitX];
                if(u == -1) break;
            }
        }
        if(u != -1) ret = min(ret, mn[u]);
        return ret;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    
    if(!k) { 
        cout << 1 << endl;
        return;
    }
    
    trie T;
    int ans = INF;
    for (int i = n - 1; i >= 0; i--) {
        int qi = T.query(k, v[i]);
        if (qi != INF) ans = min(ans, qi - i + 1);
        T.insert(v[i], i);
    }
    
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    _;

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return(0);
}

