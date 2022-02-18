package main

import (
	"log"
	"strings"
)

func wordPattern(pattern string, s string) bool {
	var (
		m        map[string]rune = make(map[string]rune)
		splitted                 = strings.Split(s, " ")
		parsed   string
	)

	if len(splitted) != len(pattern) {
		return false
	}

	for i, v := range splitted {
		if _, ok := m[v]; !ok {
			m[v] = rune(pattern[i])
		}
		log.Printf("%v -> %v", v, m[v])
		parsed = parsed + string(m[v])
	}

	return parsed == pattern
}
