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

	int n, k; cin >> n >> k;
	int num = 1;
	for (int i = 0; i < n; i++) {
		if (num * 2 < num + k) {
			num <<= 1;
		} else {
			num += k;
		}
	}
	cout << num << endl;
    
    return(0);
}
