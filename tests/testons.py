import random
import sys
try:
  n = int(sys.argv[1])
except:
  print("python3 ./push_swap_gen.py <n>")
  exit(1)
print(" ".join(str(x) for x in random.sample(range(-2147483648, 2147483647), k=n)))