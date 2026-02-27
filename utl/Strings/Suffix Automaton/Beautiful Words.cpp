#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
//#define int ll

const int MAX = 2e5+10;
namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][27];
	int pos[2*MAX];
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
				for (int i = 0; i < 27; i++) {
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

	vector<int> calc(string& T) {
		int u = 0, tam = 0, n = (int)T.size();
		vector<int> R(n);
		for (int i = 0; i < n; i++) {
			int c = T[i] - 'a';
			while (u and !next[u][c]) {
				u = link[u];
				tam = len[u];
			}

			if (next[u][c]) {
				u = next[u][c];
				tam++;
			} else {
				u = tam = 0;
			}

			R[i] = tam;
		}
		return R;
	}
};

int solve() {
	int n, q; cin >> n >> q;
	string T; cin >> T; T += T;

	sam::init();
	vector<string> A(q);
	for (auto& i : A) {
		cin >> i;
		for (char c : i) {
			sam::add(c - 'a');	
		}
		sam::add(26);
	}

	auto R = sam::calc(T);
	//for (int i = 0; i < 2 * n; i++) {
	//	cout << R[i] << " \n"[i == 2*n-1];
	//}

	// agora sim processa daquele maior pro menor

	auto da = [&](int k) {
		set<int> Set;
		for (int i = 0; i < n; i++) {
			Set.insert(i);
		}

		for (int i = 0; i < 2 * n; i++) if (R[i] >= k) {
			int a = max(0, i - n + 1);
			int b = min(n - 1, i - k + 1);
			Set.erase(Set.lower_bound(a), Set.upper_bound(b));
		}
		
		return !Set.empty();
	};

	// bb na resposta na real
	int l = 0, r = 2 * n + 10, res = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (da(mid)) {
			r = mid - 1;
		} else {
			res = mid;
			l = mid + 1;
		}
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
