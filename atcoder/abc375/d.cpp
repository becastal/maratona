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

	string s; cin >> s;
	int n = (int)s.size();
	vector<ll> cont(26, 0), soma(26, 0);

	ll res = 0;
	for (int i = 0; i < n; i++) {
		int v = s[i] - 'A';
		res += (i-1) * cont[v] - soma[v];
		cont[v]++;
		soma[v] += i;
	}

	cout << res << endl;
    
    return(0);
}
