#include<iostream>

using namespace std;

int main(){

    int arr[] = {10, 12, 13, 11, 16, 15, 14, 17, 19, 18};
    float prefix_avg[10];
    int sum = 0;

    for(int i=0;i<10;i++){
        sum += arr[i];
        prefix_avg[i] = (float)sum/(float)(i+1); 
        cout<<prefix_avg[i]<<"\n";
    }

}