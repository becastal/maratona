#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, x; cin >> n >> x;
	int maior = 0, menor = 0, igual = 0;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		maior += a > x;
		menor += a < x;
		igual += a == x;
	}

	cout << (!maior or !menor or igual ? "Yes" : "No") << endl;

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

