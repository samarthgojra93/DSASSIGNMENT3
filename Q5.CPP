#include <iostream>
#include <stack>
using namespace std;

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

bool isOp(char c){
    return !(c=='+'||c=='-'||c=='*'||c=='/');
}

string toPost(string inf){
    stack<char> st;
    string post="";
    for(char c:inf){
        if(isOp(c)) post+=c;
        else{
            while(!st.empty() && prec(st.top())>=prec(c)){
                post+=st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){ post+=st.top(); st.pop(); }
    return post;
}

int eval(string post){
    stack<int> st;
    for(char c:post){
        if(isOp(c)) st.push(c-'0');
        else{
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            if(c=='+') st.push(a+b);
            else if(c=='-') st.push(a-b);
            else if(c=='*') st.push(a*b);
            else if(c=='/') st.push(a/b);
        }
    }
    return st.top();
}

int main(){
    string inf="3+7*5+4-5/2";
    string post=toPost(inf);
    cout<<"Infix: "<<inf<<endl;
    cout<<"Postfix: "<<post<<endl;
    cout<<"Result: "<<eval(post)<<endl;
}