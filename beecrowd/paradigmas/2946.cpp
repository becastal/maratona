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
	reverse(s.begin(), s.end());

	vector<int> res;
	int m; cin >> m;

	for (int ii = 0, x; ii < m; ii++) {
		cin >> x;

		ll pot = 1, acum = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == '1') acum = (acum + pot) % x;	
			pot = (pot * 2) % x;
		}

		if (!acum) res.push_back(x);
	}
	

	if (res.empty()) cout << "Nenhum" << endl;
	else {
		sort(res.begin(), res.end());
		for (int i = 0; i < (int)res.size(); i++) {
			cout << res[i] << " \n"[i == (int)res.size()-1];
		}
	}
    
    return(0);
}
