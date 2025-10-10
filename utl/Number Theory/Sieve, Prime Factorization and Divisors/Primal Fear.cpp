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

const int MAX = 1e6+10;
int divi[MAX];
int pot[] = {10, 100, 1000, 10000, 100000, 1000000};
void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

int ruim(int x) {
	if (divi[x] == x) {
		int xi = x;
		while (xi) {
			if (xi % 10 == 0) return 0;
			xi /= 10;
		}
	}
	
	for (int i : pot) {
		int agr = x % i;
		if (divi[agr] != agr or agr == 1) return 0;
	}
	return 1;
}

int main()
{
    _;

	crivo(MAX-1);

	int res[MAX];
	res[1] = 0;
	for (int i = 2; i < MAX; i++) {
		res[i] = res[i-1] + ruim(i);
		//if (ruim(i)) dbg(i);
	}

	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		cout << res[x] << endl;
	}
    
    return(0);
}
