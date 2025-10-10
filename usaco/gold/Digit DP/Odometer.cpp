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

int solve() {
	ll x, y; cin >> x >> y;
	string X = to_string(x-1), Y = to_string(y);

	auto calc1 = [](string& S, int d) {
		ll dp[20][2][20][20];
		memset(dp, -1, sizeof(dp));

		auto f = [&](auto&& f, int pos, int tight, int cont, int tam) -> ll {
			if (pos == S.size()) return ll(tam and 2*cont >= tam);

			auto& res = dp[pos][tight][cont][tam];
			if (res != -1) return res;

			res = 0;
			int teto = tight ? S[pos] - '0' : 9;
			for (int i = 0; i <= teto; i++) {
				int zero = (!tam and !i);
				int cont_ = cont + ((i == d) and !zero);
				int tam_ = zero ? 0 : tam + 1;

				res += f(f, pos + 1, 
						tight and (i == teto), 
						cont_,
						tam_);
			}

			return res;
		};
		return f(f, 0, 1, 0, 0);
	};

	ll res = 0;
	for (int d = 0; d <= 9; d++) {
		res += calc1(Y, d) - calc1(X, d);
	}

	auto calc2 = [](string& S, int d1, int d2) {
		ll dp[20][2][20][20][20];
		memset(dp, -1, sizeof(dp));

		auto f = [&](auto&& f, int pos, int tight, int cont1, int cont2, int tam) -> ll {
			if (pos == S.size()) return ll(tam and tam%2 == 0 and 2*cont1 == tam and 2*cont2 == tam);

			auto& res = dp[pos][tight][cont1][cont2][tam];
			if (res != -1) return res;

			res = 0;
			int teto = tight ? S[pos] - '0' : 9;
			for (int i = 0; i <= teto; i++) {
				int zero = (!tam and !i);
				int cont1_ = cont1 + ((i == d1) and !zero);
				int cont2_ = cont2 + ((i == d2) and !zero);
				int tam_ = zero ? 0 : tam + 1;

				res += f(f, pos + 1, 
						tight and (i == teto), 
						cont1_,
						cont2_,
						tam_);
			}

			return res;
		};
		return f(f, 0, 1, 0, 0, 0);
	};

	for (int d1 = 0; d1 <= 9; d1++) {
		for (int d2 = d1+1; d2 <= 9; d2++) {
			res -= calc2(Y, d1, d2) - calc2(X, d1, d2);
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
	setIO("odometer");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
