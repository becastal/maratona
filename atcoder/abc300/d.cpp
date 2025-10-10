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

const int MAX = 300010;
int divi[MAX];
vector<ll> p;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, p.push_back(i);
		for (int j : p) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}


int main()
{
    _;

	crivo(MAX-1);	
	ll N; cin >> N;

	int n = p.size(), res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				ll agr = p[i]*p[i]*p[j];

				if (agr > N) break;
				agr *= p[k];
				if (agr > N) break;
				agr *= p[k];
				if (agr > N) break;
				res++;
			}
		}
	}
	cout << res << endl;
    
    return(0);
}
