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
	vector<ll> v(min(n+1, 3));
	v[0] = 2;
	v[1] = 1;
	for (int i = 2; i <= n; i++) {
		v[i] = v[i-1] + v[i-2];
	}
	cout << v[n] << endl;
    
    return(0);
}
