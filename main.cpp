#include <iostream>
#include <algorithm>

using namespace std;

class edges
{
public:
    int source;
    int dest;
    int weight;
};

bool compare(edges e1,edges e2)
{
    return e1.weight<e2.weight;//return 0 or 1
}

int findparent(int v,int parent[])
{
    if(parent[v]==v)
    return v;
    return  findparent(parent[v],parent);
}

int main()
{
   int v;
   cin>>v;//no. of vertex
   int n;
   cin>>n;//no. of edges
   int scr,dst,wt;
   edges e[n];
   for(int i=0;i<n;i++)
   {
       cin>>scr;
       cin>>dst;
       cin>>wt;
       e[i].source=scr;
       e[i].dest=dst;
       e[i].weight=wt;
   }
   sort(e,e+n,compare);//edge based on weight
   int parent[n];
   for(int i=0;i<v;i++)
   {
       parent[i]=i;
   }
   int i=0;
   int count=0;//count is a variable
   edges currentedge[v-1];//safe edge A
   while(count<v-1)
   {
      int sourceparent=findparent(e[i].source,parent);
      int destparent=findparent(e[i].dest,parent);

      if(sourceparent!=destparent)
      {
        currentedge[count].source=e[i].source;
        currentedge[count].dest=e[i].dest;
        currentedge[count].weight=e[i].weight;
        count++;
        parent[sourceparent]=e[i].dest;
      }

      i++;
   }
   cout<<"\nMinimum spanning tree\n";
   for(int i=0;i<v-1;i++)
   {
       cout<<currentedge[i].source<<""<<currentedge[i].dest<<"";
       cout<<currentedge[i].weight<<endl;
   }

    return 0;
}
