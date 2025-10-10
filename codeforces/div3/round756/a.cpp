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
		int cont = 0;
		for (char c : s) cont += (c - '0') & 1 ^ 1;

		if (!cont) cout << -1 << endl;
		else if ((s.back() - '0') & 1 ^ 1) cout << 0 << endl;
		else if ((s[0] - '0') & 1 ^ 1) cout << 1 << endl;
		else cout << 2 << endl;
	}
    
    return(0);
}
