/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
const (
	DELIMITER = ","
)
type Codec struct {
    
}

func Constructor() Codec {
    return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
    if root == nil {
		return "";
	}
	serialized := "";
	var rec func(node *TreeNode) 
	rec = func(node *TreeNode) {
		if node == nil {
			serialized = serialized + DELIMITER
			return 
		}
		serialized = serialized + strconv.Itoa(node.Val) + DELIMITER
		rec(node.Left)
		rec(node.Right)
		return
	}
	rec(root)
	return serialized[:len(serialized)-1]
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
    if data == "" {
		return nil
	}
	nodeValues := strings.Split(data, DELIMITER)
	var rec func(i int) (*TreeNode, int)
	rec = func(i int) (*TreeNode, int) {
		if nodeValues[i] == "" || i >= len(nodeValues) {
			return nil, i
		}
		node := &TreeNode{
			Val: convertIntStringToInt(nodeValues[i]),
		}
		node.Left, i = rec(i+1)
		node.Right, i = rec(i+1)
		return node, i
	}
	root, _ := rec(0)
	return root
}

func convertIntStringToInt(val string) int {
	v, _ := strconv.Atoi(val)
	return v
}
