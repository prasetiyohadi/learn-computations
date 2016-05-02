//Sains Komputasi
//Program Simulasi Penyebaran Api
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
	{
	//Deklarasi
	srand(time(0)); 
	int scale;
	cout<<"Masukkan Ukuran Ladang (meter) : ";
	cin>>scale;	
	int tree[scale+2][scale+2] , trees[scale+2][scale+2], k, prob, jum=0; 
	
	//Inisiasi
	for (int i=1; i<=scale; i++)
		{
		for (int j=1; j<=scale; j++)
			{
			tree[i][j]=1;
			trees[i][j]=tree[i][j]; //posisi tanaman
			}
		}
	
	k = rand()%scale; //posisi api (k=scale/2)
	tree[k][k]=2;
	
	for (int i=1; i<=scale; i++)
		{
		for (int j=1; j<=scale; j++)
			{
			cout<<tree[i][j];
			}
		cout<<endl;
		}
	
	//Input	
	
	cout<<"Masukkan Burn probability (dalam %) : ";
	cin>>prob;
	
	//Simulasi
	for(int h=1; h<=scale; h++) //h = iterasi, program disetting sampai n kali iterasi 
		{
		//Clear
		//system("clear");
		
		cout<<"Iterasi ke-"<<h<<endl;
		//Boundary Setting
		for(int i=1; i<scale; i++)
			{
			tree[i][0]=tree[i][scale-2];
			tree[i][scale-1]=tree[i][1];
			tree[0][i]=tree[scale-2][i];
			tree[scale-1][i]=tree[1][i];
			}
		
		//Penyebaran tanaman
		for (int i=1; i<=scale; i++)
			{
			for (int j=1; j<=scale; j++)
				{
				if(tree[i][j]==0) trees[i][j]=0;
				if(tree[i][j]==1) 
					if(tree[i+1][j]==2||tree[i][j+1]==2||tree[i-1][j]==2||tree[i][j-1]==2)
						if(((rand()%99)+1)<=prob&&((rand()%99)+1)>10) //probImune tanaman 1
							trees[i][j]=2;
				if(tree[i][j]==2) trees[i][j]=0;
				}
			}
	
		for (int i=1; i<=scale; i++)
			{
			for (int j=1; j<=scale; j++)
				{
				tree[i][j]=trees[i][j];
				cout<<tree[i][j];
				}
			cout<<endl;
			}
		cout<<endl;
		}
	
	
	//Perhitungan Jumlah tanaman yang mati
	for (int i=1; i<=scale; i++)
		{
		for (int j=1; j<=scale; j++)
			{
			if(tree[i][j]==0||tree[i][j]==2) jum=jum+1;
			}
		}
	
	cout<<"ProbBurning->"<<prob<<"%"<<endl;
	cout<<"Jumlah tanaman yang terbakar adalah "<<jum<<endl;
	cout<<"Persen tanaman di Ladang yang terbakar adalah "<<(jum*100)/(scale*scale)<<"%"<<endl;
	
	system("pause");
	return 0;
	}

