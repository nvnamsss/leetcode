package main

func trygo(gas []int, cost []int, start int) bool {
	at := start
	tank := gas[at]
	length := len(gas)
	for tank >= cost[at] {
		tank -= cost[at]
		at = (at + 1) % length
		tank += gas[at]
		if at == start {
			return true
		}
	}

	return false
}

func canCompleteCircuit(gas []int, cost []int) int {
	length := len(gas)
	for loop := 0; loop < length; loop++ {
		if gas[loop] >= cost[loop] && trygo(gas, cost, loop) {
			return loop
		}
	}

	return -1
}
