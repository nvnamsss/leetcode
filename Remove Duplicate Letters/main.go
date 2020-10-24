package main

func removeDuplicateLetters(s string) string {
	rs := ""
	last := [26]int{}
	used := [26]int{}
	n := len(s)
	for loop := 0; loop < n; loop++ {
		last[s[loop]-'a'] = loop
	}

	for loop := 0; loop < n; loop++ {
		if used[s[loop]-'a'] > 0 {
			continue
		}
		used[s[loop]-'a']++
		for rs != "" && rune(rs[len(rs)-1]) > rune(s[loop]) && loop < last[rs[len(rs)-1]-'a'] {
			used[rs[len(rs)-1]-'a'] = 0
			rs = rs[:len(rs)-1]
		}

		rs = rs + string(s[loop])
	}

	return rs
}

func main() {
	input := "cbacdcbc"
	output := removeDuplicateLetters(input)
	println("Output:", output)
}
