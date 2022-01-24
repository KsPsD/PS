#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=a;i<b;i++)
#define r_rep(i,a,b) for(int i=a;i>b;i--)
using namespace std;
const int MAXCHAR = 96;
//조회가 빠르다 ~ 
//int toNumber(const char c){ return c - 32;}
//struct TrieNode{
//    int count;
//    bool terminal;
//    struct TrieNode* children[MAXCHAR];
//    TrieNode() : terminal(false), count(1){
//        memset(children, 0, sizeof(children));
//    }
//    ~TrieNode(){
//        rep(i, 0, MAXCHAR) if(children[i])
//            delete children[i];
//    }
//    void insert(const char* key){
//        if((*key) == 0) terminal = true;
//        else{
//            int next = toNumber(*key);
//            if(children[next] == NULL){
//                children[next] = new struct TrieNode();
//            }
//            children[next]->insert(key+1);
//        }
//    }
//    TrieNode* find(const char* key){
//        if(*key == 0) return this;
//        int next = toNumber(*key);
//        if(children[next] == NULL) return NULL;
//        return children[next]->find(key+1);
//    }
//};
int toNumber(const char c){ return c - 32;}

struct TrieNode{
	int cnt;
	bool end;
	struct TrieNode* child[MAXCHAR];
	TrieNode(): end(false), cnt(1){
		memset(child, 0, sizeof(child));
	}
	 ~TrieNode(){
        for(int i =0 ;i<MAXCHAR ; i++) 
			if(child[i])
           	 delete child[i];
    }
    void insert(const char * key){
    	if((*key) =='\0') end =true;
    	else{
    		int next = toNumber(*key);
    		if(child[next] ==NULL){
    			child[next] = new struct TrieNode();
			}
			child[next] -> insert(key+1);
		}
	}
	TrieNode * find(const char *key){
		if(*key=='\0') return this;
		int next = toNumber(*key);
		if(child[next] == NULL) return NULL;
		return child[next] -> find(key+1);
	}
};


int main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 0;
    char name[32];

    struct TrieNode root;
    struct TrieNode* where;
    vector<string> input;

    while(!cin.getline(name, 31).eof()){
        //cin.getline(name, 31);
        cnt++;
        if((where = root.find(name)) == NULL){
            root.insert(name);
            input.push_back(name);
        }else where->cnt++;
    }
    cout<<fixed;
    cout.precision(4);

    sort(input.begin(), input.end());
    rep(i, 0, input.size()){
        cout << input[i] << " "<< (double)(where = root.find(input[i].c_str()))->cnt/cnt * 100 << endl;
    }

    return 0;
}
