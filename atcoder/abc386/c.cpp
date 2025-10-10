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

	int k; cin >> k;
	string s, t; cin >> s >> t;

	if ((int)s.size() == (int)t.size()) {
		int dif = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			dif += s[i] != t[i];
		}

		cout << (dif <= 1 ? "Yes" : "No") << endl;
		
		return 0;
	}

	if (abs((int)s.size() - (int)t.size()) == 1) {
		int dif = 0, l = 0, r = 0;

		while (dif <= 1 and l < (int)s.size() and r < (int)t.size()) {
			if (s[l] != t[r]) {
				dif++;
				if ((int)s.size() > (int)t.size()) l++;
				else r++;
			} else {
				l++, r++;
			}

			if (dif > 1) return	cout << "No" << endl, 0;
		}

		return cout << "Yes" << endl, 0;
	}

	cout << "No" << endl;
		
    return(0);
}
