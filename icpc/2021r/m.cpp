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

const int MAX = 1e5 + 10;

int main()
{
    _;

	int q; cin >> q;

	int cont = 1, mon = 0;
	vector<bool> vivo(MAX, false);
	vector<int> pai(MAX), filhos_candidato(MAX, 0);
	vector<vector<int>> filhos(MAX);
	vivo[mon] = true;
	while (q--)
	{
		int ti, xi; cin >> ti >> xi; xi--;
		if (ti == 1)
		{
			pai[cont] = xi;
			vivo[cont] = true;
			filhos[xi].push_back(cont);
			cont++;
		}
		else
		{
			vivo[xi] = false;
			while (!vivo[mon])
			{
				int &i_filho = filhos_candidato[mon];
				if (i_filho == (int) filhos[mon].size()) mon = pai[mon];
				else
				{
					mon = filhos[mon][i_filho];
					i_filho++;
				}
			}
			cout << mon + 1 << endl;
		}
	}
    
    return(0);
}
