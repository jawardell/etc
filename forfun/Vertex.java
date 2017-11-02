import java.util.*;
public class Vertex {
	private String label;
	private ArrayList<Vertex> neighbors;
	private ArrayList<Vertex> tmp;
	private int degree;
	private boolean isWhite;
	private int whiteCost;
	private int blackCost;
	private int minCount;
	private boolean isStable;
	public Vertex(String label, ArrayList<Vertex> neighbors, boolean isWhite, int whiteCost, int blackCost) {
		this.label = label;
		this.neighbors = neighbors;
		for(Vertex v: neighbors) {
			tmp.add(v);
		}
		this.isWhite = isWhite;
		this.whiteCost = whiteCost;
		this.blackCost = blackCost;
		degree = neighbors.size();
		isStable = false;
		minCount = 0;
	}
	public Vertex(String label) {
		this.label = label;
		isStable = false;
	}
	public boolean isStable() {
		return minCount > 4;
	}
	public boolean getRawStable() {
		return isStable;
	}
	public void setStable(boolean isStable) {
		this.isStable = isStable;
	}
	public int getMinCount() {
		return minCount;
	}
	public void setMinCount(int minCount) {
		this.minCount = minCount;
		if(minCount > 4) {
			isStable = true;
		}
	}
	public String getLabel() {
		return label;
	}
	public void setLabel(String label) {
		this.label = label;
	}
	public void addNeighbor(int i, ArrayList<Vertex> graph ) {
		neighbors.add(graph.get(i));
		degree = neighbors.size();
	}
	public ArrayList<Vertex> getNeighbors() {
		return neighbors;
	}
	public void setNeighbors(ArrayList<Vertex> neighbors) {
		this.neighbors = neighbors;
	}
	public void initNeighbors() {
		this.neighbors = new ArrayList<>();
		degree = neighbors.size();
	}
	public int getDegree() {
		return degree;
	}
	public void setDegree(int degree) {
		this.degree = degree;
	}
	public boolean isWhite() {
		return isWhite;
	}
	public void setWhite(boolean isWhite) {
		this.isWhite = isWhite;
	}
	public int getWhiteCost() {
		return whiteCost;
	}
	public void setWhiteCost(int whiteCost) {
		this.whiteCost = whiteCost;
	}
	public int getBlackCost() {
		return blackCost;
	}
	public void setBlackCost(int blackCost) {
		this.blackCost = blackCost;
	}
	public String toString() {
		String res = "";
		degree = neighbors.size();
		if(!(neighbors == null)) {
			for(Vertex v : neighbors) {
				res += v.getLabel() + " ";
			}
		} else {
			res = "null";
		}
		return "\n\nVertex: " + label + "\nNeighbors: " + res
		+ "\nisWhite: " + isWhite + "\nWhite Cost: " + whiteCost + "\nBlack Cost: " + blackCost + "\nDegree: " + degree;
	}
}
