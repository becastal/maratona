#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 1e6+10;
namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][4];
	int sz, last;

	void init() {
		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
	}
	
	void add(int c) {
		int cur = sz++;
		len[cur] = len[last] + 1;

		int p = last;
		while (p != -1 and !next[p][c]) {
			next[p][c] = cur;
			p = link[p];
		}

		if (p == -1) {
			link[cur] = 0;
		} else {
			int q = next[p][c];
			if (len[p] + 1 == len[q]) {
				link[cur] = q;
			} else {
				int clone = sz++;
				len[clone] = len[p] + 1;
				link[clone] = link[q];
				for (int i = 0; i < 4; i++) {
					next[clone][i] = next[q][i];
				}

				while (p != -1 and next[p][c] == q) {
					next[p][c] = clone;
					p = link[p];
				}

				link[q] = link[cur] = clone;
			}
		}
		last = cur;
	}
};

map<char, int> M = {
	{'^', 0}, 
	{'v', 1},
	{'-', 2},
	{'~', 3}
};

int solve() {
	string A, B; cin >> A >> B;

	sam::init();
	for (char c : A) {
		sam::add(M[c]);	
	}

	int u = 0, t = 0, res = 0;
	for (char c : B) {
		while (u and !sam::next[u][M[c]]) {
			u = sam::link[u];
			t = sam::len[u];
		}

		if (sam::next[u][M[c]]) {
			u = sam::next[u][M[c]];
			t++;
		} else {
			u = 0;
			t = 0;
		}
		res = max(res, t);
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

