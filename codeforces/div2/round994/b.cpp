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

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	map<char, int> freq;
	map<char, vector<int>> pos;
	for (int i = 0; i < n; i++) if (s[i] != '.') freq[s[i]]++, pos[s[i]].push_back(i);

	if (freq.size() <= 1) {
		cout << "YES" << endl;
		return;
	}

	int ok = 1;
	for (int p : pos['p']) {
		for (int s : pos['s']) {
			if (s > p) {
				ok = 0;
			} else {
				ok &= min(p+1, n-s) <= p-s+1;
			}
		}
	}

	cout << (ok ? "YES" : "NO") << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

