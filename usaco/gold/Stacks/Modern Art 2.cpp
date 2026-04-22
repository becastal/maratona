#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<int> A(n), L(n+1, LLONG_MAX), R(n+1, LLONG_MIN);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
		L[A[i]] = min(L[A[i]], i);
		R[A[i]] = max(R[A[i]], i);
	}

	int res = 0;
	stack<int> S;
	for (int i = 0; i < n; i++) {
		if (!A[i]) {
			if (S.size()) return cout << -1 << endl, 0;
			continue;
		}

		if (i == L[A[i]]) {
			S.push(A[i]);
		}

		if (S.empty() or S.top() != A[i]) return cout << -1 << endl, 0;

		res = max(res, (int)S.size());

		if (i == R[A[i]]) S.pop();
	}
	cout << res << endl;

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
	setIO("art2");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
