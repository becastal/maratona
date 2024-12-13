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

	ll h; cin >> h;
	if (h == 1) return cout << 2 << endl, 0;

	ll s1 = (2 + (2 + (h - 1) * 2)) * h / 2;
	h--;
	ll s2 = (1 + (1 + (h - 1))) * h / 2;

	//dbg(s1), dbg(s2);
	cout << s1 + s2 << endl;
    
    return(0);
}

