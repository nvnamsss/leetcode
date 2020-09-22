package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var result bool

func preorder(node *TreeNode, min *TreeNode, max *TreeNode) {
	if node == nil {
		return
	}

	if min != nil && node.Val <= min.Val {
		result = false
	}

	if max != nil && node.Val >= max.Val {
		result = false
	}
	preorder(node.Left, min, node)
	preorder(node.Right, node, max)
}

func isValidBST(root *TreeNode) bool {
	result = true
	preorder(root, nil, nil)
	return result
}
