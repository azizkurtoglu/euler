#include <iostream>

//***Euler Path and Euler cycle finding program***///


using namespace std;

void euler (int[][1000], int, int);
int k;
int sayac=0;
int p[1000][1000];
int o[1000][1000];
int b[1000][1000];

int dizi[1000];

int main()
{
    //Entering how many vertices your graph has
    cout<<"How many vertices does your graph have?"<<endl;
    cin>>k;
    
    
    //Entering the adjacency matrix
     for(int i=0; i<k; i++)
    {
            for (int j=0; j<k; j++)
    {
            cout<<"If your vertex "<<i+1<<" has edge with vertex "<<j+1<<" enter 1, otherwise enter 0"<<endl;        
    cin>>p[i][j]; o[i][j]=p[i][j]; b[i][j]=p[i][j];
    cout<<endl;
     
}
 }
//Checking whether the graph is single piece (connected)
  for (int x=0; x<k; x++)
  {
      for (int e=0; e<k; e++)
      {
          if (p[x][e]==1)
          p[e][x]=0;
      }
  }  
  int sum=0;  
  for (int x1=0; x1<k; x1++)
  {
      for (int e1=0; e1<k; e1++)
      {
          if (p[x1][e1]==1)
          sum++;
      }
  }  
  if (sum<k)
  {
            cout<<"The graph is not single piece!"<<endl;
            system("PAUSE");
            exit(0);
            }
 
//calculating the degrees of the graph
int degree[k];
int degreesum=0;

  for (int x1=0; x1<k; x1++)
  {
      for (int e1=0; e1<k; e1++)
      {
          if (o[x1][e1]==1)
          degreesum++;
      }
      degree[x1]=degreesum;
      degreesum=0;
  }  
  
  //Calculating the number of degrees with an odd number
  int oddsum=0;
  for (int d1=0; d1<k; d1++)
  {
      if (degree[d1]%2==1)
      oddsum++;
  }
  if (oddsum>2)
  {
               cout<<"There is no euler path in this graph!"<<endl;
               system("PAUSE");
               exit(0);
               }

if (oddsum==2)
{
              for (int d2=0; d2<k; d2++)
              {
                  if (degree[d2]%2==1)
              euler(o, d2, k-1);
              }
              }
 if (oddsum==0)  
   euler(o, 0, k-1);
    
   
        
    
    system("PAUSE");
    return 0;
}

//The body of euler function
void euler(int a[][1000], int l, int r)
{
     int i,j;
     
     
     int toplam=0;
     for (int q = 0; q <= r; q++)
        {
 
  for (int s = 0; s <= r; s++)
         toplam+=a[q][s];
         
         }
         if (toplam==0)
        {
             cout<<endl<<"This is an euler path!"<<endl;
            for(int w=0; w<k; w++)
    
    
            cout<<dizi[w];
           
           
             int u=dizi[0];
            int v=dizi[k-1];
   if (b[u-1][v-1]==1) {
                       cout<<endl<<"This is also an euler cycle!"<<endl;
                        for(int w=0; w<k; w++)
    
    
            cout<<dizi[w];
                                 cout<<dizi[0];
                    
                    }
                    
   system("PAUSE");
   exit(0); 
        }  

else
{
    
   
      
        
        for (int i = l; i <= r; i++)
        {
 
  for (int j = 0; j <= r; j++)
         {   
           if(a[i][j]==1)
           
           {
                        
                          a[i][j]=0;
                          a[j][i]=0;
                dizi[sayac]=i+1;
                 sayac++;    
           
       euler(a, j, r);
         a[i][j]=1;      
    a[j][i]=1;  
            
    
       }
        
         
        
   

         
            
        }
       
        }
 
           
}

}
 
