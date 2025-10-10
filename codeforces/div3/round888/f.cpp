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
	int sigma, k; char norm;
	trie(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
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
    tuple<int,int,int> query(string s) {
        int u = 0, res = 0, x = 0, y = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int bit = s[i] - '0';

            if (to[u][bit] and pref[to[u][bit]] > 0) {
                u = to[u][bit];
				y <<= 1, y |= bit;
				res <<= 1, res |= 1;
                if (!bit) x = (x << 1) | 1;
                else x = (x << 1) | 0;
            } else {
                u = to[u][bit ^ 1];
                y = (y << 1) | (bit ^ 1);
                res <<= 1, x <<= 1;
            }
        }
        return {res, x, y};
    }
};

string bs(int x, int k) {
    string s;
    for (int i = k - 1; i >= 0; i--) {
        s.push_back('0' + ((x >> i) & 1));
    }
    return s;
}

int solve() {
	int n, k; cin >> n >> k;

	map<int, int> pos;
	trie t(2, '0');

	int res = -1, ii, jj, x;
	for (int i = 0, vi; i < n; i++) {
		cin >> vi;

		if (i) {
			auto [res_, x_, y_] = t.query(bs(vi, k));

			if (res < res_) {
				res = res_;
				x = x_;
				jj = i;
				ii = pos[y_];
			}
		}
		t.insert(bs(vi, k));
		pos[vi] = i;
	}

	cout << ii + 1 << ' ' << jj + 1 << ' ' << x << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
