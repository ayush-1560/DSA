class Node{
    public:
    string val;
    Node* next;
    Node* prev;
    Node(string val){
        this->val=val;
        this->next=this->prev=NULL;
    }
};
class BrowserHistory {
public:
    Node* currentPage;
    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newPage = new Node (url);
        currentPage->next=newPage;
        newPage->prev = currentPage;
        currentPage = currentPage->next;
    }
    
    string back(int steps) {
        while(steps--){
            if(currentPage->prev){
                currentPage = currentPage->prev;
            }
            else break;
        }
        return currentPage->val;
    }
    
    string forward(int steps) {
        while(steps--){
            if(currentPage->next){
                currentPage = currentPage->next;
            }
            else break;
        }
        return currentPage->val;
    }
};
