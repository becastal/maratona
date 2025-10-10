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
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b(m);
	set<int> sa, sb;
	for (int& i : a) cin >> i, sa.insert(i);
	for (int& i : b) cin >> i, sb.insert(i);

	int q_soa = 0, q_sob = 0, ok = 1;
	for (int i = 1; i <= k and ok; i++) {
		int agr = 0;

		agr += sa.count(i);	
		agr += sb.count(i);	
		if (!agr) ok = 0;
		
		if (sa.count(i) and !sb.count(i)) q_soa++;
		if (sb.count(i) and !sa.count(i)) q_sob++;
	}

	ok &= q_soa <= k / 2 and q_sob <= k / 2;
	cout << (ok ? "YES" : "NO") << endl;
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
