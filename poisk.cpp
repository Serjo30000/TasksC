#include <iostream>
using namespace std;
 
int main()
{
	int size=4;//Количество цифр
	int arr[size]={1,2,3,4};//Цифры
	int f=1;
	int x=0;
	int n=0;
	int p=0;
	int s=1;
	int temp=0;
	int t=0;
	int d=0;
	int po=0;
	int r=1;
	int w=0;
	int q=1234;//Значение для окончания
	for (int i=0;i<size;i++){
		cout<<arr[i];
	}
	cout<<"\n";
	while (f){
		for (int i=size-1;i>0;i--){
			if (i==size-1){
				x=arr[size-1];
				p=i;
			}
			if (x<arr[i-1] and w==0){
				x=arr[i-1];
				p=i-1;
			}
			else if (x>arr[i-1] and w==0){
				d=arr[i-1];
				po=i-1;
				n=size-i-1;
				w=1;
			}
		}
		if (d!=0){
			for (int i=size-1;i>size-n-1;i--){
				if (x>arr[i] and arr[i]>d){
					x=arr[i];
					p=i;
				}
			}
			arr[p]=d;
			arr[po]=x;
		}
		p=0;
		po=0;
		w=0;
		d=0;
		while (s){
		    s=0;
		    for (int j=size-1;j>size-n-1;j--){
		        if (arr[j]<arr[j-1]){
		            temp=arr[j];
		            arr[j]=arr[j-1];
		            arr[j-1]=temp;
		            s=1;
		        }
		    }
		}
		s=1;
		x=0;
		for (int i=0;i<size;i++){
			cout<<arr[i];
		}
		cout<<"\n";
		for (int i=0;i<size;i++){
			t+=arr[i]*r;
			r*=10;
		}
		if (t==q){
			f=0;
			break;
		}
		t=0;
		r=1;
	}
}
