package main

import (
	"fmt"
	"testing"
	"time"
)

const (
	arraySize   = 1000
	patternSize = 10000
)

func TestBranchPredictor(t *testing.T) {
	patterns := []string{
		PatternAlwaysTaken,
		PatternAlwaysNotTaken,
		PatternAlternating,
		PatternRandom,
		PatternMostlyTaken,
	}

	for _, pattern := range patterns {
		t.Run(pattern, func(t *testing.T) {
			bp := GenerateBranchPattern(pattern, 100)
			accuracy, _ := RunBranchPrediction(bp)

			// Just verify that we get some results, not testing specific values
			if accuracy < 0 || accuracy > 100 {
				t.Errorf("Invalid accuracy for %s: %f", pattern, accuracy)
			}
		})
	}
}

func BenchmarkBranchPatterns(b *testing.B) {
	results := make(map[string]struct {
		Accuracy float64
		Duration time.Duration
	})

	patterns := []string{
		PatternAlwaysTaken,
		PatternAlwaysNotTaken,
		PatternAlternating,
		PatternRandom,
		PatternMostlyTaken,
	}

	for _, pattern := range patterns {
		b.Run(pattern, func(b *testing.B) {
			// Generate pattern outside of timing
			bp := GenerateBranchPattern(pattern, patternSize)

			b.ResetTimer()

			var totalAccuracy float64
			var runs int

			for b.Loop() {
				accuracy, duration := RunBranchPrediction(bp)
				totalAccuracy += accuracy
				runs++

				// Store the last run's duration
				results[pattern] = struct {
					Accuracy float64
					Duration time.Duration
				}{
					Accuracy: accuracy,
					Duration: duration,
				}
			}

			// Update with average accuracy if we had multiple runs
			if runs > 1 {
				results[pattern] = struct {
					Accuracy float64
					Duration time.Duration
				}{
					Accuracy: totalAccuracy / float64(runs),
					Duration: results[pattern].Duration,
				}
			}
		})
	}

	// Print formatted results after all benchmarks complete
	fmt.Println(FormatBenchmarkResults(results))
}

// Run with different thresholds to see how branch prediction affects performance

func BenchmarkPredictableBranching_NegativeThreshold(b *testing.B) {
	sortedData := generateSortedArray(arraySize)

	b.ResetTimer()
	for b.Loop() {
		PredictableBranching(sortedData, -500)
	}
}

func BenchmarkUnpredictableBranching_NegativeThreshold(b *testing.B) {
	randomData := generateRandomArray(arraySize)

	b.ResetTimer()
	for b.Loop() {
		UnpredictableBranching(randomData, -500)
	}
}

func BenchmarkPredictableBranching_PositiveThreshold(b *testing.B) {
	sortedData := generateSortedArray(arraySize)

	b.ResetTimer()
	for b.Loop() {
		PredictableBranching(sortedData, 500)
	}
}

func BenchmarkUnpredictableBranching_PositiveThreshold(b *testing.B) {
	randomData := generateRandomArray(arraySize)

	b.ResetTimer()
	for b.Loop() {
		UnpredictableBranching(randomData, 500)
	}
}

// Example usage:
// go test -bench=. -benchmem
// This will show the performance difference between predictable and unpredictable
// branch patterns, demonstrating how the CPU's branch predictor affects performance.
