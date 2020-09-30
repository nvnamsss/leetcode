package main

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minDistance(word1 string, word2 string) int {
	l1 := len(word1)
	l2 := len(word2)

	var dp [][]int = make([][]int, l1+1)
	for loop := 0; loop <= l1; loop++ {
		dp[loop] = make([]int, l2+1)
	}

	for loop := 0; loop <= l1; loop++ {
		dp[loop][0] = loop
	}

	for loop := 0; loop <= l2; loop++ {
		dp[0][loop] = loop
	}

	for loop := 1; loop <= l1; loop++ {
		for loop2 := 1; loop2 <= l2; loop2++ {
			if word1[loop-1] == word2[loop2-1] {
				dp[loop][loop2] = dp[loop-1][loop2-1]
			} else {
				m1 := min(dp[loop-1][loop2], dp[loop][loop2-1])

				dp[loop][loop2] = 1 + min(m1, dp[loop-1][loop2-1])
			}
		}
	}

	return dp[l1][l2]
}
