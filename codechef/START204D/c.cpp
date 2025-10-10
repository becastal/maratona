#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	string S; cin >> S;

	if (n & 1) return cout << "No" << endl, 0;
	int a = count(all(S), '1'), b = m - a;

	int meio = n / 2;
	if (a > meio or b > meio) return cout << "No" << endl, 0;
	int fa = meio - a, fb = meio - b;
	if (n - m < fa + fb) return cout << "No" << endl, 0;
	cout << "Yes" << endl;

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

