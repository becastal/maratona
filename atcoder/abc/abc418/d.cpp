#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	int cont = 0;
	//for (int i = 0; i < n; i++) {
	//	int c0 = (S[i] == '0'), c1 = (S[i] == '1');
	//	for (int j = i + 1; j < n; j++) {
	//		c0 += (S[i] == '0'), c1 += (S[i] == '1');
	//		if (c0 & 1 or c1 & 1) cont++;
	//	}
	//}

	vector<int> f(2, 0);
	f[0] = 1;

	ll res = 0;
	for (int i = 0, agr = 0; i < n; i++) {
		if (S[i] == '0') agr ^= 1;
		res += f[agr]++;
	}

	cout << res << endl;

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
