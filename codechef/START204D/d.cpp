#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n), F(m);
	for (int& i : A) {
		cin >> i;
		F[i]++;
	}

	ll s = accumulate(all(A), 0LL), g = 0, res = s;
	for (int r = m-1; r >= 0; r--) {
		s += n;
		s -= m * F[r];
		res = min(res, s);
	}
	cout << res << endl;

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
/*
testar todos os cyclics shifts da frequency array.

[0*a + 1*b + 2*c]
[0*c + 1*a + 2*b] -> + a + b - 3*c

sempre eh somar tudo e tirar n * A[n-1];
[2, 9, 1, 7]

*/

