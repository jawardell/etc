package graphs;

import java.util.*;

public class Main {
	static int numVertices, itercount = 0;
	static Scanner console = new Scanner(System.in);
	static ArrayList<Vertex> graph;
	static int[][][] adjMatrix;

	public static void main(String[] args) {
		graph = new ArrayList<>();
		try {
			fillMatrix();
			initVertices();
			assignNeigbors();
			displayGraph();
			getGreedyPath();

		} catch (Exception e) {
			System.out.println("\n\t\tAn exception occured.");
		}

	}

	public static void initMatrix() {
		for (int i = 0; i < adjMatrix.length; i++) {
			for (int j = 0; j < adjMatrix[0].length; j++) {
				for (int k = 0; k < 2; k++) {
					adjMatrix[i][j][k] = -1;
				}
			}
		}
	}

	public static void printMatrix() {
		System.out.print("\n");
		for (Vertex v : graph) {
			System.out.printf("  %6s", v.getLabel());
		}
		System.out.print("\n");
		for (int i = 0; i < adjMatrix.length; i++) {
			for (int j = 0; j < adjMatrix[0].length; j++) {
				if (j == 0) {
					System.out.printf("%2s[%4d:%d, ", graph.get(i).getLabel(), adjMatrix[i][j][0], adjMatrix[i][j][1]);
				} else if (j == adjMatrix[0].length - 1) {
					System.out.printf("%4d:%d]\n", adjMatrix[i][j][0], adjMatrix[i][j][1]);
				} else {
					System.out.printf("%4d:%d,", adjMatrix[i][j][0], adjMatrix[i][j][1]);
				}
			}
		}
		System.out.println("\n");
	}

	public static void fillMatrix() {
		System.out.print("\n\nAdjacency Matrix Initialization\n\n\t~~~~~~~~~~~~~~~~\n");
		System.out.println("\n\nEnter the number of vertices: ");
		numVertices = console.nextInt();
		adjMatrix = new int[numVertices][numVertices][2];
		graph.clear();
		initMatrix();
		System.out.println("\nVertex Labeling\n");
		for (int i = 0; i < numVertices; i++) {
			System.out.println("vertex " + i + " label: ");
			Vertex vertex = new Vertex(console.next());
			graph.add(vertex);
		}
		printMatrix();
		for (int i = 0; i < adjMatrix.length; i++) {
			for (int j = 0; j < adjMatrix[0].length; j++) {
				System.out.println("\nEnter the edge values for [" + i + "][" + j + "]");
				System.out.println("White Value: ");
				adjMatrix[i][j][0] = console.nextInt();
				System.out.println("Black Value: ");
				adjMatrix[i][j][1] = console.nextInt();
				printMatrix();
			}
		}
		System.out.print("\n\nIs this information correct? Type 1 to proceed and 0 to try again: ");
		int input = console.nextInt();
		switch (input) {
		case 1:
			break;
		case 0:
			fillMatrix();
		default:
			break;
		}
	}

	public static void initVertices() {
		System.out.println("\n\n\nVertex Initialization\n\n\t~~~~~~~~~~~~~~~~\n");
		for (Vertex v : graph) {
			System.out.print("\n\nVertex " + v.getLabel() + " is white, true = 1 /false = 0: ");
			switch (console.nextInt()) {
			case 1:
				v.setWhite(true);
				break;
			case 0:
				v.setWhite(false);
				break;
			}
			System.out.print("\nEnter " + v.getLabel() + "'s white cost, an integer: ");
			v.setWhiteCost(console.nextInt());
			System.out.print("\nEnter " + v.getLabel() + "'s black cost, an integer: ");
			v.setBlackCost(console.nextInt());
		}
		System.out.print("\n\nIs this information correct? Type 1 to proceed and 0 to try again: ");
		int input = console.nextInt();
		switch (input) {
		case 1:
			graph.get(0).setStable(true);
			break;
		case 0:
			initVertices();
		default:
			graph.get(0).setStable(true);
			break;
		}
	}

