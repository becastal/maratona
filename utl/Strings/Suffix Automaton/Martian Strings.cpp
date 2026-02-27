#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 1e5+10;
namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][26];
	int pos[2*MAX];
	int sz, last;

	void init() {
		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
	}
	
	void add(int c, int t) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		pos[cur] = t;

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
				pos[clone] = pos[q];
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
};

namespace sam_ {
	int len[2*MAX], link[2*MAX], next[2*MAX][26];
	int pos[2*MAX];
	int sz, last;

	void init() {
		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
	}
	
	void add(int c, int t) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		pos[cur] = t;

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
				pos[clone] = pos[q];
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

};

int solve() {
	string T; cin >> T;
	int n = (int)T.size();

	string T_ = T;
	reverse(all(T_));

	sam::init(), sam_::init();
	for (int i = 0; i < n; i++) {
		sam::add(T[i] - 'A', i);
		sam_::add(T_[i] - 'A', n-1-i);
	}

	int m, res = 0; cin >> m;
	while (m--) {
		string S; cin >> S;
		int nn = (int)S.size();

		if (nn == 1) {
			continue;
		}

		string S_ = S;
		reverse(all(S_));

		vector<int> Pre(nn), Suf(nn);
		for (int i = 0, u = 0, v = 0; i < nn; i++) {
			if (u == -1 or !sam::next[u][S[i] - 'A']) u = -1;
			else u = sam::next[u][S[i] - 'A'];

			if (v == -1 or !sam_::next[v][S_[i] - 'A']) v = -1;
			else v = sam_::next[v][S_[i] - 'A'];

			Pre[i] = (u == -1 ? -1 : sam::pos[u]);
			Suf[i] = (v == -1 ? -1 : sam_::pos[v]);
		}

		//for (int i = 0; i < nn; i++) {
		//	cout << Pre[i] << " \n"[i==nn-1];
		//}
		//for (int i = 0; i < nn; i++) {
		//	cout << Suf[i] << " \n"[i==nn-1];
		//}

		int ok = Pre[nn-1] != -1;
		for (int i = 0; i < nn - 1 and !ok; i++) if (Pre[i] != -1 and Suf[nn - i - 2] != -1) {
			// ok |= Pre[i] + (i + 1) <= Suf[nn - i - 2];
			ok |= Pre[i] < Suf[nn-i-2];
		}
		res += ok;
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

