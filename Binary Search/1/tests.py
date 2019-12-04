import unittest
from lowest_index import lowest_index, count_in_sorted


class TestBinarySearchSuite(unittest.TestCase):
    """ Uses brute force implementations of functions in lowest_index.py for
    testing.
    """

    def setUp(self):
        # int lists
        self.EMPTY_ARR = []
        self.SINGLETON_ARR = [1]
        self.DUAL_ARR = [1, 2]
        self.TRIPLE_ARR = [1, 4, 5]
        self.SMALL_ARR = [1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9, 9, 9, 9, 9, 10, 11,
                          15, 20, 25, 30]

        # str lists
        self.DUAL_REP = ['a', 'a']
        self.TRIP_REP = ['a', 'e', 'e']

    # brute force for lowest_index
    def bf_lowest_index(self, A, i):
        res = lowest_index(A, i)
        if len(A) == 0:
            return res == 0
        if i in A:
            return res == A.index(i)
        if 0 < res < len(A):
            return i < A[res] and A[res - 1] < i
        if res == 0:
            return i < A[0]
        if res == len(A):
            return A[-1] < i
        return False

    # brute force for count_in_sorted
    def bf_count_in_sorted(self, A, target, target_inc):
        return count_in_sorted(A, target, target_inc) == A.count(target)

    def test_empty_case(self):
        for i in [-22, -2, -1, 0, 1, 2, 1000]:
            self.assertTrue(self.bf_lowest_index(self.EMPTY_ARR, i))
            self.assertTrue(self.bf_count_in_sorted(self.EMPTY_ARR, i, i+1))

    def test_corner_cases_no_reps(self):
        # len(arr) == 1
        for i in [-1000, -2, -1, 0, 1, 2, 3, 4, 999999999]:
            self.assertTrue(self.bf_lowest_index(self.SINGLETON_ARR, i))
            self.assertTrue(
                self.bf_count_in_sorted(self.SINGLETON_ARR, i, i+1)
            )

        # len(arr) == 2
        for i in [-999999999, -2, -1, 0, 1, 2, 3, 4, 5, 20000]:
            self.assertTrue(self.bf_lowest_index(self.DUAL_ARR, i))
            self.assertTrue(self.bf_count_in_sorted(self.DUAL_ARR, i, i+1))

        # len(arr) == 3
        for i in [-9999999, -20, -1, 0, 1, 2, 3, 4, 5, 6, 7, 10, 1000]:
            self.assertTrue(self.bf_lowest_index(self.TRIPLE_ARR, i), 0)
            self.assertTrue(self.bf_count_in_sorted(self.TRIPLE_ARR, i, i+1))

    def test_corner_cases_with_reps(self):
        # len(arr) == 2
        for i in ['', ' ', 'A', 'Z', 'a', 'b', 'c', 'z']:
            self.assertTrue(self.bf_lowest_index(self.DUAL_REP, i))
            self.assertTrue(self.bf_count_in_sorted(self.DUAL_REP, i, i+'\0'))

        # len(arr) == 3
        for i in ['', ' ', 'A', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'eggs',
                  'z', 'zebra']:
            self.assertTrue(self.bf_lowest_index(self.TRIP_REP, i))
            self.assertTrue(self.bf_count_in_sorted(self.TRIP_REP, i, i+'\0'))

    def test_small_arr_with_reps(self):
        for i in range(50):
            self.assertTrue(self.bf_lowest_index(self.SMALL_ARR, i))
            self.assertTrue(self.bf_count_in_sorted(self.SMALL_ARR, i, i+1))


if __name__ == '__main__':
    unittest.main()
