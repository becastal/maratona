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
	int n; cin >> n;
	string s; cin >> s;

	if (n & 1) {
		vector pref(2, vector<int>(26, 0)), suf(2, vector<int>(26, 0));
		int res = n;

		for (int i = n-1; i >= 0; i--) {
			suf[i&1][s[i]-'a']++;
		}

		for (int i = 0; i < n; i++) {
			suf[i & 1][s[i] - 'a']--;
			int resi = n;

			for (int k = 0; k < 2; k++) {
				int maior = 0;
				for (int j = 0; j < 26; j++) {
					maior = max(maior, suf[k ^ 1][j] + pref[k][j]);
				}
				resi -= maior;
			}

			res = min(res, resi);
			pref[i & 1][s[i] - 'a']++;
		}
		cout << res << endl;
	} else {
		int res = 0;
		for (int i = 0; i < 2; i++) {
			vector<int> cont(26, 0);
			int maior = 0, soma = 0;
			for (int j = i; j < n; j += 2) {
				cont[s[j]-'a']++;
				maior = max(maior, cont[s[j]-'a']);
				soma++;
			}
				
			res += soma - maior;
		}

		cout << res << endl;
	}

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
