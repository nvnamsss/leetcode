package main

import (
	"math/rand"
)

type RandomizedSet struct {
	set         map[int]int
	reversedSet []int
}

/** Initialize your data structure here. */
func Constructor() RandomizedSet {
	var str RandomizedSet
	str.set = make(map[int]int)
	str.reversedSet = []int{}

	return str
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
func (this *RandomizedSet) Insert(val int) bool {
	_, ok := this.set[val]

	if !ok {
		this.set[val] = val
		this.reversedSet = append(this.reversedSet, val)
	}

	return !ok
}

func IndexOf(arr []int, item int) int {
	len := len(arr)
	for loop := 0; loop < len; loop++ {
		if arr[loop] == item {
			return loop
		}
	}

	return -1
}

func Remove(s []int, index int) []int {
	s[len(s)-1], s[index] = s[index], s[len(s)-1]
	return s[:len(s)-1]
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
func (this *RandomizedSet) Remove(val int) bool {
	_, ok := this.set[val]
	if ok {
		this.reversedSet = Remove(this.reversedSet, IndexOf(this.reversedSet, val))
		delete(this.set, val)
	}

	return ok
}

/** Get a random element from the set. */
func (this *RandomizedSet) GetRandom() int {
	at := rand.Intn(len(this.reversedSet))

	return this.reversedSet[at]
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
