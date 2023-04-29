#include<bits/stdc++.h>
using namespace std;

struct trieNode{
    char c;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char ch){
        this->c=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie{
        trieNode *root;
    public:
        Trie(){
            root=new trieNode('\0');
        }
        void insertTrie(trieNode* root,string word){
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            trieNode* child=NULL;
            if(root->children[word[0]-'a']!=NULL){
                child=root->children[word[0]-'a'];
            }else{
                cout<<word[0];
                child= new trieNode(word[0]);
                root->children[word[0]-'a']=child;
            }
            insertTrie(child,word.substr(1));
        }
        void insertUtility(string word){
            insertTrie(root,word);
        }

        bool searchTrie(trieNode* root,string word){
            if(word.length()==0){
                return root->isTerminal;
            }
            trieNode* child=NULL;
            if(root->children[word[0]-'a']!=NULL){
                child=root->children[word[0]-'a'];
            }else{

                return false;
            }

            return searchTrie(child,word.substr(1));
        }

        bool searchUtility(string word){
            return searchTrie(root,word);
        }

        bool removeTrie(trieNode* root,string word){
            if(word.length()==0){
                if(!root->isTerminal){
                    cout<<"Sorry This does not exist\n";
                    return false;
                }


                int count=0;
                for(int i=0;i<26;i++){
                    if(root->children[i]){
                        count++;
                        break;
                    }
                }
                bool ans;
                if(!count)
                    ans=true;


                root->isTerminal=false;
                return ans;
            }
            trieNode* child;
            if(root->children[word[0]-'a']){
                child=root->children[word[0]-'a'];
                if(removeTrie(child,word.substr(1))){
                    root->children[word[0]-'a']=NULL;

                    int count=0;
                    for(int i=0;i<26;i++){
                        if(root->children[i]){
                            count++;
                        }
                    }

                      if(!count)
                        return true;
                }else
                        return false;
            }else{
                return false;
            }
        }

        void removeUtility(string word){
            removeTrie(root,word);
        }

};

int main(){
    Trie obj;
    obj.insertUtility("help");
    cout<<"\n";
    obj.insertUtility("helpo");
    cout<<"\n";
    obj.insertUtility("hello");
    cout<<"\n";
    obj.removeUtility("help");

    cout<<obj.searchUtility("helpo");
    return 0;
}
