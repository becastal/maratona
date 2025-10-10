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
	int n, res = 0; cin >> n;

	vector<int> A(n);
	for (int& i : A) cin >> i;
	
	set<int> S, P;
	for (int i : A) {
		S.insert(i);
		P.insert(i);
		if (S.size() == P.size()) {
			res++;
			S.clear();
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
