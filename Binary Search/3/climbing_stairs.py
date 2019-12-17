def _fib_rec(n):
    """ Calculate nth Fibonacci number using Binet's Method. Assumes
    Fib(0) = Fib(1) = 1.

    Args:
        n integer
    Returns:
        tuple (Fib(n), Fib(n-1))
    Preconditions:
        n >= 0
    """
    (f1, f2), i = (1, 0), 31
    while i >= 0:
        if (n >> i) > 0:
            f1, f2 = f1**2 + f2**2, f2 * (2*f1 - f2)
            if (n >> i) % 2 == 1:
                f1, f2 = f1 + f2, f1
        i -= 1
    return f1, f2


def fib(n):
    """ Calculate nth Fibonacci number assuming Fib(0) = Fib(1) = 1.

    Args:
        n integer
    Returns:
        integer Fib(n)
    Preconditions:
        n >= 0
    """
    return _fib_rec(n)[0]


def climb_stairs(n):
    """ Number of paths to climb n stairs if each move comprises of climbing 1
    or 2 steps.

    Args:
        n integer
    Returns:
        integer
    Preconditions:
        n >= 0
    """
    return fib(n)
