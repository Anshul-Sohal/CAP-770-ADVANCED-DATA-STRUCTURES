#include<iostream>
#include<stack>
using namespace std;
bool isMatching(char a, char b){
    if(a == '(' && b == ')'){
        return true;
    }else if(a == '{' && b == '}'){
        return true;
    }else if(a =='[' && b == ']'){
        return true;
    }
    return false;
}

bool checkPrenthesis(string s){
    stack<char> st;
    for(int i = 0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }else if(ch == ')' || ch == ']' || ch == '}'){
            if(st.empty() || !isMatching(st.top(), ch)){
                return false;
            }else{
                st.pop();
            }
        }
    }
    return st.empty();
}
int main(){
    string expression;
    cout<<"Enter the expression=";
    cin>>expression;
    if(checkPrenthesis(expression)){
        cout<<"The paraenthesis are balanced"<<endl;
    }else{
        cout<<"The paraenthesis are not balanced"<<endl;
    }
    return 0;
}