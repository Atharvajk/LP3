#include<iostream>
#include<vector>
using namespace std;
int recursiveFibo(int n){
    if(n==0 || n==1)return n;
    return recursiveFibo(n-2)+recursiveFibo(n-1);
}
int Fibbo(int n){

    vector<int> vec(n+1);
    vec[0]=0;vec[1]=1;
    for(int i=2;i<=n;i++){
        vec[i]=vec[i-1]+vec[i-2];
    } 
    return vec[n];

}
int main(){
for(int i=0;i<10;i++){
    cout<<Fibbo(i)<<endl;
}

return 0;
}