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

	int e, v; cin >> e >> v;
	
	int h = 19 + e / v;
	int m = (e % v * 60) / v;
	
	h %= 24;

	cout << setfill('0') << setw(2) << h << ":"<< setfill('0') << setw(2) << m << endl;

    return(0);
}
