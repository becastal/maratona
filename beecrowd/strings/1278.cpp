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

	int n, cont = 0;
	while (cin >> n and n) {
		cin.ignore();
		if (cont++) cout << endl;

		int mx = 0;
		vector<string> v;
		for (int i = 0; i < n; i++) {
			string s, si = ""; getline(cin, s);

			for (int l = 0, r; l < (int)s.size(); ){
				if (s[l] != ' ') {
					si.push_back(s[l++]);	
					continue;
				}

				r = l + 1;
				while (s[r] == ' ') {
					r++;
				}

				if (l and r != (int)s.size()) si.push_back(' ');
				l = r;
			}

			v.push_back(si);
			mx = max(mx, (int)si.size());
		}

		for (auto i : v) {
			cout << setw(mx) << i << endl;
		}
	}
    
    return(0);
}
