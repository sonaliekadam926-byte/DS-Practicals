#include<iostream.h>
#include<conio.h>
#define max_col 10
struct element
{
 int row;
 int col;
 int value;
};
int createsparse(int mat[][5],int row,int col,element sparse[])
{
 int count=0;
 for(int i=0;i<row;i++)
 {
  for(int j=0;j<col;j++)
  {
   if(mat[i][j]!=0)
   {
    sparse[count].row=i;
    sparse[count].col=j;
    sparse[count].value=mat[i][j];
    count++;
   }
  }
 }
 return count;
}
void countcol(element sparse[],int nonzero,int col,int rowterm[])
{
 for(int j=0;j<col;j++)
  rowterm[j]=0;
 for(int i=0;i<nonzero;i++)
 {
  rowterm[sparse[i].col]++;
 }
}
void fastran(element sparse[],element transposed[],int nonzero,int col)
{
  int rowterm[max_col];
  int startpos[max_col];
  countcol(sparse,nonzero,col,rowterm);
  startpos[0]=0;
  for(int j=1;j<col;j++)
   startpos[j]=startpos[j-1]+rowterm[j-1];

  for(int i=0;i<nonzero;i++)
  {
   int col=sparse[i].col;
   int pos=startpos[col];
   transposed[pos].row=sparse[i].col;
   transposed[pos].col=sparse[i].row;
   transposed[pos].value=sparse[i].value;
   startpos[col]++;
  }
}
void display(element arr[],int nonzero,char msg[])
{
 cout<<"\n"<<msg<<" \n";
 for(int i=0;i<nonzero;i++)
 {
  cout<<"("<<arr[i].row<<","<<arr[i].col<<","<<arr[i].value<<") \n";
 }
}
void main()
{
 clrscr();
 int mat[4][5]={{0,0,3,0,4},{0,0,5,7,0},{0,0,0,0,0},{0,2,6,0,0}};
 int row=4,col=5;
 element sparse[20];
 element transposed[20];
 int nonzero=createsparse(mat,row,col,sparse);
 cout<<"Total number of nonzero:"<<nonzero<<endl;
 display(sparse,nonzero,"Before");
 fastran(sparse,transposed,nonzero,col);
 display(transposed,nonzero,"After");
 getch();
}