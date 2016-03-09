# Dynamic Programming

Consider the FIbonacci sequence:
  * F(n) = F(n-1) + F(n-2)
  * F(1) = F(2) = 1    

If we solve the recurrence relation, Then the runtime of this algorithm is θ(1.618^n)  

#### Top-Down Memorization
* Like BFS/DFS, we just used an array visited[i] to make sure that we only compute each subproblem at most once
```
    int main(){  
      visited[i] = false for 1 <= i <= n  
      F(n)  
    }  
    F(n){           //recursive function    
      if visited[n] == true, return answer[n];  
      if n == 1 or n == 2, return 1 ;  
      answer[n] = F(n-1) + F(n-2);  
      visited[n] = true;  
      return answer[n];   
    }  
```
* Time Complexity: Each subproblen run once, the total running time is O(n)

