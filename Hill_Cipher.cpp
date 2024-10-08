#include <bits/stdc++.h>
using namespace std;

void getKeyMatrix(string key,  vector<vector<int>>&keyMatrix,int n)
{
    int k = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            keyMatrix[i][j] = (key[k])-'a';
            k++;
        }
    }
}

 vector<vector<int>>encrypt( vector<vector<int>>keyMatrix,vector<vector<int>>msgVector,int n){
   
    vector<vector<int>>cipherMatrix(n,vector<int>(1));
     int x, i, j;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;
          
             for (x = 0; x < n; x++)
            {
                cipherMatrix[i][j] += 
                     keyMatrix[i][x] * msgVector[x][j];
            }
         
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
    return cipherMatrix;
}
string  Hill_Chiper(string key,string msg,int n){
    vector<vector<int>>keyMatrix(n,vector<int>(n));
     getKeyMatrix(key,keyMatrix,n);
     string CipherText="";
     int i=0;
     while(i<msg.size()){
     vector<vector<int>>msgVector(n,vector<int>(1,23));
        for(int j=0;j<n;j++){
           msgVector[j][0]=msg[i]-'a';
           i++;
           if(i>=msg.size())break;
        }
         vector<vector<int>>res=encrypt(keyMatrix, msgVector,n);
         for(int j=0;j<n;j++){
            CipherText+=char(res[j][0]+'a');
         }
     }
     return CipherText;

}

pair<bool,int>CheckSize(int n){
    for(int i=1;i*i<=n;i++){
        if(i*i==n){
            return {1,i};
        }
    }
    return {0,-1};
}
int main(){
    string key,msg;
    cout<<"Enter the key (size must be square of any number)"<<endl;
    cin>>key;
    auto check=CheckSize(key.size());
    if(!check.first){
        cout<<"Invalid Key, Enter the key (size must be square of any number)"<<endl;
        cin>>key;
    }else{
        cout<<"Enter the msg you want to encript"<<endl;
        cin>>msg;
        string encMsg=Hill_Chiper(key,msg,check.second);
        cout<<"Encripted Msg is "<<encMsg;
    }
}