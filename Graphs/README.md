# Graphs

#### Graph Connectivity  
* **Defination**
  * Given an undirected graph, we say that two vertices u,v are connected if there is a path from u to v
  * A subst S in V is connected if s,v in V are connected for all s,t in V
  * A connected component is a maximally connected subset of vertices
* Some of the most basic question about a graph:
  * to determine whether it is connected
  * to find all the connecte components
  * to determine whether u,v are connected for given u,v
  * to determine the shortest path connecting u and v for givenu,v in V  
All the question above can be solved by **Breath First Search** (BFS) in O(n+m) time

#### Breadth First Search  
Imagine you are searchiing for a person in a social network, A natural stategy is to ask your friends, and then ask your friends to ask their friends and so on.
* **Basic version of BFS**:  
  * Input: G=(V,E), s in V
  * Output: all vertives reachable form s
  * Initialization: visited[v] = false for all v in V, queue Q is empty, enqueue(Q,s_, visited[s] = true
<pre><code>  
While Q != empty do
  u = dequeque(Q)
  for each neighbor v of u
    if visited[v] = false
        enqueque(Q,v). visited[v] = true
</code></pre>

* **Time complexity**:   
Each vertex is enqueued at most once when a vertex u is dequeued, the for loop is executed deg(u) times,So the total complexity is O(n + ∑deg(u)) = O(n+m)
* **Claim**: There is a path form s to c if and only if visited[v] = true at the end  
With this claim, we can determine following problem in linear time :
  1. whether a graph is connencted or not (by checking whether visitied[v] = true for all v in B)
  2. find the connected component containing v (the set of vertices with visited[v] = true)
  3. whether there is a path form s to t (by checking whether visited[v] = true)
* **BFS Tree**:
  * A BFS Tree is used to find a path of two vertices
  * Algrithom: we can add an array parent[v], when a vertex v is first visited, within the for loop of vertex u, then we set parent[v] = u. Now, to trace out a  path from v to s, we just need to write a for loop that starts from v, and keep going to its parent until s is reached
  * Claim the path is shortest path
<pre><code> Initialization: visited[v] = false for all v in V, queue Q is empty, enqueue(Q,s), vistied[v] = true, distace[x] =0
while Q!= empty do
  u = dequeue(Q)
  for each heighbor v of u
    if visitied[v] = false
        enqueue(Q,v), visited[v] = true, parent[v] = u, distance[v] = distance[v] + 1
</code></pre>

#### Depth First Search  
Imagine that we are in a maze searching for the exit, we could model this problem as a s-t connectivity problem in garphs, each square of the maze is a vertx, and two vertices have an edge, if and oonly if the two square are reachabel in one step, then finding a path from our current position to the exit is equivalent to finding a path betweent two specifed vertices in the graph( or determine none exists)
* **DFS** algorithm:
  * **Input**: an undirected graph G=(V,E), a vertex s in V
  * **Output**: all vertices reachable from s
<code>  
(main program)
visited[v] = fale for all v in V // gloval variable array
visited[v] = true. explore(x)
(explore(u)) //recursive function explore:
for each neigbour v of u
  if visitied[v] = false
    visitied[v] = true explore(v)
</code></pre>
* **Time Complexity**
  * Similar to BFS
    * each vertex u is called the recursice function explore(u) once
    * when explore(u) is excuted, the for loop executed deg(u) times
    * the total time complexity is thus O(n + ∑deg(u)) = O(n+m)
* **DFS Tree**
  * Defination:
    1. The starting vertex is regarded as the root of the DFS tree.
    2. A Vetex u is called the parent of a vertex v if the edge uv is in the DFS tree and u is closer to the root
    3. A vertex u is called an *ancestor* of a vertex if u is closer to the root than v, and u is on the path from v to the root , in this situation, we also call v a *descendent* of vertex u.
    4. A non-tree-edge uv is called a *back edge* if either u is an ancestor of v or u is a descendent of v. it is called a back edge because this edge was explored from the decendent to the ancestor
* Starting time and finishing time
We keep track of the time when a vertex if first visited and finished exporing, pseudocodo in the following:
<pre><code>  
(main program)
visited[v] = false for all v in V //global variable array
time =1       // the new variable keeping track the time
visited[s] = true, explore(s)
explore(u) // recursive function explore
  start[u] = time, time= time + 1 //start is an array to store starting time
  for each neighbour v of u
    if visited[v] = false
      visited[v] = true, explore(v)
  finish[u] = time. time <- time+1//finish is an array to store finishing time
</code></pre>
* Properties:
  1. The intervals [start(u),finish(u)] and [start(v),finish(v)] for u and v are either disjoint or one is contained in another. the latter case happens precising when u,v are an ancestor-descendent pair
  2. in an undirected garpgh, all non-tree edges are back edges
* **Cut vertices and cut edges**
Algorithm:  
The idea is to look at a DFS tree from bottom to up, and keep track of how far up the back edges of a subtree can go.  
In partiualr, for a non-root vertex v, all subtrees below v have an edges go above v if and onlf if v is not a cut vertex  
Lets define a calue low[v] for each vertex:  
low[v] := min(start[v], start[w](where uw is a  back edge with u a descendent of v or u = v
  * By this bototm up order, all vertice would only be processed once , and thus the total time complexity is O(n + ∑deg(u)) = O(n+m)
  * to check whether v is a cut vertex, we just need to check whether low[ui] < star[v]
  * [code]()










