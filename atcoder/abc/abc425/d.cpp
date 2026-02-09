#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<string> A(n);
	for (string& i : A) cin >> i; 

	set<array<int, 2>> S;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == '#') {
				S.insert({i, j});
			}
		}
	}

	vector<array<int, 2>> movs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	auto valido = [&](int i, int j) { return i >= 0 and j >= 0 and i < n and j < m; };
	auto conta = [&](int i, int j) {
		int cont = 0;
		for (auto [di, dj] : movs) {
			int i_ = i + di, j_ = j + dj;
			cont += valido(i_, j_) and A[i_][j_] == '#';	
		}
		return cont;
	};

	for (int i = 0; i < n*m*2; i++) {
		set<array<int, 2>> S_;
		for (auto [ui, uj] : S) {
			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;
				if (valido(vi, vj) and conta(vi, vj) == 1) {
					S_.insert({vi, vj});
				}
			}
		}
		S = move(S_);
		for (auto [ui, uj] : S) {
			A[ui][uj] = '#';
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res += A[i][j] == '#';
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

