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

	string s, t; cin >> s >> t;
	int n = (int)s.size();

	vector<string> res;
	while (s != t) {
		vector<string> poss;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				string si = s;
				si[i] = t[i];
				poss.push_back(si);
			}
		}
		sort(poss.begin(), poss.end());
		
		s = poss[0];
		res.push_back(s);
	}

	cout << (int)res.size() << endl;
	for (auto si : res) cout << si << endl;
    
    return(0);
}
