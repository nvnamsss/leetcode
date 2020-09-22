package main

func searchMatrix(matrix [][]int, target int) bool {
	m := len(matrix)
	if m == 0 {
		return false
	}
	n := len(matrix[0])
	a := []int{}

	for loop := 0; loop < n; loop++ {
		if target >= matrix[0][loop] && target <= matrix[m-1][loop] {
			a = append(a, loop)
		}
	}

	length := len(a)
	for loop := 0; loop < length; loop++ {
		column := a[loop]
		for loop2 := 0; loop2 < m; loop2++ {
			if target == matrix[loop2][column] {
				return true
			}
		}
	}

	return false
}
