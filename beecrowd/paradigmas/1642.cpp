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

	int k;
	while (cin >> k and k) {
		cin.ignore();
		string s; getline(cin, s);
		int n = (int)s.size(), res = 0;

		map<char, int> M;
		for (int r = 0, l = 0; r < n; r++) {
			M[s[r]]++;

			while (M.size() > k) {
				if (--M[s[l]] == 0) M.erase(s[l]);
				l++;
			}

			res = max(res, r - l + 1);
		}
		cout << res << endl;
	}
    
    return(0);
}
