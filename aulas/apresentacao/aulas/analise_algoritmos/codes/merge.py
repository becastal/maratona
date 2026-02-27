import math

def merge(V, p, q, r):
    n_left = q - p + 1
    n_right = r - q
    L=[]
    R=[]

    for i in range(n_left):
        L.append(V[p + i])

    for i in range(n_right):
        R.append(V[q+i+1])

    i = 0
    j = 0
    k = p

    while i < n_left and j < n_right:
        if (L[i] <= R[j]):
            V[k] = L[i]
            i = i + 1
        else:
            V[k] = R[j]
            j = j + 1
        k = k + 1

    while i < n_left:
        V[k] = L[i]
        i = i + 1
        k = k + 1

    while j < n_right:
        V[k] = R[j]
        j = j + 1
        k = k + 1

def mergesort(V, left, right):
    if left < right:
        mid = math.floor((left + right)/2)
        mergesort(V, left, mid)
        mergesort(V, mid + 1, right)
        merge(V, left, mid, right)

V = [9,2,4,59,1,10, 123,4]
print(V)
mergesort(V,0, len(V)-1)
print(V)
