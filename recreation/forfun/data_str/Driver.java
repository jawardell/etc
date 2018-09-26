public class Driver {
	public static void main(String[] args) {
		Node n1 = new Node(4);
		n1.insert(new Node(1), n1);
		n1.insert(new Node(3), n1);
		n1.insert(new Node(6), n1);
		n1.insert(new Node(2), n1);
		n1.dfs(n1);
		System.out.println();
		n1.bfs(n1);
		System.out.println();
		System.out.println(n1.contains(1, n1));
		System.out.println(n1.contains(2, n1));
		System.out.println(n1.contains(3, n1));
		System.out.println(n1.contains(4, n1));
		System.out.println(n1.contains(6, n1));
		System.out.println(n1.contains(7, n1));
		System.out.println(n1.contains(7, n1));
		System.out.println(n1.contains(9, n1));
	}
}
