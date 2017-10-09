public class List {
	Node head;
	
	public List(Node head) {
		this.head = head;
	}
	

	public addNode(Node node) {
		Node current = head;
		while(current.right != null) {
			if(current.data < node.data) {
				current.setRight(node);
			}
			current = current.right;
		}		

	}
	
	public removeNode(Node node) {
		Node current = head;
		while(current.right != null) {
			if(current.data == node.data) {
				Node temp = current.left;
				current.setLeft = current.right;
				current.setRight = temp;
			}
			current = current.right;
		}
	}

	public Node getEndNode() {
		Node current = head;
		while(head.right != null) {
			current = current.right;
		}
		return current;
	}

	public Node getFirstNode() {
		return head;
	}


}
