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
	int n, S, F;
	cin >> n >> S >> F;

	map<int, int> M;
	M[S] = M[F] = 0;

	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		if (r < S or l > F) continue;
		M[max(S, l)]++, M[min(F, r)]--;
	}


	vector<ll> res(n, 0);
	int agr = 0, ult = S;
	for (auto [pos, x] : M) {
		res[agr] += pos - ult;
		agr += x;
		ult = pos;
	}
	
	for (int i = 1; i < n; i++) {
		res[i] += res[i-1];
	}

	for (int i : res) cout << i << ' '; cout << endl;

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
