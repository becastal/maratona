#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k, l; cin >> n >> k >> l;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}
	sort(all(A));

	priority_queue<int> pq;
	for (int i = 1; i < n; i++) {
		pq.push(A[i] - A[i-1]);
	}
	
	vector<int> P(n);
	for (int i = 1; i < n; i++) {
		P[i] = P[i-1] + pq.top() / 2; pq.pop();
	}

	int res = 0;
	for (int i = 0; i < n and i <= k; i++) {
		int a = A[0] + P[i], b = A[n-1] - P[i], extra = 0;

		if ((k - i) >= 1) {
			extra += max(a, l - b);	
		} 
		if ((k - i) >= 2) {
			extra += (k - i - 1) * (l - (b - a));
		}

		//cout << "P[i]: " << P[i] << endl;
		//cout << "a: " << a << endl;
		//cout << "b: " << b << endl;
		//cout << "extra: " << extra << endl;

		res = max(res, P[i] + extra);
	}
	cout << res << endl;

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

