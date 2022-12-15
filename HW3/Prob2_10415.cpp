#include <iostream>
#include<cstring>
using namespace std;
string finger(char a){
	if(a=='c') return "0111001111";
	if(a=='d') return "0111001110";
	if(a=='e') return "0111001100";
	if(a=='f') return "0111001000";
	if(a=='g') return "0111000000";
	if(a=='a') return "0110000000";	
	if(a=='b') return "0100000000";
	if(a=='C') return "0010000000";
	if(a=='D') return "1111001110";
	if(a=='E') return "1111001100";
	if(a=='F') return "1111001000";	
	if(a=='G') return "1111000000";	
	if(a=='A') return "1110000000";	
	if(a=='B') return "1100000000";	
	else return "0000000000";
}
int main(){
	int t;
	cin>>t;
	string song;
	getline(cin,song);
	while(t>0){
		
		getline(cin,song);
		string last="0000000000",next;
		int total[10]={0,0,0,0,0,0,0,0,0,0};
		for(int i=0;i<song.size();i++){
			next=finger(song[i]);
			for(int j=0;j<10;j++){
				if(last[j]=='0'&&next[j]=='1')
					total[j]++;
			}
			last=next;
		}
		
		for(int i=0;i<9;i++){
			cout<<total[i]<<" ";
		}
		cout<<total[9]<<endl;
			
		t--;
	}
	
	return 0;
} 
