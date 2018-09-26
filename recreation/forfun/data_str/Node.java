//Simple Implementation of an unbalanced and incomplete BST
class Node {
	Node right; 
	Node left; 
	int data; 
	Node(int data) {
		this.data = data;
		right = null;
		left = null;
	}

	void insert(Node node, Node root) {
		if((node.data > root.data) && (root.right == null)) {
			root.right = node;
			return;
		}

		if((node.data <= root.data) && (root.left == null)) {
			root.left = node;
			return;
		}

		if(node.data > root.data) 
			insert(node, root.right);

		if(node.data <= root.data) 
			insert(node, root.left);
	}

	void dfs(Node root) {
		if(root == null)
		       return;	
		System.out.println(root.data);
		dfs(root.left);
		dfs(root.right);
	}
	
	void bfs(Node root) {
		bfs(0, root);
	}

	private void bfs(int i, Node root) {
		if(root.right == null && root.left == null) 
			return;

		if(i == 0)
			System.out.println(root.data);

		if(root.left != null) { 
			System.out.println(root.left.data);
			bfs(i+1, root.left);
		}

		if(root.right != null) {
			System.out.println(root.right.data);
			bfs(i+1, root.right);
		}
	}
	
	boolean contains(int data, Node root) {
		if(root == null) 
			return false;

		if(data == root.data)
			return true;
		
		if(data < root.data) {
			if(root.left == null)
				return false;
			else 
				return contains(data, root.left);
		}

		if(data > root.data) {
			if(root.right == null)
				return false;
			else 
				return contains(data, root.right);
		}

		return false;
	}
}
