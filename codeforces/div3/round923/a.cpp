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
		int n; cin >> n;
		string s; cin >> s;

		int pri = -1, ult = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B') {
				if (pri == -1) pri = i;
				ult = i;
			}
		}

		cout << ult - pri + 1 << endl;
	}
    
    return(0);
}
