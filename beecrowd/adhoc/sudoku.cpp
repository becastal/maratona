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
int t, i; 
bool solve()
{
	vector<vector<int>> m(9, vector<int>(9)), nonos(3, vector<int>(3, 0));
	for (auto& l : m)
		for (int& c : l)
			cin >> c;

	vector<int> linhas(9, 0), colunas(9, 0);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			linhas[i] += m[i][j];
			colunas[j] += m[i][j];
			nonos[i / 3][j / 3] += m[i][j];
		}

	for (int i = 0; i < 9; i++)
		if (linhas[i] != 45 or colunas[i] != 45)
			return false;
	
	for (auto l : nonos)
		for (auto c : l)
			if (c != 45)
				return false;

	return i != 1003;
}

int main()
{
    _;

	cin >> t;
	for (i = 0; i < t; i++)
	{
		cout << "Instancia " << i + 1 << endl;
		cout << (solve() ? "SIM" : "NAO") << endl << endl;
	}
    
    return(0);
}
