#include <iostream>

using namespace std;

void print_array(int a[], int length_a){

    cout<<"[";
    for(int i=0;i<length_a;i++){
        cout<<a[i]<<", ";
    }
    cout<<"]\n";
}

int isBst(int *a, int len)
{
	int cnt = 1;
	int ln = len;
	if(len < 2){
		//cout << "Length < 1" << endl;
		return 1;
	}
	while(len-cnt){
		if(a[cnt] == -1){
			cnt += 2;
			//cout << "continue " << endl;
			continue;
		}
		else if(a[cnt-1] < a[cnt] && abs(a[cnt] - a[cnt+1]) < a[cnt/2]){
            //cout << a[cnt] << a[cnt+1] <<endl;
            cnt +=2;
			//cout << "Returning 0" << endl;
			return 0;
		}
		else {
			cnt += 2;
			//cout << "inc 2" << endl;
		}
	}
    return 1;
}

int main()
{
	int n;
	cin >> n;

	int cnt = 0;

	int a[n];

	while(n--){
		cin >> a[cnt++];
	}

	if(isBst(a, cnt)){
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
    // print_array(a, cnt);
    // cout << cnt << endl;
	return 0;
}
