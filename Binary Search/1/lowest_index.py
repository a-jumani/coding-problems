def lowest_index(arr, target):
    """ Finds the lowest index of target in arr. If target in arr, returns lowest
    index i such that arr[i] == target, else returns index i where it should be
    inserted while keeping arr sorted.

    Args:
        arr array to search target in
        target value
    Returns:
        index, where 0 <= index <= len(arr)
    Preconditions:
        arr == sorted(arr)
        < is supported between target and elements of arr
    """
    # initialize search range
    start, end = 0, len(arr)

    # maintain solution in range [start, end]
    while (start < end):
        mid = (start + end) // 2
        if arr[mid] < target:
            start = mid + 1
        else:
            end = mid

    return end
