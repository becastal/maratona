#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 150020;
namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][20];
	int ocur[2*MAX], pos[2*MAX];
	int sz, last, m;

	void init(int m_) {
		m = m_;	
		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
	}

	void add(int c, int t) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		pos[cur] = t;
		ocur[cur] = 1;

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
				pos[clone] = pos[q];
				len[clone] = len[p] + 1;
				link[clone] = link[q];
				for (int i = 0; i < m; i++) {
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

	array<int, 3> calc() {
		vector<int> U(sz);
		iota(all(U), 0);
			
		sort(all(U), [&](int a, int b) {
			return len[a] > len[b];
		});

		for (int u : U) if (link[u] != -1) {
			ocur[link[u]] += ocur[u];
		}

		array<int, 3> res;
		for (int u = 1; u < sz; u++) {
			array<int, 3> agr = {ocur[u] * len[u], len[u], pos[u] - len[u] + 1};			
			res = max(res, agr);
		}
		return res;
	}


};

int solve() {
	int n, m; cin >> n >> m;

	vector<int> A(n);
	sam::init(m);
	for (int i = 0; i < n; i++) {
		cin >> A[i]; A[i]--;
		sam::add(A[i], i);
	}

	array<int, 3> res = sam::calc();
	cout << res[0] << endl << res[1] << endl;
	for (int i = res[2], j = 0; j < res[1]; i++, j++) {
		cout << A[i] + 1 << ' ';
	}
	cout << endl;

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

