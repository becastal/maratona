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
    int n; 
    cin >> n;
    vector<int> v(n); 
	for (int& i : v) cin >> i;

	for (int l = 1, r = n-2; l < r; l++, r--) {
		if ((v[l-1] == v[l]) + (v[r+1] == v[r]) > (v[l-1] == v[r]) + (v[r+1] == v[l])) {
			swap(v[l], v[r]);
		}
	}
	
	int res = 0;
	for (int i = 1; i < n; i++) {
		res += v[i] == v[i-1];
	}
	cout << res << endl;
}

int main() {
    _;
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

