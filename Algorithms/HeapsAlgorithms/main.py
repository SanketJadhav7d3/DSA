
# heap's algorithm to generate permutation of a sequence

permutations = []

def heaps(n, size):

    if size == 1:
        print(n)
        return

    for i in range(size):
        heaps(n, size-1)

        if size % 2 != 0:
            # swap the first element with the last elmeent
    
            n[0], n[size-1] = n[size-1], n[0]
        else:
            # otherwise swap the i'th element with the last element
            n[i], n[size-1] = n[size-1], n[i]


a = [x for x in range(0, 10)]

heaps(a, len(a))
