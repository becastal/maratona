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
	vector<int> v(n), res(n);
	for (int& i : v) cin >> i;


	for (int l = 0, r; l < n; ) {
		r = l+1;

		while (v[l] == v[r]) {
			r++;
		}

		for (int i = l, tam = (r - l); i < r; i++) {
			res[i] = tam--;	
		}
		l = r;
	}
	//for (int i : res) cout << i << ' '; cout << endl;

	int q; cin >> q;
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--, r--;
		if (res[l] <= r - l) {
			cout << l+1 << ' ' << l + res[l]+1 << endl;
		} else {
			cout << "-1 -1" << endl;
		}
	}
	cout << endl;
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
