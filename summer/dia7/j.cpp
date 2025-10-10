#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;
 
int main() {
	_;

	int n; cin >> n;
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;

	int b1, b2, b3;
	cin >> b1 >> b2 >> b3;

	vector<ll> A = {a1, a2, a3}, B = {b1, b2, b3};

	ll mn = 0, mx = min(a1, b2) + min(a2, b3) + min(a3, b1);
	for (int i = 0; i < 3; i++) {
		mn = max(mn, B[i]-(A[i]+A[(i+1)%3]));
	}
	cout << mn << ' ' << mx << endl;
 
 	return 0;
}
