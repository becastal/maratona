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

	int n, k; cin >> n >> k;
	string s; cin >> s;

	sort(s.begin(), s.end());

	int res = 0;
	do {
		int ok = 1;

		for (int i = 0; i <= n - k; i++) {
			int pal = 1;
			for (int j = 0; j < k; j++) {
				pal &= s[i + j] == s[i + k - 1 - j];	
			}
			ok &= !pal;
		}
		
		res += ok;
	} while (next_permutation(s.begin(), s.end()));

	cout << res << endl;
    
    return(0);
}
