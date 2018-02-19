class node:
    def __init__(self,val):
        self.val = val
        self.child = 1
        self.l = None
        self.r = None

def insert(root, t):
    if root == None:
        here = node(t)
        return here

    if t < root.val:
        root.l = insert(root.l, t)
    if t >= root.val:
        root.r = insert(root.r, t)

    root.child += 1
    return root

def ways(root):
    if root == None:
        return 1

    total = 1;
    if root.r != None and root.l != None:
        total = table[root.l.child][root.r.child]

    total *= ways(root.l)
    total *= ways(root.r)
    return total

def printtree(root):
    if root == None:
        return

    print(root.val)
    printtree(root.l)
    printtree(root.r)



table = [[1 for i in range(101)] for j in range(101)]
for i in range(1,101):
    for j in range(1,101):
        table[i][j] = table[i-1][j] + table[i][j-1];

import fileinput

while(True):
    root = None
    try:
        n = int(input())
        t = input().split()
    except:
        break

    for i in t:
        root = insert(root,int(i))
    print(ways(root))

