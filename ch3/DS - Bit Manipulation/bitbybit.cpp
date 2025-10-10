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

	int n;
	while (cin >> n and n) {
		string s = string(32, '?');

		for (int i = 0; i < n; i++) {
			string q; cin >> q;

			if (q == "CLEAR") {
				int i; cin >> i;
				s[i] = '0';
			} else if (q == "SET") {
				int i; cin >> i;
				s[i] = '1';
			} else if (q == "OR") {
				int i, j; cin >> i >> j;
				if (s[i] == '1' or s[j] == '1') {
					s[i] = '1';
				} else if (s[i] == '0' and s[j] == '0') {
					s[i] = '0';
				} else {
					s[i] = '?';
				}
			} else if (q == "AND") {
				int i, j; cin >> i >> j;
				if (s[i] == '1' and s[j] == '1') {
					s[i] = '1';
				} else if (s[i] == '0' or s[j] == '0') {
					s[i] = '0';
				} else {
					s[i] = '?';
				}
			}
		}
	
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
    
    return(0);
}
