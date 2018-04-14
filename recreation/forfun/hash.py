import hashlib
import os
import time
def hash(string):
	hash_object = hashlib.md5(string.encode())
	print(hash_object.hexdigest())


string = raw_input()
hash(string)
time.sleep(3)
os.system('clear')
