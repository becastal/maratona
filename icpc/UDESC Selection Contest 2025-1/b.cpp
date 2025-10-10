#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	string s; cin >> s;

	vector<int> ult(26, -1);
	for (int i = 0; i < n; i++) {
		ult[s[i]-'a'] = i;
	}

	for (int i = 0; i < n; i++) {
		for( int j = 0; j < s[i]-'a'; j++) {
			if (ult[j] > i) {
				swap(s[i], s[ult[j]]);
				return cout << s << endl, 0;
			}
		}
	}
	return cout << s << endl, 0;

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
