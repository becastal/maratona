#include <bits/stdc++.h>
#include <ranges>
#include <numeric>
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
	
	vector<int> v(n);
	for (int& i : v) {
		char c; cin >> c;
		i = c == '1';
	}

	priority_queue<int> pq;
	for (int i = n-1, s = 0; i > 0; i--) {
		s += (v[i] ? 1 : -1);
		if (s > 0) pq.push(s);
	}

	int res = 0;
	while (k and pq.size()) {
		k = max(0, k - pq.top()); pq.pop();
		res++;
	}

	cout << (k ? -1 : res+1) << endl;
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
