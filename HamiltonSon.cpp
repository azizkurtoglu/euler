#include <iostream>
#include <fstream>
//***Program for calculating a random Hamiltonian Path from a road distance 
//matrix taken from a txt file.*** 
using namespace std;

void permute (int[]);






 
  int m[81][81];
 
  int p[81];
  
  int k=0;
  int l=0;
  int x;

int sum=0;
int dizi[80];
int sayac=0;


int main()
{
  

 //First the distance matrix is loaded from Hamilton.txt file.  
  ifstream inFile;
  
  inFile.open("Hamilton.txt");
 
  while (inFile >> x)
  {
         
       
       
          m[k][l]=x;
         
          l++;
          if (l%81==0)
          {
                      k++;
                      l=0;
          }
        
        } 
        
       inFile.close();
        
      for (int t=0; t<81; t++)
    {
            if (t<6)
      dizi[t]=t+1; 
      else  if (t>6)
      dizi[t-1]=t+1;
      }
      
      //permute function called and it finds a permutation for the dizi[] array
      //representing the towns in Turkey except Ankara (06).
        
         permute(dizi);
         cout<<endl;
         cout<<endl;
      //permute function changes dizi[] array to a permutation of towns except 
      //Ankara (06) and it is printed to the screen.   
         cout<<"Bulunan sehirler arasi Hamilton permutasyon yolu:"<<endl;
         cout<<"06-";
        for (int z=0; z<80; z++)
     { if (dizi[z]<10)
            cout<<"0"<<dizi[z]<<"-";
            else cout<<dizi[z]<<"-";
     }
      cout<<"06";
      cout<<endl;
      //The sum of the road distances in the permutation of the Hamilton Tour 
      //is calculated.
      int temp=dizi[0];
      sum+=m[5][temp];
      for (int r=0; r<79; r++)
      {
          int temp1, temp2;
      temp1=dizi[r]-1;
      temp2=dizi[r+1]-1;
          sum+=m[temp1][temp2];
          }
          int temp3=dizi[79]-1;
      sum+=m[temp3][5];
      
        //The total road distance is printed to the screen. 
        cout<<"Bu permutasyonun yol uzunlugu: "<<sum<<" km'dir."<<endl;
        
         system("PAUSE");   
    return 0;
}


void permute(int a[])
{  
     

     int i;
     
     srand(time(0));
     
     for (i=0; i<1000; i++)
     {
     int k=rand() % 80;
     
     int l=rand() % 80;
     
     swap(a[k], a[l]);
     }
  
    }

 
