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

	int v, n; cin >> v >> n;
	double i = 10;

	while (i <= 90) {
		double k = (n * v * i) / 100;
		cout << (i == 10 ? "" : " " ) << (int)ceil(k);
		i += 10;
	}
	cout << endl;
    
    return(0);
}
