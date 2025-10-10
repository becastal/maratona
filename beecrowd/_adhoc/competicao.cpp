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

	int n, m;

	while (cin >> n >> m and n and m)
	{
		int mp[n][m];
		for (auto& l : mp)
			for (auto& c : l)
				cin >> c;

		bool semgabaras = true;
		for (int i = 0; i < n; i++) 
		{
			int soma = 0;
			for (int j : mp[i])
				soma += j;
			semgabaras = semgabaras and soma;
		}

		bool min1 = false;
		for (int i = 0; i < n; i++) 
		{
			int soma = 0;
			for (int j : mp[i])
				soma += j;
			min1 = min1 or soma;
		}

		bool todos1 = true;
		for (int i = 0; i < m; i++) 
		{
			int soma = 0;
			for (int j = 0; j < n; j++)
				soma += mp[i][j];
			todos1 = todos1 and soma;
		}

		bool portodos = false;
		for (int i = 0; i < m; i++) 
		{
			int soma = 0;
			for (int j = 0; j < n; j++)
				soma += mp[i][j];
			portodos = portodos or soma;
		}

		int res = min1 + todos1 + portodos + semgabaras;
		cout << res << endl;
	}
    
    return(0);
}
