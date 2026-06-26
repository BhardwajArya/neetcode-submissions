struct TrieNode{
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i =0; i<26; i++){
            children[i]=nullptr;
        }
    }
};



class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c :  word){
            int idx = c - 'a';
            if(!cur->children[idx]){
                cur->children[idx]= new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true;

    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(char c : word){
            int idx = c - 'a';
            if(!cur->children[idx])return false;
            cur = cur->children[idx];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c: prefix){
            int idx = c - 'a';
            if(!cur->children[idx])return false;
            cur = cur->children[idx];
        }
        return true;
    }
};
