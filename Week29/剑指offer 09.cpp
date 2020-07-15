class Solution
{
public:
    void push(int node) {
        while (stack2.size()>0){
            int s=stack2.top();
            stack2.pop();
            stack1.push(s);
        }
        stack1.push(node);
    }
 
    int pop() {
        while (stack1.size()>0){
            int s=stack1.top();
            stack1.pop();
            stack2.push(s);
        }
        int s=stack2.top();
        stack2.pop();
        return s;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};