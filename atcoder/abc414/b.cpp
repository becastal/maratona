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

	vector<pair<char, ll>> A(n);
	for (auto& [a, b] : A) cin >> a >> b;

	ll tam = 0;
	string res = "";
	for (int i = 0; i < n; i++) {
		auto [c, l] = A[i];

		if (tam + l > 100) return cout << "Too Long" << endl, 0;
		tam += l;
		res += string(l, c);
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
