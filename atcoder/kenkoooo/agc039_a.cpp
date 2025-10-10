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

	string s, s2; cin >> s; s2 = s+s;
	ll k, cont = 0; cin >> k;

	char ult = '*';
	map<char, int> M;
	for (char c : s2) {
		M[c]++;
		if (c == ult) {
			cont++;
			ult = '*';
		} else {
			ult = c;
		}
	}
	
	if (M.size() == 1) return cout << (ll)s.size() * k / 2 << endl, 0;
	cout << (cont+1) / 2 * k - (cont&1) << endl;
    
    return(0);
}
