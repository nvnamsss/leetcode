package main

import (
	"strconv"
	"strings"
)

func addBinary(a string, b string) string {
	la := len(a)
	lb := len(b)
	aa := a
	bb := b
	if la > lb {
		bb = strings.Repeat("0", la-lb) + bb
	} else {
		aa = strings.Repeat("0", lb-la) + aa
	}

	r := 0
	result := ""
	for loop := len(aa) - 1; loop >= 0; loop-- {
		va := int(aa[loop] - 48)
		vb := int(bb[loop] - 48)
		result = strconv.Itoa((va+vb+r)%2) + result
		r = (va + vb + r) / 2
	}

	if r > 0 {
		result = strconv.Itoa(r) + result
	}

	return result
}
