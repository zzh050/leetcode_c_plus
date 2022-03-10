#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s2.empty()){
            s1.push(x);
        }else{
            int size = s2.size();
             for(int i=0;i<size;i++){
                int x= s2.top();
                s2.pop();
                s1.push(x);
            }
            s1.push(x);
        }
    }
    
    int pop() {
        if(s1.empty()){
            int x = s2.top();
            s2.pop();
            return x;
        }else{
            int size = s1.size();
            for(int i=0;i<size;i++){
                int x= s1.top();
                s1.pop();
                s2.push(x);
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
    }
    
    int peek() {
        if(s1.empty()){
            int x = s2.top();
            s2.pop();
            return x;
        }else{
            int size = s1.size();
            for(int i=0;i<size;i++){
                int x= s1.top();
                s1.pop();
                s2.push(x);
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
    }
    
    bool empty() {
        if(s1.size()==0&&s2.size()==0){
            return true;
        }else return false;
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main(){


}