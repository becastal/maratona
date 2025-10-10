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

	string s;
	while (cin >> s) {
		vector<int> cont(26, 0);
		for (char c : s) cont[c-'a'] ^= 1;

		int pri = 1, res = 0;
		for (int i : cont) {
			if (i) {
				if (pri) {
					pri = 0;
					continue;	
				}
				res++;
			}
		}
		cout << res << endl;
	}
    
    return(0);
}
