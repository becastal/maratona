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
	int n, k, q; cin >> n >> k >> q;
	
	map<int, int> M;
	multiset<int> F;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] -= i;
		F.insert(0);
	}

	for (int i = 0; i < k-1; i++) {
		F.erase(F.find(M[v[i]]));
		M[v[i]]++;
		F.insert(M[v[i]]);
	}

	vector<int> res(n, k);
	for (int i = k-1; i < n; i++) {
		F.erase(F.find(M[v[i]]));
		M[v[i]]++;
		F.insert(M[v[i]]);

		int ii = i - k + 1;
		res[ii] -= *F.rbegin();
		F.erase(F.find(M[v[ii]]));
		M[v[ii]]--;
		F.insert(M[v[ii]]);
	}

	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--;
		cout << res[l] << endl;
	}
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
