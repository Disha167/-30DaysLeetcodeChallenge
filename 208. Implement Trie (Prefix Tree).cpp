class TrieNode{
public:
bool isTerminal;
TrieNode *children[26];
char data;
TrieNode(char ch)
{
    data=ch;
    for(int i=0;i<26;i++)
    {
        children[i]=NULL;
    }
    isTerminal=false;
}
};
class Trie {
public:
TrieNode* root;/*this is important for your trie to get memory allocated for that*/
    Trie() {
      root  = new TrieNode('/0');
    }
    void insertUtil(string word, TrieNode* rootLocal)
    {
        // cout<<rootLocal->data<<"\n";
        TrieNode* child;
        if(word.size()==0)
        {
            // cout<<"isTerminal "<<rootLocal->data<<"\n";
            rootLocal->isTerminal=true;
            return;
        }
        int index= word[0]-'a';
        // cout<<"index insert "<<index<<endl;
        if(rootLocal->children[index]!=NULL)//PRESENT
        {
            child=rootLocal->children[index];
            // cout<<"present insert "<<child->data<<"\n";

        }
        else//ABSENT
        {
            
            child=new TrieNode(word[0]);
            rootLocal->children[index]=child;
            // cout<<"absent insert "<<child->data<<"\n";
        }
        insertUtil(word.substr(1),child);
    }
    bool searchUtil(string word, TrieNode* rootLocal)
    {
        // cout<<rootLocal->data<<"\n";
        TrieNode* child;
        if(word.length()==0)
        {
            
            return rootLocal->isTerminal;
        }
        int index= word[0]-'a';
        // cout<<"index "<<index<<endl;
        if(rootLocal&&rootLocal->children[index]!=NULL)//PRESENT
        {
            child=rootLocal->children[index];
            // cout<<"present "<<child->data<<"\n";
        }
        else
        {
            return false;
        }
        return true&&searchUtil(word.substr(1),child);
    }
bool startsWithUtil(string prefix, TrieNode* rootLocal)
{
    TrieNode* child;
    if(prefix.size()==0)//base condition to exit when prefix is traversed
    {
        return true;
    }

    int index=prefix[0]-'a';
    //present
    if(rootLocal->children[index]!=NULL)
    {
        child=rootLocal->children[index];

    }
    else
    {
        return false;

    }

    return startsWithUtil(prefix.substr(1),child);
}


    void insert(string word) {
        insertUtil(word,root);
        
    }
    
    bool search(string word) {
        return searchUtil(word,root);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(prefix,root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
