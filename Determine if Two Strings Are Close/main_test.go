package main

import (
	"testing"
)

var testCases = []struct {
	word1    string
	word2    string
	expected bool
}{
	{"abc", "bca", true},
	{"a", "aa", false},
	{"cabbba", "abbccc", true},
	{"aabbcccddd", "abccccdddb", false},
	{"abbbzcf", "babzzcf", true},
	{"aaabbbbccddeeeeefffff", "aaaaabbcccddeeeefffff", false},
	{"uau", "ssx", false},
}

func BenchmarkCloseStrings(b *testing.B) {
	for _, tc := range testCases {
		b.Run(tc.word1+"-"+tc.word2, func(b *testing.B) {
			for i := 0; i < b.N; i++ {
				closeStrings(tc.word1, tc.word2)
			}
		})
	}
}

func BenchmarkCloseStringsV2(b *testing.B) {
	for _, tc := range testCases {
		b.Run(tc.word1+"-"+tc.word2, func(b *testing.B) {
			for i := 0; i < b.N; i++ {
				closeStringsV2(tc.word1, tc.word2)
			}
		})
	}
}

func BenchmarkCloseStringsV3(b *testing.B) {
	for _, tc := range testCases {
		b.Run(tc.word1+"-"+tc.word2, func(b *testing.B) {
			for i := 0; i < b.N; i++ {
				closeStringsV3(tc.word1, tc.word2)
			}
		})
	}
}

// Also add standard tests to verify correctness
func TestCloseStrings(t *testing.T) {
	for _, tc := range testCases {
		if got := closeStrings(tc.word1, tc.word2); got != tc.expected {
			t.Errorf("closeStrings(%q, %q) = %v, want %v", tc.word1, tc.word2, got, tc.expected)
		}
		if got := closeStringsV2(tc.word1, tc.word2); got != tc.expected {
			t.Errorf("closeStringsV2(%q, %q) = %v, want %v", tc.word1, tc.word2, got, tc.expected)
		}
		if got := closeStringsV3(tc.word1, tc.word2); got != tc.expected {
			t.Errorf("closeStringsV3(%q, %q) = %v, want %v", tc.word1, tc.word2, got, tc.expected)
		}
	}
}
