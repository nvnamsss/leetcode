package main

func isMatch(s string, p string) bool {
	ls := len(s)
	lp := len(p)
	var dp [][]bool = make([][]bool, ls+1)
	for loop := 0; loop < ls+1; loop++ {
		dp[loop] = make([]bool, lp+1)
	}

	dp[ls][lp] = true
	for loop := ls; loop >= 0; loop-- {
		for loop2 := lp - 1; loop2 >= 0; loop2-- {
			first_math := loop < ls && (s[loop] == p[loop2] || p[loop2] == '.')

			if loop2+1 < lp && p[loop2+1] == '*' {
				dp[loop][loop2] = dp[loop][loop2+2] || (first_math && dp[loop+1][loop2])
			} else {
				dp[loop][loop2] = first_math && dp[loop+1][loop2+1]
			}
		}
	}
	return dp[0][0]
}
