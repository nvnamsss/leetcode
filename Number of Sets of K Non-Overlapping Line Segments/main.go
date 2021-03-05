package main

import (
	"log"
	"math"
	"math/big"
)

func combination(n int, k int) *big.Int {
	rs := big.NewInt(1)

	end := k*2 + 1
	for loop := 1; loop < end; loop++ {
		rs = rs.Mul(rs, big.NewInt(int64(n+k-loop)))
		rs = rs.Div(rs, big.NewInt(int64(loop)))
	}

	return rs
}

func numberOfSets(n int, k int) int {
	amount := combination(n, k)
	log.Println(amount)
	amount = amount.Div(amount, big.NewInt(int64(math.Pow10(9))+7))

	return int(amount.Int64())
}

func main() {
	rs := numberOfSets(42, 25)
	log.Printf("Case: (%v, %v) - Result: %v - Expect: %v", 42, 25, rs, 630775896)
}
