#include<iostream>
using namespace std;

void towerOfHanoi(int n, int from, int aux, int to){
    if(n>0){
        towerOfHanoi(n-1, from, to, aux);
        cout<<"Moving "<<n<<" from "<<from<<" to "<<to<<endl;
        towerOfHanoi(n-1, aux, from, to);
    }
}
int main()
{
    int x;
    cout<<"Enter the number of discs you want to move:"<<endl;
    cin>>x;
    towerOfHanoi(x,1,2,3);
}
