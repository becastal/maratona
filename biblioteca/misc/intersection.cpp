/**
 * Este programa resolve o problema de encontrar interse��es entre segmentos horizontais e verticais
 * em um plano 2D. Utiliza uma combina��o de compress�o de coordenadas e uma �rvore bin�ria indexada (BIT)
 * para alcan�ar uma solu��o eficiente.
 *
 * A abordagem geral � a seguinte:
 * 1. L� os segmentos de entrada na main.
 * 2. Para cada segmento lido, s�o gerados eventos:
 *    - In�cio e fim de segmentos horizontais.
 *    - Segmentos verticais.
 * 3. Comprima as coordenadas y para reduzir o espa�o de coordenadas e trabalhar eficientemente.
 * 4. Ordena os eventos por coordenada x.
 * 5. Usa um BIT para manter e consultar a contagem de segmentos horizontais ativos durante a varredura dos eventos.
 * 6. Calcula e imprime o n�mero de interse��es entre os segmentos horizontais e verticais.
 */

#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0); // Macros para otimiza��o de I/O
#define endl '\n' // Defini��o de endl para melhorar performance de sa�da
#define dbg(x) cout << #x << " = " << x << endl // Macro para debug

typedef long long ll; // Defini��o de tipo para n�meros inteiros longos
using namespace std;

typedef pair<int,int> point; // Tipo de dado para representar um ponto (coordenadas x e y)
struct event {
    point p1, p2; // Pontos que definem o evento
    int type; // Tipo de evento (0: in�cio de segmento horizontal, 1: fim de segmento horizontal, 2: segmento vertical)
    event() {}; // Construtor padr�o
    event(point p1, point p2, int type) : p1(p1), p2(p2), type(type) {}; // Construtor com par�metros
};

const int MAX = 1e6+10; // Tamanho m�ximo pr�-definido para arrays
int n, e; // Vari�veis para o n�mero de segmentos e eventos
event events[MAX]; // Array para armazenar os eventos
vector<int> coords; // Vetor para armazenar as coordenadas y �nicas
map<int, int> compress; // Mapa para mapear coordenadas comprimidas para �ndices do BIT
int bit[MAX]; // BIT (Binary Indexed Tree) para manter contagem de segmentos ativos

// Fun��o de compara��o para ordena��o dos eventos
bool compare(event a, event b) {
    if (a.p1.f == b.p1.f)
        return a.type < b.type; // Se coordenadas x s�o iguais, ordena por tipo (0 antes de 1)
    return a.p1.f < b.p1.f; // Ordena por coordenada x
}

// Fun��o para atualizar o BIT
void update(int idx, int val) {
    while (idx < MAX) {
        bit[idx] += val; // Adiciona val ao BIT na posi��o idx
        idx += idx & -idx; // Atualiza idx para o pr�ximo �ndice no BIT
    }
}

// Fun��o para consultar a soma acumulada no BIT at� o �ndice idx
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx]; // Soma o valor do BIT na posi��o idx
        idx -= idx & -idx; // Atualiza idx para o �ndice anterior no BIT
    }
    return sum;
}

// Fun��o principal para calcular o n�mero de interse��es
ll hv_intersection() {
    ll cont = 0; // Vari�vel para contar interse��es
    for (int i = 0; i < e; ++i) { // Itera sobre todos os eventos
        event c = events[i]; // Obt�m o evento atual
        if (c.type == 0) { // Se � o in�cio de um segmento horizontal
            update(compress[c.p1.s], 1); // Adiciona um ao BIT na posi��o correspondente � coordenada y
        } else if (c.type == 1) { // Se � o fim de um segmento horizontal
            update(compress[c.p2.s], -1); // Remove um do BIT na posi��o correspondente � coordenada y
        } else { // Se � um segmento vertical
            // Calcula o n�mero de segmentos horizontais ativos entre as coordenadas y do segmento vertical
            cont += query(compress[c.p2.s]) - query(compress[c.p1.s] - 1);
        }
    }
    return cont; // Retorna o n�mero total de interse��es encontradas
}

int main() {
    _
    cin >> n; // L� o n�mero de segmentos

    e = 0;
    for (int i = 0; i < n; ++i) {
        int p1x, p1y, p2x, p2y;
        cin >> p1x >> p1y >> p2x >> p2y; // L� as coordenadas do segmento

        // Gera os eventos para o segmento atual
        if (p1x == p2x) { // Se o segmento � vertical
            events[e++] = event(make_pair(p1x, min(p1y, p2y)), make_pair(p2x, max(p1y, p2y)), 2);
            coords.push_back(min(p1y, p2y)); // Adiciona coordenada y m�nima
            coords.push_back(max(p1y, p2y)); // Adiciona coordenada y m�xima
        } else { // Se o segmento � horizontal
            events[e++] = event(make_pair(min(p1x, p2x), p1y), make_pair(max(p1x, p2x), p2y), 0);
            events[e++] = event(make_pair(max(p1x, p2x), p1y), make_pair(min(p1x, p2x), p2y), 1);
            coords.push_back(p1y); // Adiciona coordenada y do primeiro ponto
            coords.push_back(p2y); // Adiciona coordenada y do segundo ponto
        }
    }

    sort(coords.begin(), coords.end()); // Ordena as coordenadas
    coords.erase(unique(coords.begin(), coords.end()), coords.end()); // Remove duplicatas

    for (int i = 0; i < coords.size(); ++i) {
        compress[coords[i]] = i + 1; // Mapeia cada coordenada para um �ndice no BIT
    }

    sort(events, events + e, compare); // Ordena os eventos por coordenada x

    cout << hv_intersection() << endl; // Calcula e imprime o n�mero de interse��es entre os segmentos

    return 0; // Retorna 0 para indicar sucesso
}
