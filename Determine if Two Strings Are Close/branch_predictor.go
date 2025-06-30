package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

// Pattern types for branch prediction testing
const (
	PatternAlwaysTaken    = "Always Taken"
	PatternAlwaysNotTaken = "Always Not Taken"
	PatternAlternating    = "Alternating"
	PatternRandom         = "Random"
	PatternMostlyTaken    = "Mostly Taken (80%)"
	PatternMostlyNotTaken = "Mostly Not Taken (80%)"
)

// BranchPattern represents a sequence of branch decisions (taken or not taken)
type BranchPattern struct {
	Name     string
	Sequence []bool // true for taken, false for not taken
}

// GenerateBranchPattern creates a pattern with the given characteristics
func GenerateBranchPattern(patternType string, size int) *BranchPattern {
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	seq := make([]bool, size)

	switch patternType {
	case PatternAlwaysTaken:
		for i := range seq {
			seq[i] = true
		}
	case PatternAlwaysNotTaken:
		for i := range seq {
			seq[i] = false
		}
	case PatternAlternating:
		for i := range seq {
			seq[i] = i%2 == 0
		}
	case PatternRandom:
		for i := range seq {
			seq[i] = r.Float64() < 0.5
		}
	case PatternMostlyTaken:
		for i := range seq {
			seq[i] = r.Float64() < 0.8
		}
	case PatternMostlyNotTaken:
		for i := range seq {
			seq[i] = r.Float64() < 0.2
		}
	}

	return &BranchPattern{
		Name:     patternType,
		Sequence: seq,
	}
}

// BranchPredictor simulates a 2-bit saturating counter branch predictor
type BranchPredictor struct {
	table map[string]int // 2-bit counters per branch ID
}

func NewBranchPredictor() *BranchPredictor {
	return &BranchPredictor{
		table: make(map[string]int),
	}
}

// Predict returns true if prediction is 'taken'
func (bp *BranchPredictor) Predict(branchID string) bool {
	state, exists := bp.table[branchID]
	if !exists {
		state = 1 // default: weakly not taken
	}
	return state >= 2
}

// Update modifies the state of the branch predictor
func (bp *BranchPredictor) Update(branchID string, taken bool) {
	state, exists := bp.table[branchID]
	if !exists {
		state = 1
	}
	if taken {
		if state < 3 {
			state++
		}
	} else {
		if state > 0 {
			state--
		}
	}
	bp.table[branchID] = state
}

func (bp *BranchPredictor) StateName(state int) string {
	names := []string{"Strong Not Taken", "Weak Not Taken", "Weak Taken", "Strong Taken"}
	return names[state]
}

// RunBranchPrediction runs a sequence of branches and measures prediction accuracy
func RunBranchPrediction(pattern *BranchPattern) (float64, time.Duration) {
	bp := NewBranchPredictor()
	branchID := "main_branch"

	correct := 0
	iterations := len(pattern.Sequence)

	start := time.Now()

	for _, taken := range pattern.Sequence {
		prediction := bp.Predict(branchID)
		if prediction == taken {
			correct++
		}
		bp.Update(branchID, taken)

		// Simulate the actual branch - this is what would happen in real code
		sum := 0
		if taken {
			sum++
		}
		_ = sum // prevent optimization
	}

	elapsed := time.Since(start)
	accuracy := float64(correct) / float64(iterations) * 100.0

	return accuracy, elapsed
}

// FormatBenchmarkResults formats results in the requested style
func FormatBenchmarkResults(results map[string]struct {
	Accuracy float64
	Duration time.Duration
}) string {
	output := "Branch Predictor Benchmark Results:\n\n"

	for pattern, result := range results {
		output += fmt.Sprintf("Pattern: %-18s | Accuracy: %5.1f%% | Time: %v\n",
			pattern, result.Accuracy, result.Duration)
	}

	return output
}

// The following functions are kept for backward compatibility

// PredictableBranching sums values above threshold in a pre-sorted array
// The pattern of branches is predictable (all early elements < threshold, all later elements > threshold)
func PredictableBranching(data []int, threshold int) int {
	result := 0
	// This summation has a predictable branch pattern
	for _, val := range data {
		if val > threshold {
			result += val
		}
	}
	return result
}

// UnpredictableBranching sums values above threshold in a random array
// The pattern of branches is unpredictable (random mix of elements above/below threshold)
func UnpredictableBranching(data []int, threshold int) int {
	result := 0
	for _, val := range data {
		if val > threshold {
			result += val
		}
	}

	return result
}

// BranchlessSummation uses bit manipulation to avoid branches
// This demonstrates an alternative approach that avoids the branch predictor
func BranchlessSummation(threshold int, iterations int) int {
	data := generateRandomArray(1000)

	result := 0
	for i := 0; i < iterations; i++ {
		sum := 0
		for _, val := range data {
			// Use arithmetic to avoid branching
			// If val > threshold, mask will be all 1s (as -1), otherwise all 0s
			mask := -((val - threshold) >> 31)
			sum += val & mask
		}
		result += sum
	}

	return result
}

// generateRandomArray creates an array with random integers
func generateRandomArray(size int) []int {
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = r.Intn(2000) - 1000 // Random values between -1000 and 999
	}
	return arr
}

// generateSortedArray creates a sorted array of integers
func generateSortedArray(size int) []int {
	arr := generateRandomArray(size)
	sort.Ints(arr)
	return arr
}
