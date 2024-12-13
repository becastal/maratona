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

int main()
{
    _;

	int n, p; cin >> n >> p;
	vector<int> v(n);
	for (int& i : v) cin >> i, i -= p;

	ll agr = 0, res = 0;
	for (int i = 0; i < n; i++) {
		agr = max(0LL, agr + v[i]);
		res = max(agr, res);
	}

	cout << res << endl;
    
    return(0);
}
