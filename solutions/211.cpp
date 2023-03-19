struct TrieNode{
    TrieNode* nextLetters[26];
    bool isWord;
};
class Trie{
public:
    Trie(){
        root = new TrieNode();
    }
    void addWord(string word){
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            if(!cur->nextLetters[word[i]-'a'])
             cur->nextLetters[word[i]-'a']= new TrieNode();

            cur = cur->nextLetters[word[i]-'a'];
        }
        cur->isWord = true;
    }
    bool search(string word){
        return search(word, root);
    }
    bool search(string word, TrieNode* r){
        TrieNode* cur = r;
        for(int i = 0; i < word.size(); i++){
            if(word[i] == '.'){
                    for(int j = 0; j < 26; j++){
                        if(cur->nextLetters[j] &&
                        search(word.substr(i+1, word.size()-i-1), cur->nextLetters[j])){
                            return true;
                        }
                            
                    }
                    return false;
            }
            if(!cur->nextLetters[word[i]-'a'])
                return false;
            cur = cur->nextLetters[word[i]-'a'];
        }
        if(cur->isWord)
        return true;
        return false;
    }
private:
    TrieNode* root;
};
class WordDictionary {
public:
    Trie* trie;
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->addWord(word);
    }
    
    bool search(string word) {
       return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */