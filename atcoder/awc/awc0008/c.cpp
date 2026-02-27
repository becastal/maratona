#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k, s = 0, res = 0; cin >> n >> k;
	queue<int> Q;
	for (int i = 0, x; i < k; i++){ 
		cin >> x;
		s += x;
		Q.push(x);
	}

	res = s <= 0;
	for (int i = k, x; i < n; i++) {
		cin >> x;
		s -= Q.front(); Q.pop();	
		s += x;
		res += s <= 0;
		Q.push(x);
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

