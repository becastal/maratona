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

	vector<ll> f(50, 0);
	f[1] = f[2] = 1;

	for (int i = 3; i < 50; i++) {
		f[i] = f[i-1] + f[i-2];
	}

    int n;
	while (cin >> n and n) {
		cout << f[n+1] << endl;
	}

    return(0);
}
