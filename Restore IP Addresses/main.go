package main

import "strconv"

func isValid(v string) bool {
	// Check if the string is empty or has leading zeros
	if len(v) == 0 || (len(v) > 1 && v[0] == '0') {
		return false
	}
	ip, err := strconv.Atoi(v)
	if err != nil {
		return false
	}
	return ip >= 0 && ip <= 255
}

func backtrack(s string, start int, path []string, res *[]string) {
	if len(path) == 4 && start == len(s) {
		*res = append(*res, path[0]+"."+path[1]+"."+path[2]+"."+path[3])
		return
	}
	for i := 1; i <= 3; i++ {
		if start+i > len(s) {
			break
		}
		part := s[start : start+i]
		if isValid(part) {
			backtrack(s, start+i, append(path, part), res)
		}
	}
}

func restoreIpAddresses(s string) []string {
	var res []string
	backtrack(s, 0, []string{}, &res)
	return res
}
