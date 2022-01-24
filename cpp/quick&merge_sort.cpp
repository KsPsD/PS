#include<bits/stdc++.h>

using namespace std;


int arr[50];
int tmp[50];


vodi quicksort(int *arr ,int lt, int rt){
	if(start>=end){
		return;
	}
	int pivot= start;
	int p1 = pivot+1;
	int p2 = rt;
	int p3;
	
	while(p1<=p2){
		while(p1<=end&& arr[p1] <= arr[pivot]){
			p1++;
		}
		while(p2>start;  && arr[p2]>=arr[pivot]){
			p2--;
		}
		
		if(p1>=p2) break;
		
		p3 =arr[p1];
		arr[p1] = arr[p2];
		arr[p2] = p3;
	}
	
	p3 = arr[p2];
	arr[p2] = arr[pivot];
	arr[pivot] = p3;
	
	quicksort(arr,lt ,p2-1);
	quicksort(arr,p2+1,rt);
}

void divide(int lt, int rt){
	
	if(lt<rt){
		int mid =(lt+rt)/2;
		divide(lt,mid);
		divdie(mid+1,rt);
		int p1,p2,p3;
		p1= lt;
		p2= mid+1;
		p3 =lt;
		
		while(p1<=mid && p2<=rt){
			if(arr[p1]<arr[p2]) tmp[p3++] = arr[p1++];
			else tmp[p3++] = arr[p2++];
			
		}
		
		while(p1<=mid)tmp[p3++] = arr[p1++];
		while(p2<=rt) tmp[p3++] = arr[p2++];
		
		for(int i=lt ; i<=rt;i++){
			arr[i]  = tmp[i];
		}
	}

	
	
	
	
}




int main(){
	
	
	int n,i;
	
	for(int i=1; i<=n ;i++){
		cin>>arr[i] ;
	}
	
	divide(1,n);
	
	for(int i=1; i<=n;i++){
		cout<<arr[i]<<endl;
	}
	
	return 0;
}
