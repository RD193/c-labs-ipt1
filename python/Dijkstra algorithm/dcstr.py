def minfull(lst, val):
    lst = list(enumerate(lst))
    min = (100000, 1000000)
    for i in lst:
        if (i[1] < min[1]) and val[i[0]]:
            min = i
    return min
  
  
def deicstra(matr):
    weight = [10000]*len(matr)
    valid = [True]*len(matr)
    weight[0] = 0
    while True:
        curr = minfull(weight, valid)[0]
        for i in enumerate(matr[curr]):
            if i[1] and valid[i[0]]:
                tes = matr[curr][i[0]] + weight[curr]
                if tes < weight[i[0]]:
                    weight[i[0]] = tes
        valid[curr] = False
        if not any(valid):
            break
    return weight
  
  
Test1 = [[0,2,3,0,0,0,0], [2,0,1,1,4,0,0], [3,1,0,0,0,5,0], [0,1,0,0,1,0,0], [0,4,0,1,0,1,0], [0,0,0,0,1,0,1], [0,0,0,0,0,1,0]]
print(deicstra(Test1))