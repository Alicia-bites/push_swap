import string
import random
import subprocess

TEST_COUNT = 30

charset = string.ascii_letters + string.digits
def random_string(length=12):
	return ''.join(random.sample(charset, length))

def number_gens(start=-2147483648, end=2147483647, n=12):
	return random.sample(range(start, end), n)

def convert_to_string(args: list) -> list:
	return [str(i) for i in args]

for x in range(TEST_COUNT):
	print("⏳ Checking normal N's [Re-run #{}]".format(x), end="\r")
	numbers = number_gens(n=12)
	args = convert_to_string(numbers)
	try:
		subprocess.check_call(["./push_swap", *args], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
	except subprocess.CalledProcessError:
		print("\n\t❌ KO")
		print("Args : ", " ".join(["./push_swap", *args]))
		exit(0)
print("\n\t✅ OK")


for x in range(TEST_COUNT):
	print("⏳ Checking mixed string [Re-run #{}]".format(x), end="\r")
	numbers = number_gens(n=12)
	numbers.extend([random_string() for i in range(12)])
	args = convert_to_string(numbers)
	random.shuffle(args)
	try:
		subprocess.check_call(["./push_swap", *args], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
		print("\n\t❌ KO")
		print("Args : ", " ".join(["./push_swap", *args]))
		exit(1)
	except subprocess.CalledProcessError:
		pass
print("\n\t✅ OK")


for x in range(TEST_COUNT):
	print("⏳ Checking strings only [Re-run #{}]".format(x), end="\r")
	args = [random_string() for i in range(12)]
	random.shuffle(args)
	try:
		subprocess.check_call(["./push_swap", *args], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
		print("\n\t❌ KO")
		print("Args : ", " ".join(["./push_swap", *args]))
		exit(1)
	except subprocess.CalledProcessError:
		pass
print("\n\t✅ OK")

for x in range(TEST_COUNT):
	print("⏳ Checking invalid signs (+- shuffled and multiple times) [Re-run #{}]".format(x), end="\r")
	numbers = number_gens(n=12)
	args = convert_to_string(numbers)
	# prepend signs to args
	for i in range(len(args)):
		args[i] = (random.choice(["-", "+"]) * random.randint(2, 12)) + args[i]
	random.shuffle(args)
	try:
		subprocess.check_call(["./push_swap", *args], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
		print("\n\t❌ KO")
		print("Args : ", " ".join(["./push_swap", *args]))
		exit(1)
	except subprocess.CalledProcessError:
		pass
print("\n\t✅ OK")

for x in range(TEST_COUNT):
	print("⏳ Checking overflowing / underflowing integers [Re-run #{}]".format(x), end="\r")
	numbers = number_gens(start=-9999999999999, end=999999999999, n=12)
	for i in range(len(numbers)):
		if numbers[i] < 0:
			numbers[i] = numbers[i] - 2147483649
		else:
			numbers[i] = numbers[i] + 2147483649
	args = convert_to_string(numbers)
	random.shuffle(args)
	try:
		subprocess.check_call(["./push_swap", *args], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
		print("\n\t❌ KO")
		print("Args : ", " ".join(["./push_swap", *args]))
	except subprocess.CalledProcessError:
		pass
print("\n\t✅ OK")

for x in range(TEST_COUNT):
	print("⏳ Checking with preceeding normal N's [Re-run #{}]".format(x), end="\r")
	numbers = number_gens(n=12)
	args = convert_to_string(numbers)
	# prepend spaces to args
	for i in range(len(args)):
		args[i] = " " * random.randint(0, 12) + args[i]
	try:
		subprocess.check_call(["./push_swap", *args], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
	except subprocess.CalledProcessError:
		print("\n\t❌ KO")
		print("Args : ", " ".join(["./push_swap", *args]))
		exit(0)
print("\n\t✅ OK")

for x in range(TEST_COUNT):
	print("⏳ Checking with duplicates integers", end="\r")
	numbers = number_gens(n=12)
	# duplicate numbers
	numbers.extend(numbers)
	random.shuffle(numbers)
	args = convert_to_string(numbers)
	try:
		subprocess.check_call(["./push_swap", *args], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
		print("\n\t❌ KO")
		print("Args : ", " ".join(["./push_swap", *args]))
		exit(0)
	except subprocess.CalledProcessError:
		pass
print("\n\t✅ OK")
