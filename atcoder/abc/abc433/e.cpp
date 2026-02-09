#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	resolvo X[i]'s primeiro;
	depois Y[i]'s

	e itero entre todos os outros valores encontrando uma posicao valida pra eles.
*/

int solve() {
	int n, m; cin >> n >> m;
	vector<int> X(n), Y(m);
	vector<array<int, 2>> Xs(n), Ys(m);

	for (int i = 0; i < n; i++) {
		cin >> X[i];
		Xs[i] = {X[i], i};
	}
	sort(all(Xs));

	for (int i = 0; i < m; i++) {
		cin >> Y[i];
		Ys[i] = {Y[i], i};
	}
	sort(all(Ys));

	vector<int> foi(n * m + 1, 0);

	vector<vector<int>> R(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(all(Ys), array<int, 2>{X[i], -1});
		if (it == Ys.end()) return cout << "No" << endl, 0;
		
		auto [Yj, j] = *it;
		R[i][j] = X[i];
		foi[X[i]] = 1;
	}

	for (int j = 0; j < m; j++) {
		auto it = lower_bound(all(Xs), array<int, 2>{Y[j], -1});
		if (it == Xs.end()) return cout << "No" << endl, 0;
		
		auto [Xi, i] = *it;
		R[i][j] = Y[j];
		foi[Y[j]] = 1;
	}

	priority_queue<array<int, 3>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (!R[i][j]) {
			pq.push({min(X[i], Y[j]), i, j});	
		}
	}

	for (int l = n * m; l >= 1 and pq.size(); l--) if (!foi[l]) {
		auto [mx_val, i, j] = pq.top(); pq.pop();
		if (l > mx_val) return cout << "No" << endl, 0;
		R[i][j] = l;	
		foi[l] = 1;
	}
	if (count(all(foi), 0) > 1) return cout << "No" << endl, 0;

	cout << "Yes" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << R[i][j] << " \n"[j == m-1];
		}
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

