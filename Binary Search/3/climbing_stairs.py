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
    if n == 0:
        return (1, 0)
    if n == 1:
        return (1, 1)
    f1, f2 = _fib_rec(n//2)
    r1, r2 = f1 * (2*f2 + f1), f1**2 + f2**2
    return (r1, r2) if n % 2 != 0 else (r2, r1-r2)


def fib(n):
    """ Calculate nth Fibonacci number assuming Fib(0) = Fib(1) = 1.
    Args:
        n integer
    Returns:
        integer Fib(n)
    Preconditions:
        n >= 0

    Examples:
    >>> fib(0)
    1
    >>> fib(1)
    1
    >>> fib(2)
    2
    >>> fib(3)
    3
    >>> fib(4)
    5
    >>> fib(5)
    8
    >>> fib(6)
    13
    >>> fib(7)
    21
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


if __name__ == "__main__":
    import doctest
    doctest.testmod()
