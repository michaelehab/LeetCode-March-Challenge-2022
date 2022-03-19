class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freq_stack;
    int max_freq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        max_freq = max(max_freq, freq[val]);
        freq_stack[freq[val]].push(val);
    }
    
    int pop() {
        int top_max_freq = freq_stack[max_freq].top();
        freq_stack[max_freq].pop();
        freq[top_max_freq]--;
        if(freq_stack[max_freq].empty()) max_freq--;
        return top_max_freq;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */