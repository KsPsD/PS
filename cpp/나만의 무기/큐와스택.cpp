#include<bits/stdc++.h>

using namespace std;

void enqueue(stack<int>& s1 ,int value) {
	s1.push(value);
}

int dequeue(stack<int>& s1, stack<int>& s2) {
	if (s1.empty() && s2.empty()) {
		printf("Queue is empty");
		return -1;
	}
	if (s2.empty()) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}

	int front = s2.top();
	s2.pop();
	return front;
}

int n, num;
string s;
queue<int> q1;
queue<int> q2;
void push(int data){
	if(q1.empty()){
		q1.push(data);
	}else{
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		q1.push(data);
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
	}
} 
bool isEmpty(){
	if(q1.empty()){
        return true;
    }
 
    return false;
}
int pop(){
	if(isEmpty()){
		cout<<"queue is empty"<<endl;
	}
	int num = q1.front();
	q1.pop();
	
	return num;
}




int main() {
	stack<int> s1, s2;
	
	enqueue(s1, 1);
	enqueue(s1, 2);
	enqueue(s1,  4);
	enqueue(s1,  8);

	for (int i = 0; i < 4; i++) {
		int value = dequeue(s1, s2);
		printf("%d ", value);
	}
    // Ãâ·Â: 1 2 4 8
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        if(s=="pop"){
            cout<<pop()<<"\n";
        }else if(s=="push"){
            cin>>num;
            push(num);
        }else if(s=="empty"){
            cout<<isEmpty()<<"\n";
        }
    }
    
}

