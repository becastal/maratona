F2(v, p, r)
  se p < r
    q = particiona(v, p, r)
    F2(v, p, q-1)
    F2(v, q+1, r)

troca(v[], i, maior)
   temp = v[maior]
   v[maior] = v[i]
   v[i] = temp

particiona(v, p, r)
    x = v[r] // pivot
    i = p - 1
    para(j = p ate j < r)
      se v[j] <= x
        i = i + 1
        troca(v,i,j)
    troca(v,i+1,r)
    retorna i+1

particiona_probabilistico(A, p, r)
  i = random(p, r)
  troca(v, i, p)
  retorna particiona(v, p, r)
