MergeSort(v, left, right)
  se left < right:
    mid = floor((left + right)/ 2)
    MergeSort(v, left, mid)
    MergeSort(v, mid + 1, right)
    Merge(v, left, mid, right)

Merge(v, p, q, r)
  n_left = q - p + 1; 
  n_right = r - q;
  L[n_left] // cria vetor de tamanho n_left
  R[n_right] // cria vetor de tamanho n_right

  para i = 0 ate n_left
    L[i] = v[p + i]
  
  para i = 0 ate n_right
    R[i] = v[q + i + 1]

  i = 0
  j = 0
  k = p

  enquanto i < n_left && j < n_right
    se L[i] <= R[j]
      v[k] = L[i]
      i = i + 1
    senao 
      v[k] = R[j];
      j = j + 1
    k = k + 1
  
  enquanto i < n_left
    v[k] = L[i]
    i = i + 1
    k = k + 1
  
  enquanto j < n_right
    v[k] = R[j]
    j = j + 1
    k = k + 1
