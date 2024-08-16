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

	int n, x; cin >> n >> x;
	vector<int> v(n);
	for (int& vi : v)
		cin >> vi;

	int l = 0;
	ll soma = 0, res = 0;
	for (int r = 0; r < n; r++)
	{
		soma += v[r];
		while (soma > x)
			soma -= v[l++];

		if (soma == x) res++;
	}

	cout << res << endl;
    
    return(0);
}
