struct TrieNode{
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i]=nullptr;
        }
        isEnd=false;
    }
};


class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c: word){
            int idx = c - 'a';
            if(!cur->children[idx]){
                cur->children[idx]= new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isEnd=true;
    }
    bool dfs(TrieNode* node, string &word, int i){
        if(i==word.size())return node->isEnd;

        char c = word[i];

        if(c == '.'){
            for(int j =0; j<26; j++){
                if(node->children[j] && dfs(node->children[j], word, i+1)){
                    return true;
                }
            }
            return false;
        }
        else{
            int idx = c- 'a';
            

            if(!node->children[idx])return false;

            return dfs(node->children[idx], word, i+1);
        }
    }
    bool search(string word) {
       return dfs(root, word, 0);
    }
};
