#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int calculatePow(int x, int n,int q) {
        int num=x;
        if(n==0)return 1;
      
       int ans=1;
       while(n>0){
        if(n%2){
            ans=(ans*x)%q;
            n=n-1;
        }else{
            x=x*x;
            n=n/2;
        }
       }
        return ans;
    }
int main(){
    int q;
    vector<int>alphas;
    cout<<"Enter the prime number"<<endl;
    cin>>q;
   for(int alpha=3;alpha<q;alpha++){
    unordered_map<int,int>hash;
    int flag=1;
    for(int i=1;i<q;i++){
        int num=calculatePow(alpha,i,q);
        num=num%q;
        if(hash.find(num)!=hash.end()){
            flag=0;
            break;
        }else{
            hash[num]=1;
        }
     }
    
     if(flag){
            alphas.push_back(alpha);
     }
   }
    cout<<"Primitive Roots are"<<endl;
    for(auto it:alphas){
        cout<<it<<" ";
    }
    cout<<endl;

  int privateKeyA,privateKeyB;
  cout<<"Enter the private key of Sender"<<endl;
  cin>>privateKeyA;
  cout<<"Enter the private key of Receiver"<<endl;
  cin>>privateKeyB;
  int publicKeyA=calculatePow(alphas[0],privateKeyA,q)%q;
  int publicKeyB=calculatePow(alphas[0],privateKeyB,q)%q;
  
  int senderKey=calculatePow(publicKeyB,privateKeyA,q)%q;
  int receiverKey=calculatePow(publicKeyA,privateKeyB,q)%q;

  cout<<"Sender Key1 "<<senderKey<<endl;
  cout<<"Receiver Key1 " <<receiverKey<<endl;
  return 0;
}