public class Solution {
IList<IList<string>> result;
        int n;
        private void setseal(int[][] banned, int row, int column, int seal)
        {
            for (int loop = 0; loop < n; loop++)
            {
                banned[row][loop] += seal;
            }

            for (int loop = 0; loop < n; loop++)
            {
                banned[loop][column] += seal;
            }

            int ld = 0;

            bool did = true;

            while (did)
            {
                did = false;
                if (row - ld >= 0 && column - ld >= 0)
                {
                    banned[row - ld][column - ld] += seal;
                    did = true;
                }

                if (row + ld < n && column + ld < n)
                {
                    banned[row + ld][column + ld] += seal;
                    did = true;
                }

                if (row - ld >= 0 && column + ld < n)
                {
                    banned[row - ld][column + ld] += seal;
                    did = true;
                }

                if (row + ld < n && column - ld >= 0)
                {
                    banned[row + ld][column - ld] += seal;
                    did = true;
                }

                ld++;
            }

        }

        private List<string> tomatrix(List<int> rs)
        {
            List<string> s = new List<string>();
            for (int loop = 0; loop < n; loop++)
            {
                StringBuilder sb = new StringBuilder(new string('.', n));
               
                sb[rs[loop]] = 'Q';
                s.Add(sb.ToString());
            }

            return s;
        }

        private void backtrack(List<int> rs, int[][] banned, int column)
        {
            if (column == n)
            {
                result.Add(tomatrix(rs));
                return;
            }

            for (int loop = 0; loop < n; loop++)
            {
                if (banned[loop][column] == 0)
                {
                    rs[loop] = column;
                    setseal(banned, loop, column, column + 1);
                    backtrack(rs, banned, column + 1);
                    setseal(banned, loop, column, -(column + 1));
                }
            }
        }

        public IList<IList<string>> SolveNQueens(int n)
        {
            this.n = n;
            result = new List<IList<string>>();
            int[][] banned = new int[n][];
            for (int loop = 0; loop < n; loop++)
            {
                banned[loop] = new int[n];
            }

            List<int> arr = new List<int>();
            for (int loop = 0; loop < n; loop++)
            {
                arr.Add(-1);
            }

            backtrack(arr, banned, 0);

            return result;
        }
}