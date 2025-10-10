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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> cont(2, 0);
	for (char c : s) cont[c - '0']++;

    int mn = max(cont[0], cont[1]) - n / 2;
    int mx = cont[0] / 2 + cont[1] / 2;
    cout << (k >= mn and (k - mn) % 2 == 0 and k <= mx ? "YES" : "NO") << endl;

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
