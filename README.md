# Depth-First Search (DFS) Tutorial

This repository contains implementations of various Depth-First Search (DFS) algorithms in C++ for solving common graph and grid-based problems. Below, each program is explained with its purpose, approach, and key concepts to help you understand and memorize the applications of DFS.

## Introduction to DFS
Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It uses a **stack** (either explicitly or via recursion) to keep track of vertices to explore. DFS is particularly useful for problems involving connectivity, cycles, paths, and topological ordering in graphs.

### Key Characteristics of DFS
- **Recursive Nature**: DFS is often implemented recursively, though an iterative version using a stack is also possible.
- **Time Complexity**: O(V + E) for graphs, where V is the number of vertices and E is the number of edges.
- **Space Complexity**: O(V) for the recursion stack and visited array.
- **Applications**: Cycle detection, finding connected components, topological sorting, path finding, and more.

Below is an explanation of each DFS-based program in this repository.

---

## 1. Basic DFS Traversal (`DFS.cpp`)
### Purpose
Performs a basic DFS traversal of an undirected graph, printing each vertex and its children as they are visited.

### Approach
- **Input**: Number of vertices (`n`) and edges (`m`), followed by `m` pairs of vertices representing edges.
- **Graph Representation**: Adjacency list using `vector<int> graph[N]`.
- **Visited Array**: `vis[N]` tracks visited vertices to avoid revisiting.
- **DFS Function**: Recursively visits a vertex, marks it as visited, and explores its unvisited neighbors.
- **Output**: Prints the vertex and its children during traversal.

### Key Concept
- DFS explores one path fully before backtracking, making it suitable for exploring all nodes in a connected component.
- The visited array prevents infinite loops in graphs with cycles.

### Use Case
- Understanding the structure of a graph.
- Exploring all nodes in a connected component.

---

## 2. Cycle Detection (`isloop.cpp`)
### Purpose
Detects whether an undirected graph contains a cycle using DFS.

### Approach
- **Input**: Number of vertices (`n`) and edges (`m`), followed by `m` edge pairs.
- **Graph Representation**: Adjacency list.
- **DFS Function**: Takes a vertex and its parent as parameters. Marks the current vertex as visited and checks its neighbors:
  - Skips the parent to avoid false positives.
  - If a neighbor is already visited (and not the parent), a cycle is detected.
  - Recursively explores unvisited neighbors.
- **Output**: Prints "There is a loop" if a cycle is found, else "No loop".

### Key Concept
- A cycle exists if a visited node (other than the parent) is encountered during DFS.
- The parent parameter helps distinguish back edges (indicating cycles) from tree edges.

### Use Case
- Checking if a graph has cycles (e.g., in dependency resolution or network analysis).

---

## 3. Height and Depth of Tree (`Height_depth.cpp`)
### Purpose
Computes the height and depth of each node in an undirected tree.

### Approach
- **Input**: Number of vertices (`n`) and edges (`m`) forming a tree.
- **Graph Representation**: Adjacency list.
- **DFS Function**:
  - Takes a vertex and its parent.
  - Sets the depth of a child as `depth[vertex] + 1`.
  - Updates the height of a vertex as the maximum height of its children plus 1.
- **Output**: Prints each node's index, height, and depth.

### Key Concept
- **Depth**: Distance from the root to a node (number of edges).
- **Height**: Longest path from a node to a leaf in its subtree.
- DFS propagates depth downward and height upward during recursion.

### Use Case
- Analyzing tree structures, such as in file systems or organizational hierarchies.

---

## 4. Diameter of a Tree (`Diameter_of_tree.cpp`)
### Purpose
Finds the diameter of an undirected tree (the longest path between any two nodes).

### Approach
- **Input**: Number of vertices (`n`) and edges (`m`) forming a tree.
- **Graph Representation**: Adjacency list.
- **Algorithm**:
  - Run DFS from an arbitrary node (e.g., node 0) to find the node with the maximum depth (`mxnode`).
  - Run DFS again from `mxnode` to find the maximum depth, which is the diameter.
- **Output**: Prints the diameter of the tree.

### Key Concept
- The diameter is found by identifying the farthest node from an arbitrary node and then finding the farthest node from that node.
- DFS is used to compute distances (depths) in the tree.

### Use Case
- Finding the longest path in a network or tree structure.

---

## 5. Number of Islands (`Number_of_islands.cpp`)
### Purpose
Counts the number of islands (connected components of 1s) in a 2D binary grid.

### Approach
- **Input**: A 2D grid of 0s (water) and 1s (land).
- **Graph Representation**: The grid itself, with 8-directional connectivity (up, down, left, right, and diagonals).
- **DFS Function**:
  - Marks a cell as visited and explores all 8 adjacent cells that are land (1) and unvisited.
  - Each DFS call covers one island.
