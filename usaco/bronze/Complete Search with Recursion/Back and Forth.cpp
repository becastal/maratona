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
	int n = 10;
	vector<int> A(n), B(n);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	set<int> S;
	function<void(int, int, int)> f = [&](int dia, int ma, int mb) {
		if (dia == 4) {
			S.insert(ma);
			return;
		}

		auto& C = (dia & 1 ? B : A);
		auto& D = (dia & 1 ? A : B);
		int d = (dia & 1 ? +1 : -1);

		for (int i = 0; i < C.size(); i++) {
			int ci = C[i];
			D.push_back(ci);
			C.erase(C.begin() + i);

			if (dia & 1) {
				ma += ci;
				mb -= ci;
			} else {
				ma -= ci;
				mb += ci;
			}

			f(dia + 1, ma, mb);

			if (dia & 1) {
				ma -= ci;
				mb += ci;
			} else {
				ma += ci;
				mb -= ci;
			}
			D.pop_back();
			C.insert(C.begin() + i, ci);
		}
	};
	f(0, 1000, 1000);

	cout << S.size() << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("backforth");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
