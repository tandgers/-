#include <iostream>  
#include <time.h>  
#include <stdlib.h>  
#include <iomanip>  
using namespace std;  
int main()
{
	int random(double,double);  
	int k=1, RandomNumber0, a, b, temp;
	int (*Data)[6]=new int [k][6];
	int (*Red0)=new int [6];	
	int (*NewRed0)=new int [6];
	Red0[0]=0;Red0[1]=0;Red0[2]=0;Red0[3]=0;Red0[4]=0;Red0[5]=0;
	int (*Box0) [100]=new int [33][100];
	int (*Box) [100]=new int [33][100];

	/*��ÿ���������ʼ����*/


	for(int Number=0;Number!=3300;)
	{
		for(int m=0;m!=33;m++)
		{
			for(int n=0;n!=100;n++)
			{
				Box0[m][n]=Number;
				Box[m][n]=1;                //m��Ӧ����100��������
				
				Number++;
			}
		}			
	}
	delete []Box0;

	/*��ȡ���ڲ�Ʊ����*/
	/*���������ڳ��ֹ��ĺ����������Ӧ�Ŀ����Լ���*/
	
	
	cout<<"Ҫ���뼸������: ";
	cin>>k;	
	cout<<"��������������Ƿ�С��14!!!"<<endl;
	cout<<"����������������: ";
	for(int m=0; m!=k; m++)
	{
		for(int n=0; n!=6; n++)
		{
			cin>>Data[m][n];
			temp=Data[m][n];
			Box[temp-1][m*6+n]=0;           //�ú�������Ӧ�Ŀ����Լ�1
		}
	}


	/*��ʼ�������ĵ�ʱ����*/

	/*���������ó�������������Ļ�ѡ����*/
	
	srand(unsigned(time(0)));
	for(int m=0, n=0; Red0[5]==0;)              
	{
	
		RandomNumber0=random(0,3300);	
		a = RandomNumber0 / 100;	
		b = RandomNumber0 % 100;
		if(Box[a][b]==1)
		{
			Red0[m]=a+1;
			if(m==0)
			{				
				m++; 
				n++;                                     
			}				                          
			else
			{
				for(int i=1;i!=m+1;i++)                   //�ж����ѡ����ĺ�������Ƿ��ظ�
				{				
					if (Red0[m]!=Red0[m-i])
					{	
						n=m+1;
					}
					else				
					{		
						Red0[m]=0;	
						n=m;				
						break;
					}
				}	
	
				m=n;                                     //nֵΪ�����ظ��ĸ���
			}
			
		}
	}

	

	
	/*���õ��ĺ����������*/
		
	for(int i=0;i!=6;i++)
	{	
		for(int m=1;m!=6-i;m++)
		{		
			
			
			if(Red0[m-1]<Red0[m])
			{
			}
			else if(Red0[m-1]>Red0[m])
			{
				temp=Red0[m];
				Red0[m]=Red0[m-1];
				Red0[m-1]=temp;
			}
			else if(Red0[m-1]=Red0[m])
			{
				cout<<"�������bug!";
				goto bug1;
			}
			NewRed0[5-i]=Red0[5-i];
		}
	}

	NewRed0[0]=Red0[0];


	/*����������*/
	/*�;����صȴ������ɣ�*/

	cout<<"�˴λ�ѡ�ĺ������Ϊ��";
	
	for(int i=0;i!=6;i++)		
	{				
		cout<<NewRed0[i]<<"  ";			
	}

bug1:
	return 0;

}



int random(double start, double end)  
{  
    return start+rand()%(int)(end-start);  
	/*������ķ�ΧΪ[start,end)�е�����*/
}  