
import math

b, c, n = input().split()
k = int(math.log10(int(n))/math.log10(int(b)))
t = n
w = k
x = b
y = k-1
z = c

print(t,w,x,y,z)