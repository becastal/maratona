#include <bits/stdc++.h>
 
int main() {
 
    int a, b, c, d, res = 0; std::cin >> a >> b >> c >> d;
    do {
        if (++b == 60) {
            b = 0;
            if (++a == 24) {
                a = 0;
            }
        }
        res++;
    } while (a != c or b != d);
    
    std::cout << "O JOGO DUROU " << res / 60 << " HORA(S) E " << res % 60 << " MINUTO(S)\n";
 
    return 0;
}
