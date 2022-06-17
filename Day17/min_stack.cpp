class MinStack {
    // yaha pe classic key waaal asolution jo ke sumeet malik ne karaya tha
    // wo nahe chal kyunki if numbers are very large then their ,multiplication and 
    //operations would go out of range
    
private:
    stack<pair<int,int>>s;
    //first is storing val and second is stroing the minimum uptill now 
public:
    MinStack() {
        while(!s.empty()){
            s.pop();
        }
    }
    
    void push(int val) {
        if(s.size()==0){
            s.push({val,val});
        }else{
           
            
            pair<int,int> temp = s.top();
            
            if(val<=temp.second){
                s.push({val,val});
            }else{
                s.push({val,temp.second});
            }
            
            
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */