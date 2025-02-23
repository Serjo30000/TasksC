#include <iostream>
#include <fstream>
using namespace std;
//�����: ��������� ������ ����-15 ����: 15.05.2022

struct rle{//��������� ��� �������� ������
    int mas1[50][16];//������ ��� ���������� ����
    int mas2[50][16];//������ ��� �������� �����
};

void funcompressor(fstream &file,char *arr, int n){//������� ������ ������
	file.open("res.txt",ios::out);//�������� ����� ��� ������
	char y;//���������� ��� ��������� ���������� ������
	int k=1;//���������� ���������� ������
	if (file){//������� ������
		cout<<"������ �����: ";
		for (int i=0;i<n;i++){//���� ������ ������ ������
			y=arr[i];//���������� ���������� ��� ��������� ���������� ������
			if (y!=arr[i+1]){//������� ��� ��������� ���������� ������
				if (k>1){//������� ������ ���������� ���������� ������
					file<<k;//������ ���������� ���������� ������
					cout<<k;//����� ���������� ���������� ������
					k=1;//���������� ���������� ���������� ������
				}
				file<<arr[i];//������ �������� �����
				cout<<arr[i];//����� �������� �����
			}
			else{//������� ��� ������������� ������
				k++;//���������� ���������� ���������� ������
			}
		}
	}
	file.close();//�������� �����
}

void funpackaging(fstream &file,char *arr, rle *arr1, int n){//������� ��������
	file.open("packaging.txt",ios::out);//�������� ����� ��� ��������
	int s;//���������� �����
	int y;//���������� ��� ��������� ���������� ������
	int r=15;//����� � �������
	int k=1;//���������� ���������� ������
	int t=0;//����� � ���������
	char e;//������
	if (file){//������� ��� ����������� �����
		for (int i=0;i<n;i++){//���� ���������� ������� ���������� ������
			s=((int)arr[i])-48;//����� ���������� �����
			y=((int)arr[i])-48;//���������� ���������� ��� ��������� ���������� ������
			e=arr[i];
			if (y!=((int)arr[i+1])-48){//������� ��� ��������� ���������� ������
				while (r!=1){//���� �������� � �������� �������
					if (s>0){//������� ��� ���������� �������� �����
						arr1->mas2[t][r]=s%2;//���������� �������
						s/=2;//������� � ���������� ����
					}
					else{//������� ��� ������ �����
						arr1->mas2[t][r]=0;//������ ����
					}
					r--;//����� � �������
				}
				arr1->mas2[t][0]=0;//������ ����� �������� �����
				if (e>='0' and e<='9'){
					arr1->mas2[t][1]=0;//������ ����� �������� �����
				}
				else{
					arr1->mas2[t][1]=1;//������ ����� �������� �������
				}
				r=15;//���������� ������
				arr1->mas1[t][0]=-1;//������ ����� �������� ������ ���������� ������
				if (k>1){//������� ������ ���������� ���������� ������
					while (r!=0){//���� �������� � �������� �������
						if (k>0){//������� ��� ���������� �������� �����
							arr1->mas1[t][r]=k%2;//���������� �������
							k/=2;//������� � ���������� ����
						}
						else{//������� ��� ������ �����
							arr1->mas1[t][r]=0;//������ ����
						}
						r--;//����� � �������
					}
					arr1->mas1[t][0]=1;//������ ����� ���������� ������
					r=15;//���������� ������
					k=1;//���������� ���������� ���������� ������
				}
				t++;//����� � ���������
			}
			else{//������� ��� ������������� ������
				k++;//���������� ���������� ���������� ������
			}
		}
		for (int i=0;i<t;i++){//���� ������ �������� ������ ������ � �� ����������� � �������� ����
			for (int j=0;j<16;j++){
				if (arr1->mas1[i][0]!=-1){//������� ������ ���������� ���������� ������
					file<<arr1->mas1[i][j];//������ ���������� ���������� ������
				}
			}
			for (int j=0;j<16;j++){//������� ������ �������� �����
				file<<arr1->mas2[i][j];//������ �������� �����
			}
		}
	}
	file.close();//�������� �����
}

int main()
{
	setlocale( LC_ALL, "Russian");
	fstream file;//�������� ������������� �����
	char arr[20]={'9','9','9','9','a','a','4','5','6','7','3','3','9','9','b','b','b','0','0','1'};//��������� ������������������ ������
	int n=20;//���������� ������
	rle *arr1=new rle[1];//��������� ��� �������� ������
	funpackaging(file,arr,arr1,n);//������� ��������
	funcompressor(file,arr,n);//������� ������ ������
}
