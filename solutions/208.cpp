struct TrieNode{
    TrieNode* children[26];
    bool isWord;

};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();

    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            if(!cur->children[word[i ]- 'a']){
                cur->children[word[i] -'a'] = new TrieNode();
            }
            cur = cur->children[word[i]-'a'];
            if(i == word.size()-1)
                cur->isWord = true;
        }
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            if(!cur->children[word[i]-'a']){
                return false;
            }
            cur = cur->children[word[i]-'a'];
        }
        if(cur->isWord) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;

        for(int i = 0; i < prefix.size(); i++){
            if(!cur->children[prefix[i]-'a']){
                return false;
            }
            cur = cur->children[prefix[i]-'a'];
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