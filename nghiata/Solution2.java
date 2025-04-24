import java.util.*;

public class Solution2 {
    /**
     * Find the maximum path sum starting from either (0,p) or (rows-1,q)
     * The path can move down and diagonally (or up and diagonally for the bottom start)
     * 
     * @param board The 2D grid of integers as List of Lists
     * @param p The column index for the start position at the top row
     * @param q The column index for the start position at the bottom row
     * @return The maximum path sum
     */
    public int maxPathSum(List<List<Integer>> board, int p, int q) {
        int m = board.size();
        int n = board.get(0).size();
        
        // DP tables - also using Lists instead of arrays
        List<List<Integer>> dpDown = new ArrayList<>();
        List<List<Integer>> dpUp = new ArrayList<>();
        
        // Initialize with zeros using Collections.nCopies
        for (int i = 0; i < m; i++) {
            dpDown.add(new ArrayList<>(Collections.nCopies(n, 0)));
            dpUp.add(new ArrayList<>(Collections.nCopies(n, 0)));
        }
        
        // Set starting positions
        dpDown.get(0).set(p, board.get(0).get(p));
        dpUp.get(m-1).set(q, board.get(m-1).get(q));
        
        // Calculate paths from top to bottom
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int maxPrev = dpDown.get(i-1).get(j); // straight down
                
                if (j > 0) {
                    maxPrev = Math.max(maxPrev, dpDown.get(i-1).get(j-1)); // diagonal left
                }
                
                if (j < n-1) {
                    maxPrev = Math.max(maxPrev, dpDown.get(i-1).get(j+1)); // diagonal right
                }
                
                dpDown.get(i).set(j, board.get(i).get(j) + maxPrev);
            }
        }
        
        // Calculate paths from bottom to top
        for (int i = m-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int maxPrev = dpUp.get(i+1).get(j); // straight up
                
                if (j > 0) {
                    maxPrev = Math.max(maxPrev, dpUp.get(i+1).get(j-1)); // diagonal left
                }
                
                if (j < n-1) {
                    maxPrev = Math.max(maxPrev, dpUp.get(i+1).get(j+1)); // diagonal right
                }
                
                dpUp.get(i).set(j, board.get(i).get(j) + maxPrev);
            }
        }
        
        // Find maximum result from either path
        int result = 0;
        for (int j = 0; j < n; j++) {
            result = Math.max(result, dpDown.get(m-1).get(j));
            result = Math.max(result, dpUp.get(0).get(j));
        }
        
        return result;
    }
    
    // Test helper method
    public static void runTest(List<List<Integer>> board, int p, int q, int expected) {
        Solution2 sol = new Solution2();
        int result = sol.maxPathSum(board, p, q);
        
        System.out.println("Board:");
        for (List<Integer> row : board) {
            System.out.print("  [");
            for (int i = 0; i < row.size(); i++) {
                System.out.print(row.get(i));
                if (i < row.size() - 1) System.out.print(", ");
            }
            System.out.println("]");
        }
        
        System.out.println("Start positions: (0, " + p + ") or (" + (board.size() - 1) + ", " + q + ")");
        System.out.println("Expected: " + expected + ", Got: " + result);
        
        boolean passed = result == expected;
        System.out.println(passed ? "PASSED" : "FAILED");
        System.out.println();
    }
    
    // Helper method to convert 2D array to List of Lists
    private static List<List<Integer>> arrayToList(int[][] array) {
        List<List<Integer>> result = new ArrayList<>();
        for (int[] row : array) {
            List<Integer> listRow = new ArrayList<>();
            for (int val : row) {
                listRow.add(val);
            }
            result.add(listRow);
        }
        return result;
    }
    
    public static void main(String[] args) {
        int passed = 0, total = 0;
        
        // Test case 1: Simple 3x3 board
        List<List<Integer>> board1 = new ArrayList<>();
        board1.add(Arrays.asList(1, 3, 1));
        board1.add(Arrays.asList(2, 5, 2));
        board1.add(Arrays.asList(3, 6, 4));
        runTest(board1, 1, 1, 14);
        total++;
        
        // Test case 2: Board with negative numbers
        List<List<Integer>> board2 = new ArrayList<>();
        board2.add(Arrays.asList(1, -5, 1));
        board2.add(Arrays.asList(2, -8, 2));
        board2.add(Arrays.asList(10, -3, 4));
        runTest(board2, 0, 0, 10);
        total++;
        
        // Test case 3: Edge case - 1x1 board
        List<List<Integer>> board3 = new ArrayList<>();
        board3.add(Collections.singletonList(5));
        runTest(board3, 0, 0, 5);
        total++;
        
        // Test case 4: Board with optimal diagonal path
        List<List<Integer>> board4 = arrayToList(new int[][]{
            {5, 2, 3}, 
            {1, 8, 4}, 
            {7, 6, 9}
        });
        runTest(board4, 0, 2, 22);
        total++;
        
        System.out.println("Completed " + total + " tests");
    }
}
