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
	// sempre tentar fechar o quanto antes;

	stack<int> st;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '_') {
			s[i] = (st.empty() ? '(' : ')');
		}
		if (s[i] == ')') {
			res += i - st.top();
			st.pop();
		} else {
			st.push(i);
		}
	}

	cout << res << endl;
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
