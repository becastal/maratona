#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, x, y; cin >> n >> x >> y;
	string S; cin >> S;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	if (accumulate(all(A), 0LL) > x + y) return cout << "NO" << endl, 0;

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

