package main

import "errors"

type HashsetMap map[rune]struct{}
type Hashset struct {
	set HashsetMap
}

func (h *Hashset) Add(value rune) error {
	if _, ok := h.set[value]; ok {
		return errors.New("Cannot add duplicate values.")
	}

	h.set[value] = struct{}{}
	return nil
}

func (h *Hashset) Contains(value rune) bool {
	_, ok := h.set[value]

	return ok
}

func New(values ...rune) *Hashset {
	hashset := Hashset{make(HashsetMap)}

	for _, value := range values {
		hashset.set[value] = struct{}{}
	}

	return &hashset
}

func numJewelsInStones(J string, S string) int {
	sum := 0
	h := New()

	for _, c := range J {
		h.Add(c)
	}

	for _, c := range S {
		if h.Contains(c) {
			sum += 1
		}
	}
	return sum
}
