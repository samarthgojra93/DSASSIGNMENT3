#include<iostream>
#include<stack>
using namespace std;

void revStr(string s){
    stack<char> st;

    for(char c : s){
        st.push(c);
    }

    cout << "revesed string: ";
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main(){
    string word = "DataStructure";
    revStr(word);
    return 0;
}