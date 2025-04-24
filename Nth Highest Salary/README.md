# Nth Highest Salary Solution

## Approach
The solution uses MySQL's DISTINCT, ORDER BY, and LIMIT with OFFSET to find the Nth highest salary:

1. Remove duplicates using DISTINCT
2. Sort salaries in descending order
3. Use LIMIT 1 OFFSET (N-1) to get the Nth highest value

## Time Complexity
- O(n log n) where n is the number of rows in Employee table
  - Sorting operation takes O(n log n)
  - DISTINCT operation takes O(n log n)

## Space Complexity
- O(n) for storing distinct salary values
- Additional temporary space for sorting

## Edge Cases
- Returns NULL if N is greater than the number of distinct salaries
- Handles duplicate salaries correctly by using DISTINCT
    