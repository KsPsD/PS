#include<bits/stdc++.h>

using namespace std;

//int answer, attr_size;
//vector<bool> select;
//vector<int> v;
//vector<<vector<int>> candi;
//vectro<vector<string>> Relation;
//
//
//void m_attr(){
//	select.resize(Relation[0].size(), false);
//	attr_size =Relation[0].size();
//}
//
//bool check_uni(){
//	vector<string> tmp;
//	
//	for(int i=0;i<Relation.size(); i++){
//		string res ="";
//		for(int k=0; k<v.size(); k++){
//			int idx =v[k];
//			res+= Relation[i][idx];
//			
//		}
//		if(find(tmp.begin(), tmp.end(), res) !=tmp.end()) return false;
//		else tmp.push_back(res);
//	}
//	
//	return true;
//}
//
//
//bool check_mini(){
//	if(v.size()==1) return true;
//	
//	for(int i=0 ; i<candi.size(); i++){
//		bool flag=false;
//		for(int j=0; j<candi[i].size(); j++){
//			int key =candi[i][j];
//			if(find(v.begin(), v.end(),key) == v.end()){
//				flag=true;
//				break;
//			}
//		}
//		if(flag==false) return false;
//	}
//	
//	return true;
//}
//
//bool check(){
//	if(check_uni() && check_mini){
//		candi.push_back(v);
//		return true;
//	}
//	return false;
//}
//
//void dfs(int idx, int cnt, int total_cnt){
//	if(cnt==total_cnt){
//		if(check() == true) answer++;
//		return;
//	}
//		
//	for(int i=idx; i<attr_size; i++){
//		if(select[i] ==true) continue;
//		select[i] =true;
//		v.push_back(i);
//		dfs(i,cnt+1,total_cnt);
//		v.pop_back();
//		select[i] =  false;
//	}
//}
//
//void m_combi(){
//	for(int i=1; i<=Relation[0].size(); i++){
//		dfs(0,0,i);
//	}
//}
//
//int solution(vector<vector<string>> relation){
//	Relation = relation;
//	m_attr();
//	m_combi();
//	
//	return answer;
//} 


using namespace std;

// �ּҼ� Ȯ��
bool possi(vector<int> vec,int now){
    for(int i = 0; i < vec.size(); i++)
        // ans�� �ִ� ������ �̹��� ���� �����̶� ���� ������ Ȯ��
        if((vec[i] & now) == vec[i])
            return false;

    return true;
}

int solution(vector<vector<string>> relation) {
    int rowSize = (int)relation.size(); 
    int colSize = (int)relation[0].size();
    vector<int> ans;

    // ���� ����� ��
    /*
     1(0001) - �й�
     2(0010) - �̸�
     3(0011) - �̸�, �й�
     4(0100) - ����
     5(0101) - �й�, ����
     6(0110) - �̸�, ����
     7(0111) - �й�, �̸�, ����
     8(1000) - �г�
     9(1001) - �й�, �г�
     10(1010) - �̸�, �г�
     11(1011) - �й�, �̸�, �г�
     12(1100) - �̸�, �й�
     13(1101) - �й�, ����, �г�
     14(1110) - �̸�, ����, �г�
     15(1111) - �й�, �̸�, ����, �г�
     */
    for(int i = 1; i < (1<<colSize); i++){
        set<string> s; //

        for(int j = 0; j < rowSize; j++){
            string now = "";

            for(int k = 0; k < colSize; k++){
                  // ���õ� �÷��� ��ġ�Ѵٸ�
                if(i & (1<<k))
                    now += relation[j][k];
            }
            s.insert(now);
        }

        // s.size() == rowSize => �ߺ�üũ
        if(s.size() == rowSize && possi(ans,i))
            ans.push_back(i);
    }

    return (int)ans.size();
}
