#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,string> table;
string context[101];
string m[101];

void guess(string str,int cxt_num){
	int differ=100,gs,no;
	string lon,sho;
	for(int i=0;i<cxt_num;i++){
		no=0;
		if(m[i].size()<str.size()){
			
			lon=str;sho=m[i];
			
		}else if(m[i].size()>str.size()) {
			
			lon=m[i];sho=str;
			
		}else continue;
//		cout<<"L "<<lon<<"  S "<<sho<<endl;
		for(int j=0;j<sho.size();j++){
//			cout<<lon[j]<<" "<<sho[j]<<endl;
			if(lon[j]!=sho[j]){
				no=1;
				break;
			}
		}
		if(no==1)continue;
		int a=lon.size(),b=sho.size();
		if(a-b<differ){
			differ=a-b;
			gs=i;
		}
	}
	cout<<context[gs]<<"?"<<endl;
}
string change(string str){
	string str1=table[str[0]];
	for(int i=1;i<str.size();i++){
		str1=str1+table[str[i]];
	}
	return str1;
}
int main(){
	
	char temp1;
	string temp2;
	while(cin>>temp1&&temp1!='*'){
		cin>>temp2;
		table[temp1]=temp2;
	}
	
	int cxt_num=0;
	//temp2 becomes context
	while(cin>>temp2&&temp2!="*"){
		context[cxt_num]=temp2;
		m[cxt_num]=change(temp2);
		cxt_num++; 
	}
	
	//temp2 becomes morse word
	int bingo,first;
	while(cin>>temp2&&temp2!="*"){
		bingo=0;
		for(int i=0;i<cxt_num;i++){
			if(temp2==m[i]){
				bingo++;
				if(bingo==1)first=i;
			}
		}
		if(bingo>0){
			cout<<context[first];
			if(bingo>1)
				cout<<"!";
			cout<<endl;
		}else{
			guess(temp2,cxt_num);
		}
	}	
	
	return 0;
}
