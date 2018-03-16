import fileinput, math

def div(hi, lo):
    #return hi//lo
    return (hi+lo-1)//lo

casenum = 1
for line in fileinput.input():
    # length of 3**(n+1) / 2**n
    line = int(line)
    print("Case", str(casenum)+": ", end="")
    print(math.ceil(math.log10(div(3**(line+1), 2**line))))
    casenum += 1
