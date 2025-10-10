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

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<int> v(101, 0);
	for (int i = a; i <= b; i++) {
		v[i]++;
	}
	for (int i = c; i <= d; i++) {
		v[i]++;
	}
	int res = 0;
	for (int i : v) {
		res += i == 2;
	}
	cout << res - !!(res) << endl;
    
    return(0);
}
