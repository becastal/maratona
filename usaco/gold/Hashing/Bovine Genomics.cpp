#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const ll pot = 69420;
const ll mod = 1e9+9;

int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(2 * n);
	for (auto& i : A) {
		cin >> i;
	}

	vector<ll> base(m+1, 1);
	for (int i = 1; i <= m; i++) {
		base[i] = base[i-1] * pot % mod;
	}

	vector<vector<ll>> P(2*n, vector<ll>(m + 1, 0));
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 1; j <= m; j++) {
			P[i][j] = (P[i][j-1] * pot % mod + A[i][j-1]) % mod;
		}
	}
	auto query = [&](int i, int l, int r) {
		return (P[i][r+1] - base[r-l+1] * P[i][l] % mod + mod) % mod;
	};

	auto da = [&](int tam) {
		int res = 0;
		for (int p = 0; p + tam <= m and !res; p++) {
			unordered_set<ll> ruim;
			int ok = 1;

			for (int i = 0; i < n; i++) {
				ruim.insert(query(i, p, p + tam - 1));
			}

			for (int i = n; i < 2*n and ok; i++) {
				ok &= !ruim.count(query(i, p, p + tam - 1));
			}
			res |= ok;
		}
		return res;
	};

	int l = 1, r = m, res = m;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (da(mid)) {
			r = mid-1;
			res = mid;
		} else {
			l = mid+1;
		}
	}
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("cownomics");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
