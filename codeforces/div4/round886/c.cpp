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
		int n = 8;
		vector<string> v(n);
		for (auto& i : v) cin >> i;

		int ok = 0;
		string s = ""; 
		for (int i = 0; i < n and !ok; i++) {
			for (int j = 0; j < n and !ok; j++) {
				if (v[i][j] == '.') continue;

				int ii = i;
				while (ii < n and v[ii][j] != '.') {
					s.push_back(v[ii++][j]);
				}
				ok = 1;		
			}
		}
		cout << s << endl;
	}
    
    return(0);
}
