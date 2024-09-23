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
	vector<int> banca(33, 0);

	for (int i = 0, x; i < n; i++) {
		cin >> x;
		for (int j = 0; j < 32; j++) {
			if (x & (1 << j)) banca[j]++;	
		}
	}

	for (int i = 0; i < n; i++) {
		int agr = 0;
		for (int j = 0; j < 32; j++) {
			if (banca[j]) {
				banca[j]--;
				agr += (1 << j);
			}
		}
		cout << agr << " \n"[i==n-1];
	}
    
    return(0);
}
