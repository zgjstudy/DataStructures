import sys
sys.stdout = open("randnum.txt",'w')
from random import random
for i in range(0,int(1e5) + 10):
    print(random(), end=' ')
