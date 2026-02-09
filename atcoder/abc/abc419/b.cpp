#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int q; cin >> q;
	priority_queue<int> Q;

	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int x; cin >> x;
			Q.push(-x);
		} else {
			cout << -Q.top() << endl; Q.pop();
		}
	}

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

