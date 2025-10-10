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
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (x == 64) {
			cout << "1537228672809129 kg" << endl;
		} else {
			cout << abs((1LL << x) / 12000)  << " kg" << endl;
		}
	}
    
    return(0);
}
