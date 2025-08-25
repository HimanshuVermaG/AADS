// arr of n size sum elements using rec

#include <iostream>
using namespace std;

int sumarr(int arr[], int indx, int n){
    if (indx==n){
        return 0;
    }
    return arr[indx]+ sumarr(arr,indx+1,n);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    int indx =0;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << sumarr(arr,indx, n);

    return 0;
}

