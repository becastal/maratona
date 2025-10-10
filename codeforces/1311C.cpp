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
	int n, m; cin >> n >> m;
	string S; cin >> S;

	vector<int> P(n+1, 0);
	for (int i = 0, pi; i < m; i++) {
		cin >> pi;
		P[0]++, P[pi]--;
	}
	P[0]++, P[n]--;
	for (int i = 1; i < n; i++) P[i] += P[i-1];

	vector<ll> res(26, 0);
	for (int i = 0; i < n; i++) {
		res[S[i]-'a'] += P[i];	
	}

	for (int i = 0; i < 26; i++) cout << res[i] << " \n"[i==25];

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
