n = int(input())

binary = bin(n)[2:]

odd = False
if(len(binary) % 2 == 1):
    odd = True
    binary = binary[:-1]

binary = binary[0:len(binary)//2+1]
binary = int(binary, 2)

print(binary)
