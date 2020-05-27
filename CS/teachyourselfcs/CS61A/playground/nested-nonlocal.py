# Nested nonlocal test


def gimme(n):
    def more():
        nonlocal n
        print('Not that deep', n)

        def deep():
            nonlocal n
            print("Now we're talking", n)

        return deep
    return more

# post-test conclusion – it works!
