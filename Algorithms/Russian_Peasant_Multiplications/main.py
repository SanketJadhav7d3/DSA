
# Exponentiation using Russian Peasant Algorithm

def exponentiation(base, exp):
    # start with running product of 1
    running_product = 1

    # with each step base(n + 1) = base(n) ** 2
    # exp(n + 1) = exp(n) // 2

    while (exp > 0):
        # if exp is odd then multiply base to running product
        if (exp % 2 != 0):
            running_product *= base

        # half the exp and discard the remainder
        exp //= 2
        # square the base
        base **= 2

    return running_product


if __name__ == '__main__':
    print(exponentiation(4, 29))
