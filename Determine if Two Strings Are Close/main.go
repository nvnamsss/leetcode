/*
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.



Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"


Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.
*/

package main

import (
	"log"
	"slices"
	"sort"
)

func closeStrings(word1 string, word2 string) bool {
	var (
		freq1 [26]int
		freq2 [26]int
	)

	for _, c := range word1 {
		freq1[c-'a']++
	}

	for _, c := range word2 {
		freq2[c-'a']++
	}

	for i := 0; i < 26; i++ {
		if (freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0) {
			return false
		}
	}

	// sort by frequency
	sort.Slice(freq1[:], func(i, j int) bool {
		return freq1[i] < freq1[j]
	})

	sort.Slice(freq2[:], func(i, j int) bool {
		return freq2[i] < freq2[j]
	})

	for i := 0; i < 26; i++ {

		if freq1[i] != freq2[i] {
			return false
		}
	}

	return true
}

func closeStringsV2(word1 string, word2 string) bool {
	if len(word1) != len(word2) {
		return false
	}

	freq1 := make(map[rune]int)
	freq2 := make(map[rune]int)

	for _, c := range word1 {
		freq1[c]++
	}

	for _, c := range word2 {
		freq2[c]++
	}

	// Check if both strings have the same characters
	for k := range freq1 {
		if _, exists := freq2[k]; !exists {
			return false
		}
	}

	// Check if frequency distribution is the same
	freqValues1 := make([]int, 0, len(freq1))
	freqValues2 := make([]int, 0, len(freq2))

	for _, v := range freq1 {
		freqValues1 = append(freqValues1, v)
	}

	for _, v := range freq2 {
		freqValues2 = append(freqValues2, v)
	}

	sort.Ints(freqValues1)
	sort.Ints(freqValues2)

	return slices.Equal(freqValues1, freqValues2)
}

func closeStringsV3(word1 string, word2 string) bool {
	if len(word1) != len(word2) {
		return false
	}
	letters1, letters2 := make([]int, 26), make([]int, 26)
	for i := 0; i < len(word1); i++ {
		letters1[word1[i]-'a']++
		letters2[word2[i]-'a']++
	}
	for i := 0; i < len(letters1); i++ {
		if (letters1[i] == 0 && letters2[i] != 0) || (letters1[i] != 0 && letters2[i] == 0) {
			return false
		}
	}
	slices.Sort(letters1)
	slices.Sort(letters2)
	for i := 0; i < len(letters1); i++ {
		if letters1[i] != letters2[i] {
			return false
		}
	}
	return true
}

func main() {
	var (
		word1 = "abc"
		word2 = "bca"
	)

	result := closeStrings(word1, word2)
	log.Printf("Result: %v, Expected: %v", result, true)
}
