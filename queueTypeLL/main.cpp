#include <iostream>
#include "queuetype.cpp"

using namespace std;
int main() {
    QueType<string> q;
    string s;
    int n;
    cin>>n;

    q.Enqueue("1");
    while(n--){
        q.Dequeue(s);
        cout<<s<<endl;
        string s1;
        s1 = s;
        q.Enqueue(s.append("0"));
        q.Enqueue(s1.append("1"));
    }
    return 0;
}
