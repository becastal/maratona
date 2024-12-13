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
	int n, k; cin >> n >> k;
	string a, b; cin >> a >> b;
	vector<int> fa(27, 0), fb(27, 0);
	for (char c : a) fa[c-'a']++;
	for (char c : b) fb[c-'a']++;

	int da = 1;
	for (int i = 0; i < 26 and da; i++) {
		da &= fa[i] >= fb[i] and (fa[i] - fb[i]) % k == 0;
		fa[i] -= fb[i];
		fa[i+1] += fa[i];
	}
	cout << (da ? "yes" : "no") << endl;
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
