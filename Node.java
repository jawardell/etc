public class Node {
	Node left;
	Node right;
	int data;
	public Node(Node left, Node right, int data) {
		this.left = left;
		this.right = right;
		this.data = data;
	}
	public void deleteSelf() {
		this.right.setLeft(this.left);
		this.left.setRight(this.right);
	}
	public void setRight(Node node) {
		this.right = node;
	}
	public void setLeft(Node node) {
		this.left = node;
	}
	public void setData(int data) {
		this.data = data;
	}
	public int getData() {
		return data;
	}
}
