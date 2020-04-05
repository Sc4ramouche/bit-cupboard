def curry2(f):
    '''Return a curried version of the given two-argument function.'''
    def g(x):
        def h(y):
            return f(x, y)
        return h
    return g

def uncurry2(f)
    '''Return a two-argument version of the given curried function.'''
    def g(x, y):
        return f(x)(y)
    return g
