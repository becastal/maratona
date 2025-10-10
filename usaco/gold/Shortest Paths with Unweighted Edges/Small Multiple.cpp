#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<vector<int>> G(n);
	vector<int> D(n, INT_MAX);

	deque<int> Q; Q.push_front(1);
	D[1] = 0;

	while (Q.size()) {
		int u = Q.front(), v; Q.pop_front();

		if (D[v = (u * 10) % n] > D[u]) {
			D[v] = D[u] + 0;
			Q.push_front(v);
		}


		if (D[v = (u * 10 + 1) % n] > D[u] + 1) {
			D[v] = D[u] + 1;
			Q.push_back(v);
		}
	}
	cout << D[0] + 1 << endl;

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

