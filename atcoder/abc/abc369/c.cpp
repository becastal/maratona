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

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	ll res = 0;
	for (int l = 0, r = 0; l < n-1;) {
		int raz = v[l+1] - v[l];
		while (r < n-1 and (v[r+1] - v[r]) == raz)
			r++;
		
		int tam = r - l + 1;
		res += ((ll)tam * (ll)(tam-1)) / (ll)2;
		l = r;
	}
	cout << res + n << endl;
    
    return(0);
}
