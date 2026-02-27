#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 4e5+10;
const int LOG = 20;

namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][26];
	int pai[2*MAX][LOG];
	int sz, last;

	void init() {
		len[0] = 0; link[0] = -1;
		for (int i = 0; i < LOG; i++) {
			pai[0][i] = -1;
		}
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
				for (int i = 0; i < 26; i++) {
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

	void processa() {
		for (int u = 0; u < sz; u++) {
			pai[u][0] = link[u];
		}

		for (int j = 1; j < LOG; j++) {
			for (int u = 0; u < sz; u++) {
				if (pai[u][j-1] == -1) {
					pai[u][j] = -1;
					continue;
				}
				pai[u][j] = pai[pai[u][j-1]][j-1];
			}
		}
	}

	int kesimo_pai(int u, int k) {
		for (int i = LOG - 1; i >= 0; i--) {
			int v = pai[u][i];
			if (v != -1 and len[v] >= k) {
				u = v;
			}
		}
		return u;
	}
};

/*
falta:
	tratar caracteres chatos (ascii 33 ate 127, da pra manter O(n) o build)
	fazer query de lca entre U[a] e U[b], que diz tambem qual o lcp de a e b
	a partir do lcp, computar qual substring eh menor (basta checar o T em lcp + 1)
*/

int solve() {
	string T; cin >> T;
	reverse(all(T));
	int n = (int)T.size(), m; cin >> m;

	vector<int> Ult(n);
	for (int i = 0; i < n; i++) {
		sam::add(T[i] - 'a'); 
		Ult[i] = sam::last;
	}

	vector<array<int, 2>> A(m);
	vector<int> U(m);

	for (int i = 0, l, r; i < m; i++) {
		cin >> l >> r; A[i] = {l, r};
		l--, r--;
		int r_ = n - l - 1, l_ = n - r - 1;
		l = l_, r = r_;
		
		int u = Ult[r];
		U[i] = kesimo(u, r - l + 1);
	}

	vector<int> P(m);
	iota(all(P), 0);
	sort(all(P), [&](int a, int b) {

	});

	for (int i : P) {
		cout << A[i][0] << ' ' << A[i][1] << endl;
	}
	
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

