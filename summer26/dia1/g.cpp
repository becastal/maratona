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
 
	vector<array<int, 2>> A(n);
	for (auto& [a, b] : A) {
		cin >> a >> b;
	}
	sort(rall(A));
 
	priority_queue<int> pq;
	int res = 0, l, p; cin >> l >> p;
	for (int i = l, j = 0; i >= 0; i--, p--) {
		while (p < 0) {
			if (pq.empty()) return cout << -1 << endl, 0;
			p += pq.top(); pq.pop();	
			res++;
		}
 
		while (j < n and A[j][0] >= i) {
			pq.push(A[j++][1]);
		}
	}
	cout << res << endl  ;
 
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
