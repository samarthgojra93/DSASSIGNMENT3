#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "size of stack is : " << s.size() << endl;

    cout << "Stack elemnts are: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    stack<int> temp = s;

    cout << "copy stack element : ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}