- **Main Logic**: Iterates over the grid, calling DFS on each unvisited land cell and incrementing an island counter.
- **Output**: Returns the number of islands.

### Key Concept
- DFS groups connected land cells into a single island.
- The 8-directional movement allows for diagonal connectivity.

### Use Case
- Image processing, geographic analysis, or counting connected regions.

---

## 6. Lowest Common Ancestor (LCA) (`LCA.cpp`)
### Purpose
Finds the lowest common ancestor of two nodes in an undirected tree.

### Approach
- **Input**: Number of vertices (`n`), edges (`m`), and two nodes (`x`, `y`) to find their LCA.
- **Graph Representation**: Adjacency list.
- **DFS Function**: Builds a parent array by setting each node's parent during traversal.
- **Path Function**: Constructs the path from a node to the root using the parent array.
- **LCA Logic**:
  - Computes paths from `x` and `y` to the root.
  - Compares paths to find the last common node (LCA).
- **Output**: Prints the LCA.

### Key Concept
- The LCA is the deepest node that is an ancestor of both input nodes.
- Paths to the root are compared to find the point where they diverge.

### Use Case
- Finding the common ancestor in genealogical trees or network routing.

---

## 7. Topological Sort (`TopoSort.cpp`)
### Purpose
Performs a topological sort on a directed acyclic graph (DAG) using both DFS and BFS.

### Approach
- **Input**: Number of vertices (`V`) and an adjacency list for a DAG.
- **DFS-Based Topological Sort**:
  - Uses DFS to visit nodes, pushing each node to a stack after its neighbors are processed.
  - The stack's reverse order gives the topological sort.
- **BFS-Based Topological Sort (Kahn’s Algorithm)**:
  - Computes in-degrees for each node.
  - Starts with nodes having in-degree 0, processes them, and reduces in-degrees of neighbors.
  - Collects nodes in a queue to form the topological order.
- **Output**: Prints the topological order.

### Key Concept
- Topological sort orders vertices such that if there’s an edge from `u` to `v`, `u` comes before `v`.
- DFS uses post-order processing; BFS uses in-degree reduction.

### Use Case
- Task scheduling, course prerequisites, or build systems.

---

## 8. Connected Components (`Connected_Components.cpp`)
### Purpose
Counts the number of connected components in an undirected graph.

### Approach
- **Input**: Number of vertices (`V`) and an adjacency list.
- **DFS Function**: Marks a node as visited and recursively visits all its unvisited neighbors.
- **Main Logic**: Iterates through all vertices, calling DFS on unvisited ones and incrementing a counter for each component.
- **Output**: Prints the number of connected components.

### Key Concept
- Each DFS call explores one connected component.
- The visited array ensures each node is processed only once.

### Use Case
- Network connectivity analysis or clustering.

---

## How to Use This Repository
1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   ```
2. **Compile and Run**:
   - Each program is written in C++ and can be compiled using a C++ compiler (e.g., g++).
   - Example:
     ```bash
     g++ DFS.cpp -o dfs
     ./dfs
     ```
3. **Input Format**:
   - For graph-based problems, input typically includes:
     - `n` (number of vertices) and `m` (number of edges).
     - `m` lines with `v1 v2` (edge between vertices `v1` and `v2`).
   - For grid-based problems (e.g., Number of Islands), the grid is hardcoded or can be modified in the code.
4. **Study and Memorize**:
   - Review each program’s purpose and key concepts.
   - Run the programs with sample inputs to see how DFS explores the graph.
   - Modify inputs to test edge cases (e.g., disconnected graphs, single-node graphs).

## Tips for Memorizing DFS
- **Understand the Recursion**: Visualize DFS as exploring a maze, going as deep as possible before backtracking.
- **Focus on Parameters**: Note how parameters like `parent` or `visited` array change based on the problem (e.g., cycle detection vs. height computation).
- **Practice with Visualizations**: Draw graphs or grids to trace DFS execution.
- **Compare DFS and BFS**: Understand when DFS is preferred (e.g., for deep exploration or cycle detection) over BFS (e.g., for shortest paths).

## Sample Inputs for Testing
### For Graph-Based Problems
```
Input:
5 4
1 2
2 3
3 4
4 5

Output (for DFS.cpp):
vertex : 2
Vertex :2 child : 1
Vertex :2 child : 3
vertex : 3
Vertex :3 child : 2
Vertex :3 child : 4
vertex : 4
Vertex :4 child : 3
Vertex :4 child : 5
vertex : 5
Vertex :5 child : 4
```

### For Number of Islands
```
Input (hardcoded):
{1, 1, 0, 0}
{0, 1, 0, 0}
{0, 0, 1, 1}
{0, 0, 0, 1}

Output:
2
```

## Conclusion
This repository provides a comprehensive set of DFS implementations for common graph problems. By studying these programs, running them with different inputs, and understanding the underlying concepts, you can master DFS and its applications. Happy coding!