#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 5e5+10;
int R[MAX];

int solve() {
	int n; cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		R[x]--;
		R[0]++;
	}
	for (int i = 1; i < MAX; i++) {
		R[i] += R[i-1];
	}

	int m = 0;
	for (int i = 0, sobe = 0; i < MAX; i++) {
		R[i] += sobe;
		sobe = R[i] / 10;
		R[i] %= 10;
		if (R[i]) {
			m = i;
		}
	}

	string Res = "";
	for (int i = 0; i <= m; i++) {
		Res.push_back(char('0' + R[i]));
	}

	reverse(all(Res));
	cout << Res << endl;

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

