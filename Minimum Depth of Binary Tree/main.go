package main

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func Min(a, b int) int {
	if a > b {
		return b
	}

	return a
}
func recursive(root *TreeNode, d int) int {
	if root.Left == nil && root.Right == nil {
		return d
	}

	dl := math.MaxInt32
	dr := math.MaxInt32

	if root.Left != nil {
		dl = recursive(root.Left, d+1)
	}

	if root.Right != nil {
		dr = recursive(root.Right, d+1)
	}

	return Min(dl, dr)
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	return recursive(root, 1)
}
