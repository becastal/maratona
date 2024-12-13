#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> fatorial(11, 1);

	for (int i = 2; i <= 10; i++) {
		fatorial[i] = fatorial[i-1] * i;
	}

	int idx = 10, res = 0;
	while (n > 0) {
		if (fatorial[idx] <= n) {
			res++;
			n -= fatorial[idx];
		} else {
			idx--;
		}
	}
	cout << res << endl;
    
    return(0);
}
