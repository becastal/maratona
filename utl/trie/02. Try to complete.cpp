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

struct TRIE {
    vector<vector<int>> to;
    vector<int> end, pref;
    int sigma; char norm;
    TRIE(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
        to = {vector<int>(sigma)};
        end = {0}, pref = {0};
    }
    void insert(string s) {
        int x = 0;
        for (auto c : s) {
            int &nxt = to[x][c-norm];
            if (!nxt) {
                nxt = to.size();
                to.push_back(vector<int>(sigma));
                end.push_back(0), pref.push_back(0);
            }
            x = nxt, pref[x]++;
        }
        end[x]++, pref[0]++;
    }
    int find(string s) {
        int x = 0;
        for (auto c : s) {
            x = to[x][c-norm];
            if (!x) return -1;
        }
        return x;
    }
    pair<string, int> combina(const pair<string, int>& a, const pair<string, int>& b) {
        if (a.s > b.s) {
            return a;
        } else if (a.s < b.s) {
            return b;
        }
        return {min(a.f, b.f), a.s};
    }
    pair<string, int> dfs(int node, vector<char>& current, int depth) {
        pair<string, int> best = {string(current.begin(), current.begin() + depth), end[node]};
        for (int i = 0; i < sigma; ++i) {
            if (to[node][i]) {
                current[depth] = norm + i;
                auto result = dfs(to[node][i], current, depth + 1);
                best = combina(best, result);
            }
        }
        return best;
    }
    pair<string, int> query(string s) {
        int pos = find(s);
        if (pos == -1) return {"", -1};
        vector<char> current(s.begin(), s.end());
        current.resize(15);
        return dfs(pos, current, s.size());
    }
};

int main()
{
    _;

    int n; cin >> n;
    TRIE trie;
    while (n--) {
        string si; cin >> si;
        trie.insert(si);
    }

    int q; cin >> q;
    while (q--) {
        string si; cin >> si;
        auto qr = trie.query(si);
        if (qr.s > 0) {
            cout << qr.f << ' ' << qr.s << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}

