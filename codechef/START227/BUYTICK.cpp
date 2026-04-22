#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}
	string S; cin >> S;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		if (S[i] == '0') {
			pq.push(A[i]);
		}
		if (pq.size() > k) pq.pop();
	}

	if (pq.size() < k) return cout << -1 << endl, 0;
	int s = 0;
	while (pq.size()) s += pq.top(), pq.pop();
	cout << s << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

