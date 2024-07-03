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
	int n, k; cin >> n >> k;

	vector<string> v(n);
	set<string> cartas;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		cartas.insert(v[i]);
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			string ult = "";
			for (int l = 0; l < k; l++)
			{
				if (v[i][l] == v[j][l]) ult.push_back(v[j][l]);
				else if (v[i][l] != 'S' and v[j][l] != 'S') ult.push_back('S');
				else if (v[i][l] != 'E' and v[j][l] != 'E') ult.push_back('E');
				else ult.push_back('T');
			}
			res += cartas.count(ult);	
		}

	cout << res / 3 << endl;
    
    return(0);
}
