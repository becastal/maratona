#include <bits/stdc++.h>
#define f first
#define s second
const int INF = 0x3f3f3f3f;
using namespace std;

int main()
{

    int n; cin >> n;
    vector<pair<int, int>> pontos(n);
    
	for (int i = 0; i < n; i++) {
		cin >> pontos[i].f >> pontos[i].s;
	}

    sort(pontos.begin(), pontos.end());
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        int abaixo = INF, acima = INF;

        for (int j = i + 1; j < n; j++) {
            if (pontos[i].s == pontos[j].s) continue;
                
            if (pontos[i].s < pontos[j].s and abs(pontos[i].s - pontos[j].s) < abaixo) {
                abaixo = abs(pontos[i].s - pontos[j].s);
                res++;
            } else if (pontos[i].s > pontos[j].s and abs(pontos[i].s - pontos[j].s) < acima) {
                acima = abs(pontos[i].s - pontos[j].s);
                res++;
            }
        }
    }

    cout << res << endl;
    return(0);
}

