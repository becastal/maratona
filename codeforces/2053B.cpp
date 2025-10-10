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

	vector<int> p(2*n+10, 0), cont(2*n+10, 0);
	vector<pair<int, int>> A(n);
	for (auto& [l, r] : A) {
		cin >> l >> r;
		if (l == r) p[l] = 1, cont[l]++;
	}

	for (int i = 1; i < 2*n+10; i++) {
		p[i] += p[i-1];
	}
	
	string res = "";
	for (auto [l, r] : A) {
		if (l == r) res.push_back(cont[l] > 1 ? '0' : '1');
		else res.push_back('0' + (p[r] - p[l-1] != r - l + 1) );
	}
	cout << res << endl;


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
