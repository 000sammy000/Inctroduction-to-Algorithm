#include<iostream>
#include<cstring>
#include<string>
using namespace std;
long long F[47];
void bfs(int N,int left,int right){
	if(N==0)cout<<0;
	else if(N==1)cout<<1;
	else{
		if(right<F[N-2])
			bfs(N-2,left,right);
		else if(left>=F[N-2])
			bfs(N-1,left-F[N-2],right-F[N-2]);
		else{
			bfs(N-2,left,F[N-2]-1);
			bfs(N-1,0,right-F[N-2]);
		}
	}
		
}
int main(){
	F[0]=1;F[1]=1;
	for(int i=2;i<47;i++){
		F[i]=F[i-2]+F[i-1]; // F[46]>2^31
	}
	
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		if(N>46)
			N=46+N%2;
		int i,j;
		cin>>i>>j;

		bfs(N,i,j);
	
		cout<<endl;
	}

	return 0;
}
