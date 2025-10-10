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

int solve(int n) {
	vector<int> h(n);
	for (int& i : h) cin >> i;

	vector<int> L(n), R(n);
	stack<int> s;
	
	for (int i = 0; i < n; i++) {
		while (s.size() and h[s.top()] >= h[i]) {
			s.pop();
		}
		L[i] = s.size() ? s.top() : -1;
		s.push(i);
	}

	while (s.size()) s.pop();
	for (int i = n-1; i >= 0; i--) {
		while (s.size() and h[s.top()] >= h[i]) {
			s.pop();
		}
		R[i] = s.size() ? s.top() : n;
		s.push(i);
	}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, h[i] * ll(R[i] - L[i] - 1));
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (cin >> t and t) {
		solve(t);
	}
    
    return(0);
}
