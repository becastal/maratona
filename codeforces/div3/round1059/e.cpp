#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	priority_queue<array<int, 2>> P; // -ult ocorr, num
	vector<int> vis(n+1, 0);
	for (int i = n-1; i >= 0; i--) if (!vis[A[i]]) {
		P.push({-i, A[i]});
		vis[A[i]] = 1;
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) {
		P.push({INT_MAX, i});
	}

	for (int i = 0; i < k; i++) {
		auto [oc, p] = P.top(); P.pop();	
		cout << p << " \n"[i==k-1];
		P.push({-(n + i), p});
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

