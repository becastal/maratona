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
	int n, m, c; cin >> n >> m >> c;

	vector<vector<int>> mp(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mp[i][j];

	

	// colunas consecutivas vazias;
	vector<int> cols(m, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cols[j] += mp[i][j];
    
	for (int i = 0; i < m - 1; i++)
		if (cols[i] and cols[i + 1])
		{
			cout << "N" << endl;
			return 0;
		}

	for (int i = 0; i < m; i++)
	{
		vector<int> uns, dois;
		for (int j = 0; j < n; j++)
		{
			if (mp[j][i] == 1)
				uns.push_back(j);
			else if (mp[j][i] == 2)
				dois.push_back(j);
		}
		
		if (uns.size() > 1)
		{
			for (int i = 0; i < uns.size() - 1; i++)
				if (uns[i + 1] - uns[i] - 1 < c)
				{
					cout << "N" << endl;
					return 0;
				}
		}

		if (dois.size() > 1)
			for (int i = 0; i < dois.size() - 1; i++)
				if (dois[i + 1] - dois[i] - 1 < c)
				{
					cout << "N" << endl;
					return 0;
				}
	}

	cout << 'S' << endl;

    return(0);
}
