#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
	
}
 
int main() {
	//_;
 
 	int n, tot = 0; cin >> n;
	while (n--) {
		cout << 1 << endl;

		int x; cin >> x;
		cout << int(x ^ 2 ^ 3) << endl;
		int res; cin >> res;
		tot += res;
	}

 	return 0;
}
