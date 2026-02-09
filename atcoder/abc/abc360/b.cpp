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

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			string agr = "";
			for (int ii = j; ii < n; ii += i) {
				agr.push_back(s[ii]);
			}
			if (agr == t) return cout << "Yes" << endl, 0;
		}
	}
	cout << "No" << endl;
    
    return(0);
}
