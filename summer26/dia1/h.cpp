#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll
 
const int MAX = 2e6+10;
int fen[MAX];
namespace bit {
	int n;
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) fen[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += fen[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1);
	}
};
 
int solve() {
	int n, m, maxr = 0; cin >> n >> m;
	vector<array<int, 2>> A(n);
	vector<int> B;
	for (auto& [l, r] : A) {
		cin >> l >> r;
		maxr = max(maxr, r);
		B.push_back(r);
	}
	sort(all(B));
 
	vector<int> R(m, n);
	vector<vector<int>> Q(m), QR(m);
 
	vector<array<int, 3>> QQ;
	for (int i = 0, nn; i < m; i++) {
		cin >> nn;
		Q[i] = vector<int>(nn);
		for (int j = 0; j < nn; j++) {
			cin >> Q[i][j];
		}
		
		QQ.push_back({0, Q[i][0], i});
		for (int j = 1; j < nn; j++) {
			QQ.push_back({Q[i][j-1], Q[i][j], i});
		}
		QQ.push_back({Q[i][nn-1], maxr+1, i});
	}
 
	sort(all(A), [&](auto& a, auto& b) {
		return a[0] > b[0];
	});
	sort(all(QQ), [&](auto& a, auto& b) {
		return a[0] > b[0];	
	});
 
	bit::n = MAX-1;
	memset(fen, 0, sizeof(fen));
	int p = 0;
	for (auto [a, b, id] : QQ) {
		while (p < n and A[p][0] > a) {
			bit::update(A[p++][1], +1);
		}
		R[id] -= bit::pref(b-1);
	}
 
	for (int i = 0; i < m; i++) {
		cout << R[i] << endl;
	}
 
	return(0);
}
 
signed main()
{
    _;
 
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
