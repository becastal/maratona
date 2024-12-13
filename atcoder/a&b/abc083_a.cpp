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
	int l = a+b, r = c+d;
	if (l == r) {
		cout << "Balanced" << endl;
	} else {
		cout << (l > r ? "Left" : "Right") << endl;
	}
    
    return(0);
}
