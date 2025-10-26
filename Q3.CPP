#include<iostream>
#include<stack>
using namespace std;

void checkBalance(string s){
    stack<char> st;

    for(char c : s){
        if(c=='(' || c=='{' || c=='['){
            st.push(c);
        }
        else if(c==')' || c=='}' || c==']'){
            if(st.empty()){
                cout<<"Not balnced"<<endl;
                return;
            }

            char t = st.top();
            if((c==')' && t!='(') || (c=='}' && t!='{') || (c==']' && t!='[')){
                cout<<"Not balnced"<<endl;
                return;
            }
            st.pop();
        }
    }

    if(st.empty()) cout<<"Balanced"<<endl;
    else cout<<"Not balnced"<<endl;
}

int main(){
    string str="({abvdbfvbnsovv])";
    checkBalance(str);
    return 0;
}