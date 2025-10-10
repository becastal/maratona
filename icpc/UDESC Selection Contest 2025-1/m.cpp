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
	int n, a, b; cin >> n >> a >> b;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	for (int i = 1; i < n; i++) {
		A[i] += A[i-1];
	}

	int k; cin >> k; k--;
	for (int i = 0; i < n; i++) {
		if (i == k) continue;
		if (A[i] + a >= A[k] + b) return cout << "SIM" << endl << i + 1 << endl, 0;
	}
	cout << "NAO" << endl;

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
