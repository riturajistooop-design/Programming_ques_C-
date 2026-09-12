class Node {
public:
    char data;
    bool terminal;
    unordered_map<char,Node*> map;
    Node(char data){
        this->data = data;
        this->terminal = false;
    }
};
class Trie {
public:
    Node* head;
    Trie() {
        head = new Node('\0');
    }
    void insert(string word) {
        int n = word.length();
        Node* temp = head;
        for(int i=0;i<n;i++){
            if(temp->map.find(word[i])==temp->map.end()){
                Node* n = new Node(word[i]);
                temp->map[word[i]] = n;
                temp = n;
            }
            else{
                temp = temp->map[word[i]];
            }
        }
        temp->terminal = true;
    }
    
    bool search(string word) {
        int n = word.length();
        Node* temp = head;
        for(int i=0;i<n;i++){
            if(temp->map.find(word[i])==temp->map.end()) return false;
            temp = temp->map[word[i]];
        }
        if(temp->terminal == true) return true;
        return false;
    }
    
    bool startsWith(string word) {
        int n = word.length();
        Node* temp = head;
        for(int i=0;i<n;i++){
            if(temp->map.find(word[i])==temp->map.end()) return false;
            temp = temp->map[word[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */