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
	ll agr = 0, res = 0;
	vector<int> v(n);
	for (int& i : v) {
		cin >> i;
		agr = max(0LL, agr + i);
		res = max(res, agr);
	}
 
	if (!res) res = (ll)*max_element(v.begin(), v.end());
	cout << res << endl;
    
    return(0);
}
