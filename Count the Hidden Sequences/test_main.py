import unittest
from main import Solution

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example_1(self):
        # Example from LeetCode
        differences = [1,-3,4]
        lower = 1
        upper = 6
        expected = 2
        self.assertEqual(self.solution.numberOfArrays(differences, lower, upper), expected)

    def test_example_2(self):
        # Example from LeetCode
        differences = [3,-4,5,1,-2]
        lower = -4
        upper = 5
        expected = 4
        self.assertEqual(self.solution.numberOfArrays(differences, lower, upper), expected)

    def test_no_possible_array(self):
        differences = [4,-7,2]
        lower = 3
        upper = 6
        expected = 0
        self.assertEqual(self.solution.numberOfArrays(differences, lower, upper), expected)

    def test_single_difference(self):
        differences = [2]
        lower = 0
        upper = 5
        expected = 4
        self.assertEqual(self.solution.numberOfArrays(differences, lower, upper), expected)

    def test_same_bounds(self):
        differences = [0,0,0]
        lower = 1
        upper = 1
        expected = 1
        self.assertEqual(self.solution.numberOfArrays(differences, lower, upper), expected)

if __name__ == '__main__':
    unittest.main()
