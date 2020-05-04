package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func (node *TreeNode) depth(val int) int {
	if node == nil {
		return val
	}

	val += 1
	left := val
	right := val
	if node.Left != nil {
		left = node.Left.depth(val)
	}

	if node.Right != nil {
		right = node.Right.depth(val)
	}

	if left > right {
		return left
	}

	return right
}

func (node *TreeNode) diameter(max int) int {
	left := 0
	right := 0

	if node.Left != nil {
		left = node.Left.depth(0)
	}

	if node.Right != nil {
		right = node.Right.depth(0)
	}

	if (left + right) > max {
		return left + right
	}

	return max
}

func (node *TreeNode) Diameter() int {
	max := node.diameter(0)
	max_left := 0
	max_right := 0
	if node.Left != nil {
		max_left = node.Left.Diameter()
	}

	if node.Right != nil {
		max_right = node.Right.Diameter()
	}

	if max_left > max {
		max = max_left
	}

	if max_right > max {
		max = max_right
	}

	return max
}

func diameterOfBinaryTree(root *TreeNode) int {
	return root.Diameter()
}
