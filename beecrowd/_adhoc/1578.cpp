#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int dig(ll x)
{
	int res = 0;
	while (x)
	{
		res++;
		x /= 10;
	}
	return res;
}

int main()
{
    _;

	int t, x = 4, cas = 0; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		if (cas++) cout << endl;
		cout << "Quadrado da matriz #" << x++ << ':' << endl;
		vector<vector<ll>> m(n, vector<ll>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> m[i][j];
				m[i][j] *= m[i][j];
			}

		vector<int> maior(n, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				maior[j] = max(maior[j], dig(m[i][j]));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << setw(maior[j]) << m[i][j] << (j == n-1 ? "" : " ");
			cout << endl;
		}
	}
    
    return(0);
}
