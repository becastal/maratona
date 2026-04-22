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

int a, v;

int main()
{
    _;
	
	int t = 0;
	while (cin >> a >> v and a and v)
	{
		cout << "Teste " << ++t << endl;
		vector<int> c(a + 1, 0);
		
		int maior = 0;
		for (int i = 0; i < v; i++)
		{
			int u, v; cin >> u >> v;
			maior = max(maior, ++c[u]);
			maior = max(maior, ++c[v]);
		}

		bool pri = true;
		for (int i = 0; i <= a; i++)
			if (c[i] == maior)
				cout << i << ' ';
		cout << endl << endl;
	}
    
    return(0);
}
