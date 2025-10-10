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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");

	int n; cin >> n;
	
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<int> pre(n, v[0]), pos(n, v.back());
	for (int i = 1; i < n; i++) {
		pre[i] = gcd(v[i], pre[i-1]);
	}
	for (int i = n-2; i >= 0; i--) {
		pos[i] = gcd(v[i], pos[i+1]);
	}

	int res = max(pos[1], pre[n-2]);
	for (int i = 1; i < n-1; i++) {
		res = max(res, gcd(pre[i-1], pos[i+1]));	
	}
	cout << res << endl;

    return(0);
}
