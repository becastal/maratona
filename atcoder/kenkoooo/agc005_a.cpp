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
	stack<char> St;

	for (int i = 0; i < (int)S.size(); i++) {
		if (S[i] == 'S') {
			St.push('S');
		} else if (S[i] == 'T') {
			if (St.size() and St.top() == 'S') St.pop();
			else St.push('T');
		}
	}
	cout << (int)St.size() << endl;

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
