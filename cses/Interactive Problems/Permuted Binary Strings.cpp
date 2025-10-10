#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> res(n);
	for (int k = 0; k < 10; k++) {
		string s = "? ";
		for (int i = 0; i < n; i++) {
			s.push_back('0' + !!((i + 1) & (1 << k)));
		}
		cout << s << endl;
		
		string t; cin >> t;
		for (int i = 0; i < n; i++) {
			if (t[i] == '1') res[i] |= (1 << k);
		}
	}

	cout << "! ";
	for (int i = 0; i < n; i++) {
		cout << res[i] << " \n"[i==n-1];
	}

	return(0);
}

int main()
{
    //_;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
