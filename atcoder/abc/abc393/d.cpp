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
    
	int n; cin >> n;
	string s; cin >> s;

	vector<int> pos;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') pos.push_back(i);
	}

	if (pos.size() == 1) return cout << 0 << endl, 0;

	int m = (int)pos.size() / 2;
	int in = pos[m] - m;
	
	ll res = 0;
	for (int i = 0; i < (int)pos.size(); i++) {
		res += abs(pos[i] - (in + i)); 
	}
	cout << res << endl;

    return(0);
}
