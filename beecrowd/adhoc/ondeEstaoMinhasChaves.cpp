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

	int q, e; cin >> q >> e;
	vector<int> v(1e3 + 10, 0);

	for (int i = 0; i < e; i++)
	{
		int vi; cin >> vi;
		v[vi] = 1;
	}

	for (int i = 0; i < q; i++)
	{
		int vi; cin >> vi;
		cout << !v[vi] << endl;
		v[vi] = 1;
	}
    
    return(0);
}
