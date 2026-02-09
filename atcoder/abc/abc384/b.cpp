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

	int n, r; cin >> n >> r;

	for (int i = 0; i < n; i++) {
		int d, ai; cin >> d >> ai;

		if (d == 1 and r >= 1600 and r <= 2799) {
			r += ai;
		} else if (d == 2 and r >= 1200 and r <= 2399) {
			r += ai;
		}
	}

	cout << r << endl;
    
    return(0);
}
