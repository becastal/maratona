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

	string s; cin >> s;
	vector<int> v(26, 0);
	for (char c : s) {
		v[c-'a'] = 1;
	}

	for (int i = 0; i < 26; i++) {
		if (!v[i]) return cout << char('a' + i) << endl, 0;
	}
	cout << "None" << endl;
    
    return(0);
}
