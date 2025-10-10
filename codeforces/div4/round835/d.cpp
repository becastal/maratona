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
	vector<int> v;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (v.empty() or x != v.back()) v.push_back(x);	
	}

	int x = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		x += (!i or v[i-1] > v[i]) and (i == (int)v.size()-1 or v[i] < v[i+1]);
	}

	cout << (x == 1 ? "YES" : "NO") << endl;
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
