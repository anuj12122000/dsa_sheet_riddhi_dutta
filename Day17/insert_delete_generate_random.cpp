class RandomizedSet {
    
    private:
    unordered_map<int,int>set;
    vector<int>v;
    
public:
    RandomizedSet() {
        while(v.size()!=0){
            v.pop_back();
        }
    }
    
    bool insert(int val) {
        
        if(set.find(val)!=set.end()){
            return false;
        }
        v.push_back(val);
        set[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(set.find(val)==set.end()){
            return false;
        }
        
        int vidx = set[val];
        int lvidx = v.size()-1;
        int lval = v[v.size()-1];
       
        v[vidx]=lval;   // -> array main swapping ho rahe hain values kii
        v[lvidx]=val;
        
        set[lval]=vidx;   // bsdic swapping  -> map main index ki swapping 
        set[val] = lvidx;  // basic swapping occurs here
            
        v.pop_back();
        
        
        auto it = set.find(val);
        set.erase(it);
        
        return true;
    }
    
    int getRandom() {
        int x = rand()%(v.size());
        return v[x];
    }
};
