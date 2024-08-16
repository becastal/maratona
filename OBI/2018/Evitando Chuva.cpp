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
	int a = 0, b = 0;
	int ca = 0, cb = 0;
	for (int i = 0; i < n; i++) {
		string sd, sn; cin >> sd >> sn;

		if (sd == "chuva") {
			if (a) {
				a--, b++;
			} else {
				b++; ca++;
			}
		}
		if (sn == "chuva") {
			if (b) {
				b--, a++;
			} else {
				a++; cb++;
			}
		}
	}
	cout << ca << ' ' << cb << endl;
    
    return(0);
}
