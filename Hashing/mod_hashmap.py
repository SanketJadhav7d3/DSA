
hash_map = {}

values = {10: "Violet", 29: "Mikasa", 31: "2B", 12: "Major", 11: "Hinata"}

size = 10

def mod(key, size):
    key %= size
    return key

def midsquare(key):
    key = key * key
    key = str(key)
    return int(key[len(key) % 2])

if __name__ == "__main__":

    for key, value in values.items():
        # chaining
        if (midsquare(key) not in hash_map):
            hash_map[midsquare(key)] = [value]
        else:
            hash_map[midsquare(key)].append(value)
        
    print(hash_map)
