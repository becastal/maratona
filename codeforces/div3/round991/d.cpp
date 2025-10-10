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

void solve() {
	string s; cin >> s;
	int n = (int)s.size();
	
	for (int i = 0; i < n; i++) {
		int mj = -1, melhor = s[i];
		for (int j = 1; j < 9 and i + j < n; j++) {
			if (melhor < s[i+j] - j) {
				melhor = s[i+j]-j;
				mj = j;
			}
		}

		if (mj == -1) continue;

		auto nsi = s[i + mj] - mj;
        for (int ii = i + mj - 1; ii >= i; ii--) {
            s[ii + 1] = s[ii];
        }
        s[i] = nsi;
	}

	cout << s << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
