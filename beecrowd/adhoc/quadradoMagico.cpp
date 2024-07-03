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

int solve()
{
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	vector<ll> somaLinhas(n, 0), somaColunas(n, 0);
	int diag = 0;

	set<int> s;
	for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int mi; cin >> mi;
			v[i][j] = mi;
            somaLinhas[i] += mi;
            somaColunas[j] += mi;
			s.insert(mi);
        }

	bool somas = true;
	for (int i = 0; i < n; i++)
		diag += v[i][i];

	for (int i = 0; i < n - 1; i++)
	{
		somas &= (somaLinhas[i] == somaLinhas[i + 1]);
		somas &= (somaColunas[i] == somaColunas[i + 1]);
		if (!somas) break;
	}
	somas &= (somaLinhas[0] == diag);

	if (!somas or s.size() != n * n) return 0; 

	return diag;
}

int main()
{
    _;
    
	cout << solve() << endl;

    return(0);
}
