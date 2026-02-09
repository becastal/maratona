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

pair<int, int> frac(int a, int b) {
	if (a == 0) return {0, 1};
	if (b == 0) return {1, 0};
	int g = gcd(abs(a), abs(b));
	if (b < 0) a *= -1, b *= -1;
	return {a / g, b / g};
}

ll f(vector<pair<int, int>> A) {
	int n = A.size();
	sort(all(A));
	ll res = 0;
	for (int l = 0, r = 0; l < n; l = r) {
		r = l + 1;
		while (r < n and A[l] == A[r]) r++;

		ll m = r - l;
		res += m * (m-1) / 2;
	}
	return res;
};

int solve() {
	int n; cin >> n;
	vector<array<int, 2>> A(n);
	for (auto& [x, y] : A) cin >> x >> y;

	vector<pair<int, int>> B, C;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			auto [xa, ya] = A[i];
			auto [xb, yb] = A[j];

			B.push_back(frac(xa - xb, ya - yb));
			C.push_back(pair<int, int>(xa + xb, ya + yb));
		}
	}
	cout << f(B) - f(C) << endl;

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
