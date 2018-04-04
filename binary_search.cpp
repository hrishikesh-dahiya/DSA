#include <iostream>
#include <algorithm>

using namespace std;

void print_array(char a[], int length_a){

    cout<<"[";
    for(int i=0;i<length_a;i++){
        cout<<a[i]<<", ";
    }
    cout<<"]\n\n";
}

int main(){

    int a[] = {5, 5, 6, 3, 8, 3, 1, 10, 2, 4, 2};
    char c[] = "Ashiwariya"; //why is it showing 11 characters?
    
    int length_a = sizeof(a)/sizeof(a[0]);
    int length_c = sizeof(c)/sizeof(c[0]);

    cout<<"\nThe array is : \n";
    print_array(c, length_c);
    cout<<length_c<<endl;

    sort(c, c + length_c);

    cout<<"Searching 's' in c : \n";
    if(binary_search(c, c + length_c, 'z')){
        cout<<"s is present in the array\n";
    } else {
        cout<<"s not in array\n";
    }

    cout<<endl;

}