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
    fib_n, fib_n_1 = 1, 1
    for i in range(1, n):
        fib_n, fib_n_1 = fib_n + fib_n_1, fib_n
    return fib_n


if __name__ == "__main__":
    import doctest
    doctest.testmod()
