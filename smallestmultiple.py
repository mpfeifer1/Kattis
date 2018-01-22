import fileinput
import math


def factors(n):
    ret = {}
    for i in range(2, math.ceil(math.sqrt(n))+1):
        while n % i == 0:
            if i not in ret:
                ret[i] = 0
            ret[i] += 1
            n //= i

    if n > 1:
        if n not in ret:
            ret[n] = 0
        ret[n] += 1

    return ret;



def merge(m1,m2):
    for i in m2:
        if i not in m:
            m[i] = 0
        m1[i] = max(m1[i], m2[i]);
    return m1



for line in fileinput.input():
    v = [int(x) for x in line.split()]

    m = factors(v[0])
    for i in range(1, len(v)):
        n = factors(v[i])
        merge(m, n)

    total = 1;
    for i in m:
        for j in range(m[i]):
            total *= i

    print(total)
