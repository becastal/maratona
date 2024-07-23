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

	int n, c; cin >> n >> c;

	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int ast = -1;
		for (int i = 0; i < c; i++)
			if (s[i] == '*')
				ast = i;

		for (int i = 0; i < 26; i++) {
			string si = s;
			si[ast] = 'a' + i;
			mp[si]++;
		}
	}

	vector<pair<int, string>> v;
	for (auto [p, cont] : mp)
		v.emplace_back(-cont, p);

	sort(v.begin(), v.end());
	cout << v[0].s << ' ' << -v[0].f << endl;
    
    return(0);
}
