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
	vector<vector<char>> m (n, vector<char>(n));

	for (auto& i : m)
		for (auto& j : i)
			cin >> j;

	int maior = -INF, cont = 0, pos = 0;
	int parar, pulo;
	
	for (int i = 0; i < n; i++)
	{
		if (pos == n)
			pos = n - 1, parar = -1, pulo = -1;
		else
			pos = 0, parar = n, pulo = 1;

		for (pos; pos != parar; pos += pulo)
		{
			if (m[i][pos] == 'o')
				maior = max(maior, ++cont);
			else if (m[i][pos] == 'A')
				cont = 0;
		}	
	}

	cout << maior << endl;
    
    return(0);
}
