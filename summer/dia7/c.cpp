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

	int n, m; cin >> n >> m;
	for (int i = 0; i < 998; i++) {
		cout << (i&1 ? '9' : '4');	
	}
	cout << '5' << endl;
	for (int i = 1; i < 1000; i++) {
		cout << (i&1^1 ? '0' : '5');	
	}
	cout << endl;
 
 	return 0;
}
