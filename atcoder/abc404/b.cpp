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

	vector<string> a(n), b(n);

	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;

	auto cont = [&]() {
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				res += a[i][j] != b[i][j];
			}
		}
		return res;
	};

	auto rot = [&]() {
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				swap(a[i][j], a[j][i]);
			}
		}
		
		for (int i = 0; i < n; i++) {
			reverse(a[i].begin(), a[i].end());
		}
	};

	int res = INF;
	for (int i = 0; i < 4; i++) {
		res = min(res, i + cont());
		rot();
	}
	cout << res << endl;
    
    return(0);
}
