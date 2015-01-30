#AIM: 
Implement any scheme to find the optimal solution for the TRAVELLING SALESMAN PROBLEM and then solve the same problem instance using any approximation algorithm and determine the error in the approximation.

##DESCRIPTION:
The travelling salesman problem (TSP) asks the following question: Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city? It is an NP-hard problem in combinatorial optimization, important in operations research and theoretical computer science.

The TSP has several applications even in its purest formulation, such as planning, logistics, and the manufacture of microchips. Slightly modified, it appears as a sub-problem in many areas, such as DNA sequencing. In these applications, the concept city represents, for example, customers, soldering points, or DNA fragments, and the concept distance represents travelling times or cost, or a similarity measure between DNA fragments. In many applications, additional constraints such as limited resources or time windows make the problem considerably harder. TSP is a special case of the travelling purchaser problem.

In the theory of computational complexity, the decision version of the TSP (where, given a length L, the task is to decide whether the graph has any tour shorter than L) belongs to the class of NP-complete problems. Thus, it is possible that the worst-case running time for any algorithm for the TSP increases superpolynomially (or perhaps exponentially) with the number of cities.

<<<<<<< HEAD
##ALGORITHM:



=======
>>>>>>> 74d0a1aee4e4c4ebee6bb606b7c370784610b805
##CODE:
<pre>`#`include &lt;iostream>

`#`include &lt;iomanip>

using namespace std;

const int MAX = 10;
int path[MAX];
static int k=0;
int count = 0;
int perm[120][7];
int tourcost[120];</pre>

<pre>void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}</pre>

<pre>void DepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n)
{
         int i;
         v[currentVertex]=1;
         path[k++]=currentVertex;
         for (i=0; i&lt;n; i++)
		if (g[currentVertex][i] && !v[i])
			DepthFirstSearch(i,v,g,n);
}</pre>

<pre>void permute(int *a, int i, int n)
{
   int j,k;
   if (i == n)
   {
       for(k=0;k&lt;=n;k++)
       {
           //start from 2nd column
           perm[count][k+1] = a[k];
       }
       count++;
   }
   else
   {
        for (j = i; j &lt;= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}</pre>

<pre>int AppTSP(int n, int cost[MAX][MAX])
{
	int i, j, u, v, min,Excost=0;
	int sum, k, t[MAX][2], p[MAX], d[MAX], s[MAX],tree[MAX][MAX];
	int source, count;
	int visited[MAX];
	for (i=0; i&lt;n; i++)
		visited[i] = 0;

	min = 9999;
	source = 0;

	for(i=0; i&lt;n; i++)
	{
		for(j=0; j&lt;n; j++)
		{
			if(cost[i][j] != 0 && cost[i][j] &lt;= min)
			{
				min = cost[i][j];
				source = i;
			}
		}
	}

	for(i=0; i&lt;n; i++)
	{
		d[i] = cost[source][i];
		s[i] = 0;
		p[i] = source;
	}
	s[source] = 1;
	sum = 0;
	k = 0;
	count = 0;

	while (count != n-1)
	{
		min = 9999;
		u = -1;
		for(j=0; j&lt;n; j++)
		{
			if(s[j] == 0)
			{
				if(d[j] &lt;= min)
				{
					 min = d[j];
					 u = j;
				}
			}
		}

		t[k][0] = u;
		t[k][1] = p[u];
		k++;
		count++;
		sum += cost[u][p[u]];
		s[u] = 1;

		for(v=0; v&lt;n; v++)
		{
			if(s[v]==0 && cost[u][v]&lt;d[v])
			{
				d[v] = cost[u][v];
				p[v] = u;
			}
		}
	}

	for(i=0; i&lt;n; i++)
	{
	    for(j=0; j&lt;n; j++)
	    {
	        tree[i][j]=0;
	    }
	}

    if(sum >= 9999)
        cout &lt;&lt; "\nSpanning tree does not exist";
    else
    {
        for(i=0; i&lt;k; i++)
        {
            tree[t[i][0]][t[i][1]] = tree[t[i][1]][t[i][0]] =1;
        }
    }

    DepthFirstSearch(0,visited,tree,n);

    cout &lt;&lt; "\n The Approximate Minimum Cost tour is" &lt;&lt; endl;
    for(i=0;i&lt;=k;i++)
    {
        cout &lt;&lt; path[i] &lt;&lt; "->";
        Excost += cost[path[i]][path[i+1]];
    }
    cout &lt;&lt; path[0];
    Excost += cost[path[i]][path[0]];
    cout &lt;&lt; "\n The Approximate Minimum Cost of the tour is" &lt;&lt; Excost &lt;&lt; endl;
    return Excost;
}</pre>

<pre>int main(void)
{
	int a[MAX][MAX] = { { 0,  4,  8,  9, 12},
                    { 4,  0,  6,  8,  9},
                    { 8,  6,  0, 10, 11},
                    { 9,  8, 10,  0,  7},
                    {12,  9, 11,  7,  0}};

    int NumOfCity = 5;
	int interCities = 4,i,j;
	int mct=999,mctIndex,Appmct;

    //Source and destination is 0 remaining are intermediary cities
    int city[4] = {1,2,3,4};
    permute(city, 0, interCities-1);
    for(i=0;i&lt;24;i++)
    {
        for(j=0;j&lt;5;j++)
        {
            tourcost[i]+= a[perm[i][j]][perm[i][j+1]];
        }
        if( mct > tourcost[i])
        {
            mct = tourcost[i];
            mctIndex = i;
        }
    }

	cout << "\n The Exact Minimum Cost tour is" &lt;&lt; endl;
	for(i=0;i&lt;NumOfCity;i++)
	cout &lt;&lt; perm[mctIndex][i] &lt;&lt; "->";
	cout &lt;&lt; perm[mctIndex][i];
	cout &lt;&lt; "\n The Exact Minimum Cost of the tour is" &lt;&lt; mct &lt;&lt; endl;

	Appmct = AppTSP(NumOfCity,a);
	cout &lt;&lt; "\n The error in Approximation is " &lt;&lt; Appmct - mct &lt;&lt; " units" &lt;&lt; endl;
	cout &lt;&lt; "\n The Accuracy ratio is " &lt;&lt; (float)Appmct / mct &lt;&lt; endl;
	cout &lt;&lt; "\n The Approximate tour is "&lt;&lt;(((float)Appmct / mct) - 1)*100&lt;&lt; " percent longer than the optimal tour" &lt;&lt; endl;

	return 0;
}</pre>

##OUTPUT:
<pre> The Exact Minimum Cost tour is
  0->1->2->4->3->0
  The Exact Minimum Cost of the tour is37

  The Approximate Minimum Cost tour is
  0->1->2->3->4->0</pre>
  <pre>The Approximate Minimum Cost of the tour is39

  The error in Approximation is 2 units

  The Accuracy ratio is 1.05405

  The Approximate tour is 5.40541 percent longer than the optimal tour</pre>
