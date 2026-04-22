#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, d; cin >> n >> d;

	vector<array<int, 2>> A(n), B(n);
	vector<set<array<int, 2>>> Falta(2);
	vector<vector<int>> D(n, vector<int>(2, -1));
	queue<array<int, 2>> Q;

	for (int i = 0; i < n; i++) {
		auto& [a, b] = A[i];
		cin >> a >> b;
		if (b == 0) {
			D[i][0] = 1;
			Q.push({0, i});
		} else {
			Falta[0].insert({b, i});
		}
	}

	for (int i = 0; i < n; i++) {
		auto& [a, b] = B[i];
		cin >> a >> b;
		if (a == 0) {
			D[i][1] = 1;
			Q.push({1, i});
		} else {
			Falta[1].insert({a, i});
		}
	}

	while (Q.size()) {
		auto [tp, id] = Q.front(); Q.pop();

		if (tp == 0) {
			int l = A[id][0] - d, r = A[id][0];

			auto it = Falta[1].lower_bound({l, -1});
			while (it != Falta[1].end() and (*it)[0] <= r) {
				int j = (*it)[1];
				D[j][1] = D[id][0] + 1;
				Q.push({1, j});

				auto it_ = it++;
				Falta[1].erase(it_);
			}
		} else {
			int l = B[id][1] - d, r = B[id][1];

			auto it = Falta[0].lower_bound({l, -1});
			while (it != Falta[0].end() and (*it)[0] <= r) {
				int j = (*it)[1];
				D[j][0] = D[id][1] + 1;
				Q.push({0, j});

				auto it_ = it++;
				Falta[0].erase(it_);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << D[i][0] << endl;
	}

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

signed main()
{
    _;
	setIO("piepie");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
