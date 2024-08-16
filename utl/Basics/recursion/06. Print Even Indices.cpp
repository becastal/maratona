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
	ll n; cin >> n;
	vector<int> v(n);
	for (int& vi : v)
		cin >> vi;

	function<void(int)> p = [&] (int a) {
		if (a < 0) return;
		if (a % 2) p(a - 1);
		else
		{
			cout << v[a] << (a ? " " : "");
			p(a - 1);
		}
	};

	p(n - 1);
	cout << endl;
    
    return(0);
}
