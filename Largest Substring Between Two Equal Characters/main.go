package main

func Min(a, b int) int {
	if a > b {
		return b
	}

	return a
}

func Max(a, b int) int {
	if a < b {
		return b
	}

	return a
}
func maxLengthBetweenEqualCharacters(s string) int {
	var (
		characters = make([]int, 26)
	)

	for loop := 0; loop < 26; loop++ {
		characters[loop] = -1
	}
	max := -1
	for index, r := range s {
		c := r - 'a'
		if characters[c] != -1 {
			max = Max(max, index-characters[c] - 1)
		}

		if characters[c] == -1 {
			characters[c] = index
		} else {
			characters[c] = Min(characters[c], index)
		}
	}

	return max
}
