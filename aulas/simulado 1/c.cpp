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
 
	int a, b; cin >> a >> b;
 
	bool da = 0;
	map<ll, ll> origem;
	function<void(ll, ll)> dfs = [&](ll x, ll pai) {
		origem[x] = pai;
		if (x == b) da = 1;
		if (x > b or da) return;
 
		dfs(x*2, x);
		dfs(x*10+1, x);
	};
	dfs(a, 0);
 
	if (!da) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		vector<int> res;
		while (origem[b]) {
			res.push_back(b);
			b = origem[b];
		}
		res.push_back(a);
		reverse(res.begin(), res.end());
		cout << (int)res.size() << endl;
		for (int i : res) cout << i << ' ';
		cout << endl;
	}
    
    return(0);
}
