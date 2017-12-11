import hashlib
def hash(string):
	hash_object = hashlib.md5(string.encode())
	print(hash_object.hexdigest())
hash("test")
