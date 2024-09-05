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

struct No {
    int valor;
    No *esq, *dir;
    No(int valor) {
        this->valor = valor;
        esq = dir = nullptr;
    }
};

void inserir(No*& raiz, int valor) {
    if (!raiz) {
        raiz = new No(valor);
    } else {
        queue<No*> fila;
        fila.push(raiz);
        
        while (!fila.empty()) {
            No* atual = fila.front();
            fila.pop();
            
            if (!atual->esq) {
                atual->esq = new No(valor);
                break;
            } else {
                fila.push(atual->esq);
            }
            
            if (!atual->dir) {
                atual->dir = new No(valor);
                break;
            } else {
                fila.push(atual->dir);
            }
        }
    }
}

void imprimirPosOrdem(No* no) {
    if (!no) return;
    imprimirPosOrdem(no->esq);
    imprimirPosOrdem(no->dir);
    cout << no->valor << " ";
}

int main() { _
    No* raiz = nullptr;
    int n, valor;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> valor;
        inserir(raiz, valor);
    }
    
    cout << "\nA travessia pós-ordem da árvore binária é:\n";
    imprimirPosOrdem(raiz);

    return 0;
}

