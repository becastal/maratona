#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	double res = 0.0;
	for (int i = 0; i < n; i++) {
		int cont = (S[i] == 't');
		for (int j = i+1; j < n; j++) {
			if (S[j] == 't') {
				cont++;
				res = max(res, double(cont - 2) / double(j - i - 1));
			}
		}
	}
	cout << fixed << setprecision(13) << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
