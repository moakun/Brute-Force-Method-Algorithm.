#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int> > ps;		
void PSet(int n)			//Find the power set ps of 1~n

{  vector<vector<int> > ps1;		//subpower set
   vector<vector<int> >::iterator it;//Power set iterator
   vector<int> s;
   ps.push_back(s);			//Add {} empty collection element
   for (int i=1;i<=n;i++)		//Add 1~n cyclically
   {	ps1=ps;			//ps1 stores the power set obtained in the previous step
	for (it=ps1.begin();it!=ps1.end();++it)
	  (*it).push_back(i);		//Add i at the end of each set element of ps1
	for (it=ps1.begin();it!=ps1.end();++it)
	  ps.push_back(*it);		//Add each collection element of ps1 to ps
   }
}
void Knap(int w[],int v[],int W)	//Seek all the solutions and the best solutions
{  int count=0;			
   int sumw,sumv;		
   int maxi,maxsumw=0,maxsumv=0;	
   vector<vector<int> >::iterator it;	
   vector<int>::iterator sit;			
   printf("  Number\tselected item\ttotal weight\ttotal value\tcan it be loaded\n");
   for (it=ps.begin();it!=ps.end();++it)	//Scan every collection element in ps
   {	printf("  %d\t",count+1);
	sumw=sumv=0;
	printf("{");
	for (sit=(*it).begin();sit!=(*it).end();++sit)
	{   printf("%d ",*sit);
	    sumw+=w[*sit-1];			
	    sumv+=v[*sit-1];			
	}
printf("}\t\t%d\t%d  ",sumw,sumv);
      if (sumw<=W)
      {  printf("?\n");
         if (sumv>maxsumv)			
         {  maxsumw=sumw;
            maxsumv=sumv;
            maxi=count;
         }
      }
      else printf("no\n");
      count++;				
   }
   printf("the best solution is: ");
   printf("selected items");
   printf("{ ");
   for (sit=ps[maxi].begin();sit!=ps[maxi].end();++sit)
	printf("%d ",*sit);
   printf("},");
   printf("total weight :%d,total value:%d\n",maxsumw,maxsumv);
}
int main()
{  int n=4,W=6;
   int w[]={5,3,2,1};
   int v[]={4,4,3,1};
   PSet(n);
   printf("0/1knapsack solution.\n",n);
   Knap(w,v,W);
};

