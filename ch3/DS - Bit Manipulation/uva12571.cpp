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
    vector<int> end, pref;
    int sigma; 
    char norm;
    
    trie(int sigma_=2, char norm_='0') : sigma(sigma_), norm(norm_) {
        to = {vector<int>(sigma)};
        end = {0};
        pref = {0};
    }
    void insert(string s) {
        int x = 0;
        for (auto c : s) {
            int &nxt = to[x][c - norm];
            if (!nxt) {
                nxt = to.size();
                to.push_back(vector<int>(sigma));
                end.push_back(0);
                pref.push_back(0);
            }
            x = nxt;
            pref[x]++;
        }
        end[x]++;
    }
    int find(string s) {
        int x = 0;
        for (auto c : s) {
            x = to[x][c - norm];
            if (!x) return -1;
        }
        return x;
    }
    int query_(int nodo, int i, int x) {
        if (i < 0) return 0;

        if (((x >> i) & 1) == 1) {
            if (to[nodo][1] != 0) {
                return (1 << i) + query_(to[nodo][1], i - 1, x);
            } else if (to[nodo][0] != 0) {
                return query_(to[nodo][0], i - 1, x);
            } else {
                return 0;
            }
        } else {
            int res = 0;
            if (to[nodo][0] != 0) res = max(res, query_(to[nodo][0], i - 1, x));
            if (to[nodo][1] != 0) res = max(res, query_(to[nodo][1], i - 1, x));
            return res;
        }
    }
    int query(int x) {
        return query_(0, 8, x);
    }
};

void solve() {
    int n, q; 
    cin >> n >> q;
    vector<int> v(n);

    trie T;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        string si = "";
        for (int j = 8; j >= 0; j--) {
            si.push_back((v[i] & (1 << j)) ? '1' : '0');    
        }
        T.insert(si);
    }

    while (q--) {
        int x; 
        cin >> x;
        cout << T.query(x) << endl;
    }
}

int main() {
    _;
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

