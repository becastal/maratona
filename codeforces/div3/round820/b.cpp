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
	string s, t = ""; cin >> s;
	
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '0') {
			//dbg((s[i-2]-'0')*10+(s[i-1]-'0'));
			t.push_back(char('a'-1+(s[i-2]-'0')*10+(s[i-1]-'0')));	
			i-=2;
		} else {
			t.push_back(char('a'-1+(s[i]-'0')));
		}
	}
	reverse(t.begin(), t.end());
	cout << t << endl;
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
