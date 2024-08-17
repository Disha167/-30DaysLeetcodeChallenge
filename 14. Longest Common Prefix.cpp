//DAY 10 PROBLEM 1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()==true)
        return "";
    if(strs.size()==1)
        return strs[0];
    int flag=0;
   string ans="";
        
   for(int j=0;j<strs[0].size();j++)//we have to use strs[0].size() here... we cannot use untill flag==0 as in case of longest common prefix of ["flower","flower"], flag 
   //never becomes 0.
   {
      if(strs[j]==""&&j<strs.size()) 
          break;
      
       char x=strs[0][j];

       for(int i=1;i<strs.size();i++)
       {
           if(strs[i][j]==x)
           {
               if(i==strs.size()-1)
                  ans+=x;
           }
           else
           {
               flag=1;
               break;
           }
       }
       if(flag==1)
          break;
   }
 return ans;
    }
};

//Using Trie
class TrieNode{
public:
bool isTerminal;
TrieNode* children[26];
char data;
TrieNode(char ch){
    ch=data;
    for(int i=0;i<26;i++){
        children[i]=NULL;
    }
    isTerminal=false;
}
};
class Solution {
public:
TrieNode* root;
Solution(){
    root = new TrieNode('\0');
}  

    
    void insertUtil(TrieNode* rootLocal, string word)
    {
        TrieNode* child;
        if(word.size()==0)
        {
            rootLocal->isTerminal=true;
            return;
        }
        int index = word[0]-'a';
        if(rootLocal->children[index]!=NULL)//PRESENT
        {
            child=rootLocal->children[index];
        }
        else //ABSENT
        {
            child= new TrieNode(word[0]);
            rootLocal->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }
    bool searchPrefixUtil(TrieNode* rootLocal, string prefix){
        TrieNode* child;
        if(prefix.size()==0)
        return true;
        int index= prefix[0]-'a';
        if(rootLocal->children[index]!=NULL)//PRESENT
        {
            int count_of_children=0;
            for(int i=0;i<26;i++)
            {//rootLocal->isTerminal==false imp to check as in ab and a if isterminal is not checked then ab will be ans. You have to also check ifg any string is not eliminating in the prefix
                if(rootLocal->isTerminal==false&&rootLocal->children[i]!=NULL)
                count_of_children++;

            }
            if(count_of_children==1)//logic for prefix
            child=rootLocal->children[index];
            else
            return false;
        }
        else//ABSENT
        {
           return false;
        }
        return searchPrefixUtil(child,prefix.substr(1));

    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
       for(int i=0;i<strs.size();i++)
       {
        // cout<<"insert "<<strs[i]<<endl;
        insertUtil(root,strs[i]);
       }
       for(int i=0;i<=strs[0].size();i++)//<= as in substr function, 2nd argument is length
       {
        if(searchPrefixUtil(root,strs[0].substr(0,i)))
        {
            cout<<strs[0].substr(0,i)<<endl;
            if(ans.size()==0||((strs[0].substr(0,i)).size()>ans.size()))
            {
                // cout<<"prefix found "<<strs[0].substr(0,i)<<endl;
                ans=strs[0].substr(0,i);
            }

        }
       }
       return ans;


    }
};
