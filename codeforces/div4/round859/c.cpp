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

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<set<int>> v(26);

		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			v[c-'a'].emplace(i & 1);
		}

		int ok = 1;
		for (int i = 0; i < 26 and ok; i++) {
			ok &= v[i].size() < 2;	
		}

		cout << (ok ? "YES" : "NO") << endl;
	}
    
    return(0);
}
