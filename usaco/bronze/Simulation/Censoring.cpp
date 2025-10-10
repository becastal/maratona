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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("censor");

	string s, t; cin >> s >> t;

	string S = "";
	for (char c : s) {
		S.push_back(c);
		if (S.size() >= t.size()) {
			int ok = 1;
			for (int r = (int)t.size()-1, l = (int)S.size()-1; r >= 0 and l >= 0 and ok; r--, l--) {
				ok &= t[r] == S[l];
			}
			if (ok) {
				for (int i = 0; i < (int)t.size(); i++) {
					S.pop_back();
				}
			}
		}
	}
	cout << S << endl;

    return(0);
}
