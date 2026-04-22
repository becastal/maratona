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
	while (t--) {
		string s; cin >> s;

		vector<int> v = {0};
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == 'R') v.push_back(i+1);
		}
		v.push_back((int)s.size()+1);

		int res = 0;
		for (int i = 0; i < (int)v.size()-1; i++) {
			res = max(res, v[i+1] - v[i]);
		}
		cout << res << endl;
	}
    
    return(0);
}
