#include<iostream>
using namespace std;
int main(){
	int T;
	cin>>T;
	int n;
	while(T>0){
		cin>>n;
		int arr[n];
		
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int amount=arr[0]-arr[1],max=arr[0];
		for(int i=1;i<n;i++){
			if(amount<max-arr[i])
				amount=max-arr[i];
			if(arr[i]>max)
				max=arr[i];
		}
		
		cout<<amount<<endl;
		
		T--;
	} 
	return 0;
} 
