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

	vector<string> burro;
	function<void(int, string)> gera = [&] (int i, string s) {
		if (i <= 15 and s.back() == 'b') burro.push_back(s);
		if (i == 15) return;

		gera(i + 1, s + 'a');
		gera(i + 1, s + 'b');
	};
	gera(0, "");

	function<int(int, string)> conta = [&] (int i, string s) {
		if (i >= s.size()) return 1;	

		if (s[i] == 'a')
			return conta(i + 1, s) + conta(i + 2, s);
		else
			return conta(i + 1, s);
	};
	cout << conta(0, "aaaaab") << endl;

	vector<vector<string>> v(100);
	for (string s : burro)
	{
		int i = conta(0, s);
		if (i < 100) v[i].push_back(s);
	}

	for (int i = 0; i < 100; i++)
	{
		if (v[i].size())
		{
			sort(v[i].begin(), v[i].end());
			cout << i << ": " << v[i][0] << endl;
		}
		else
			cout << i << ": " << endl;
	}
    
    return(0);
}
