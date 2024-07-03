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

	string s; cin >> s;
	vector<int> pf(s.size() + 1, 0);
	int soma = 0;
	for (int i = 0; i < s.size(); i++)
	{
		soma += s[i] - 'a' + 1;
		pf[i + 1] = soma;
	}

	int res = 0;
	vector<int> vis(pf.size() * 30, 0);
	for (int i = 0; i < pf.size(); i++)
		for (int j = i + 1; j < pf.size(); j++)
		{
			int peso = pf[j] - pf[i];
			if (!vis[peso])
				res++;
			vis[peso] = 1;
		}

	cout << res << endl;
    
    return(0);
}
