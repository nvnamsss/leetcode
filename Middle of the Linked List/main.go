package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func middleNode(head *ListNode) *ListNode {
	turtoise := head
	hare := head

	for hare != nil {
		hare = hare.Next

		if hare == nil {
			break
		}

		hare = hare.Next
		turtoise = turtoise.Next
	}

	return turtoise
}
