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

	int n; cin >> n; n++;
	vector<int> cor(n+1, 1);

	for (int i = 2; i <= n; i++) if (cor[i] == 1)
		for (int j = i+i; j <= n; j += i) cor[j] = 2;	

	cout << *max_element(cor.begin(), cor.end()) << endl;
   	for (int i = 2; i <= n; i++) {
		cout << cor[i] << " \n"[i == n];
	}

    return(0);
}
