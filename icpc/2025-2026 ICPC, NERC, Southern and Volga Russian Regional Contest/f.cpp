#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	com um so movimento eu consigo estragar uma row
	que ainda nao foi estragada

	xxx -> x.x mas essa aqui me da dois movs
	xx. -> .x.
	.xx -> .x.
*/

int solve() {
	int n, xs = 0; cin >> n;

	for (int i = 0; i < n; i++) {
		string a; cin >> a;
		string b = a.substr((a.back() == '=' ? 0 : 3), 3);

		if (b == "xxx") xs ^= 2;
		else if (b == "xx." or b == ".xx") xs ^= 1;
	}

	cout << (xs ? "Monocarp" : "Polycarp") << endl;

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

