import random 

def randpairs(n, rangetuple):
    ret = []
    for i in range(n):
        ret.append((random.randint(rangetuple[0], rangetuple[1]), random.randint(rangetuple[0], rangetuple[1])))
    return ret

n = int(input("Enter number of pairs : "))
r1 = int(input("Enter the lower limit of the range : "))
r2 = int(input("Enter the upper limit of the range : "))
ret = randpairs(n, (r1, r2))

print(ret)   #ANSWER
