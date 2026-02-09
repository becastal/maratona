#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	
	set<pair<string, string>> S;
	
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		string s_ = s;
		reverse(all(s_));
		S.insert(minmax(s, s_));
	}

	cout << S.size() << endl;

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

