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
	vector<int> v(n), seq = {4, 8, 15, 16, 23, 42};
	for (int& i : v) cin >> i;
	// n - 6 (quantidade de boas subsequencias);
    
	vector<int> cont(6, 0);
	for (int i : v) {
		for (int j = 0; j < 6; j++) {
			if (i == seq[j]) {
				if (!j or cont[j-1]) {
					cont[j]++;
					if (j) cont[j-1]--;
				}
			}
		}
	}

	cout << n - 6 * cont[5] << endl;

    return(0);
}
