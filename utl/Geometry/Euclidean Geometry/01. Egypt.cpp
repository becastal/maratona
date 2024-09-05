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
#define sq(x) ((x)*(x))

int main()
{
    _;

	vector<int> v(3);
   
   	while (cin >> v[0] >> v[1] >> v[2] and v[0] and v[1] and v[2]) {
		sort(v.begin(), v.end());

		cout << (sq(v[2]) == sq(v[1]) + sq(v[0]) ? "right" : "wrong") << endl;
	}

    return(0);
}
