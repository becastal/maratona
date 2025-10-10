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

const int MAX = 5000010;
int divi[MAX];

void crivo(int lim) {
    for (int i = 0; i <= lim; i++)
        divi[i] = 0;
 
    for (int i = 2; i <= lim; i++) {
        if (divi[i] == 0) {
            for (int j = i; j <= lim; j += i) {
                int temp = j;
                while (temp % i == 0) {
                    divi[j]++;
                    temp /= i;
                }
            }
        }
    }
}

int main()
{
    _;

	crivo(MAX-1);
	vector<int> pre(MAX+1, 0);
	for (int i = 2; i <= MAX; i++) {
		pre[i] = pre[i-1] + divi[i];
	}

	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		cout << pre[a] - pre[b] << endl;
	}
    
    return(0);
}
