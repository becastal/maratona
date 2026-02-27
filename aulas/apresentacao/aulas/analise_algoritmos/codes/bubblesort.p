F3(V, n):
  para i = 0 ate n-1
    para j = n-1 decrementa ate i + 1
      se V[j] < V[j-1]
        troca(V, j, j - 1)
