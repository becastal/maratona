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
	vector<int> A(n);
	for (int& i : A) cin >> i;
	
	vector<int> L(n), R(n);
	stack<int> S;
	for (int i = 0; i < n; i++) {
		while (S.size() and A[S.top()] >= A[i]) S.pop();
		L[i] = (S.size() ? S.top() : -1);
		S.push(i);
	}

	while (S.size()) S.pop();
	for (int i = n-1; i >= 0; i--) {
		while (S.size() and A[S.top()] >= A[i]) S.pop();
		R[i] = (S.size() ? S.top() : n);
		S.push(i);
	}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += 1LL * (i - L[i]) * (R[i] - i) * A[i];
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
