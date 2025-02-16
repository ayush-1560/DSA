class BrowserHistory {
public:
    stack<string>past;
    stack<string>future;
    string curr;
    BrowserHistory(string homepage) {
        curr=homepage;
    }
    
    void visit(string url) {
        past.push(curr);
        curr=url;
        future=stack<string>();
    }
    
    string back(int steps) {
        while(steps-- && !past.empty()){
            future.push(curr);
            curr=past.top();
            past.pop();
        }
        return curr;
    }
    
    string forward(int steps) {
         while(steps-- && !future.empty()){
            past.push(curr);
            curr=future.top();
            future.pop();
        }
        return curr;
    }
};