	public static void displayGraph() {
		for (Vertex v : graph) {
			System.out.print(v.toString());
		}

	}

	public static void assignNeigbors() {
		for (int row = 0; row < adjMatrix.length; row++) {
			graph.get(row).initNeighbors();
			for (int col = 0; col < adjMatrix[0].length; col++) {
				if ((adjMatrix[row][col][0] != 0) && (adjMatrix[row][col][1] != 0)) {
					graph.get(row).addNeighbor(col, graph);
				}
			}
		}
	}

	public static boolean graphIsStable() {
		for (int i = 1; i < graph.size(); i++) {
			if (!graph.get(i).isStable()) {
				return false;
			}
		}
		return true;
	}

	public static void getGreedyPath() {
		ArrayList<String> path = new ArrayList<>();

		graph.get(0).setStable(true);
		System.out.println("\n\na.stable: " + graph.get(0).getRawStable() + " before\n\n");
		for (int i = 1; i < 100; i++) {
		//while(!graphIsStable()) {
			int scheduler = (int)(Math.random() * (numVertices-1) + 1);;
			int min = Integer.MAX_VALUE;
			Vertex minNeighbor = null;
			Vertex vertex = graph.get(scheduler);
			if (vertex.isWhite()) {
				for (Vertex neighbor : vertex.getNeighbors()) {
					if ((neighbor.getWhiteCost() + adjMatrix[scheduler][graph.indexOf(neighbor)][0]) < min) {
						min = neighbor.getWhiteCost() + adjMatrix[scheduler][graph.indexOf(neighbor)][0];
						minNeighbor = neighbor;
					} else {
						vertex.setMinCount(vertex.getMinCount() + 1);
					}
				}
				vertex.setWhiteCost(adjMatrix[scheduler][graph.indexOf(minNeighbor)][0]);
				vertex.setBlackCost(adjMatrix[scheduler][graph.indexOf(minNeighbor)][1]);
				path.add(String.format("%3d. %3s to %3s. %3s stable: %6b. \tgraph is stable: %6b.\n", itercount++, vertex.getLabel(),
						minNeighbor.getLabel(), vertex.getLabel(), vertex.isStable(), graphIsStable()));
//				path.add(itercount++ + ". " + vertex.getLabel() + " to " + minNeighbor.getLabel() + ".  "
//						+ vertex.getLabel() + " stable: " + vertex.isStable() + ". graph is stable: " + graphIsStable()
//						+ "\n");

			} else {
				for (Vertex neighbor : vertex.getNeighbors()) {
					if ((neighbor.getBlackCost() + adjMatrix[scheduler][graph.indexOf(neighbor)][1]) < min) {
						min = neighbor.getBlackCost() + adjMatrix[scheduler][graph.indexOf(neighbor)][1];
						minNeighbor = neighbor;
					} else {
						vertex.setMinCount(vertex.getMinCount() + 1);
					}
				}
				vertex.setWhiteCost(adjMatrix[scheduler][graph.indexOf(minNeighbor)][0]);
				vertex.setBlackCost(adjMatrix[scheduler][graph.indexOf(minNeighbor)][1]);
				path.add(String.format("%3d. %3s to %3s. %3s stable: %6b. \tgraph is stable: %6b.\n", itercount++, vertex.getLabel(),
						minNeighbor.getLabel(), vertex.getLabel(), vertex.isStable(), graphIsStable()));
//				path.add(itercount++ + ". " + vertex.getLabel() + " to " + minNeighbor.getLabel() + ".  "
//						+ vertex.getLabel() + " stable: " + vertex.getRawStable() + ". graph is stable: " + graphIsStable()
//						+ "\n");
			}

		}
		String message = "";
		for (String string : path) {
			message += string;
		}
		System.out.println("\n\n\n" + graph.get(0).getLabel() + ".stable after: " + graph.get(0).getRawStable() + "\n\n" + message);
	}

}