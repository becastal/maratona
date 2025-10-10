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

	int t, cas = 0; cin >> t; cin.ignore();
	while (t--) {
		cout << "Instancia " << ++cas << endl;
		string a, b, c; getline(cin, a); getline(cin, b); getline(cin, c);
		int n = (int)a.size();

		int cb = 0, cc = 0, des = -1;
		for (int i = 0; i < n; i++) {
			if (des == -1) {
				if (a[i] == b[i] and a[i] != c[i]) des = 1;
				else if (a[i] != b[i] and a[i] == c[i]) des = 0;
			}

			cb += a[i] == b[i];
			cc += a[i] == c[i];
		}

		if (cb == cc and des == -1) {
			cout << "empate" << endl << endl;
		} else if (cb == cc) {
			cout << (des ? "time 1" : "time 2") << endl << endl;
		} else {
			cout << (cb > cc ? "time 1" : "time 2") << endl << endl;
		}
	}
    
    return(0);
}
