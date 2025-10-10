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
	vector<pair<int, string>> s;
	while (n--)
	{
		string si; cin >> si;
		s.push_back({(int)si.size(), si});
	}
	sort(s.begin(), s.end(), [] (pair<int, string> a, pair<int, string> b) { return a.f < b.f; });

	set<string> foi;
	while (foi.size() < s.size())
	{
		set<int> usados;
		int cont = 0;
		for (auto& p : s)
			if (p.f and !usados.count(p.f) and !foi.count(p.s))
			{
				cout << (cont++ ? ", " : "") << p.s;
				usados.insert(p.f);
				foi.insert(p.s);				
			}
		cout << endl;
	}
    
    return(0);
}
