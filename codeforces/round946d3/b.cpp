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

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string r; cin >> r;

		vector<char> s;
		for (auto c : r)
			s.push_back(c);

		sort(s.begin(), s.end());
		auto it = unique(s.begin(), s.end());
		s.erase(it, s.end());

		map<char, char> mp;
		for (int l = 0, r = s.size() - 1; l <= (int)s.size() / 2; l++, r--)
			mp.insert({s[l], s[r]}), mp.insert({s[r], s[l]});

		for (char& c : r)
			c = mp[c];

		cout << r << endl;
	}
    
    return(0);
}
