#include<bits/stdc++.h>

using namespace std;

struct bucket* hashTable = NULL; 
int BUCKET_SIZE = 10; // ������ �� ����

// ��� ����ü ����
struct node {
    int key; // �ؽ� �Լ��� ���� Ű
    int value; // key �� ������ �ִ� ������
    struct node* next; // ���� ��带 ����Ű�� ������
    struct node* previous; // ���� ��带 ����Ű�� ������
};
// ���� ����ü ����
struct bucket{
    struct node* head; // ���� ���� �տ� �ִ� ����� ������
    int count; // ���Ͽ� ����ִ� ����� ����
};
// �ؽ����̺� ���Ե� �� ���� ��带 �������ִ� �Լ�(�ʱ�ȭ)
struct node* createNode(int key, int value){
    struct node* newNode;
    // �޸� �Ҵ�
    newNode = (struct node *)malloc(sizeof(struct node));
    // ����ڰ� ������ ���� ����
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL; // ������ ���� next�� NULL�� �ʱ�ȭ
    newNode->previous = NULL; // ������ ���� previous�� NULL�� �ʱ�ȭ

    return newNode;
}
// �ؽ��Լ� �����. ���⼭�� �ܼ��� key�� ���� ���̷� ���� �������� �Լ��� ����.
int hashFunction(int key){
    return key%BUCKET_SIZE;
}
// ���� Ű �߰��ϴ� �Լ�
void add(int key, int value){
    // ��� ���Ͽ� �߰����� �ε����� ���
    int hashIndex = hashFunction(key);
    // ���� ��� ����
    struct node* newNode = createNode(key, value);
    // ����� �ε����� ���Ͽ� �ƹ� ��嵵 ���� ���
    if (hashTable[hashIndex].count == 0){
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newNode; // head�� ��ü
    }
    // ���Ͽ� �ٸ� ��尡 ���� ��� ��ĭ�� �а� ���� ��尡 �ȴ�(�����δ� �����͸� �ٲ���)
    else{
        hashTable[hashIndex].head->previous = newNode; // �߰�
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
    }
}
// Ű�� �������ִ� �Լ�
void remove_key(int key){
    int hashIndex = hashFunction(key);
    // ������ �Ǿ����� Ȯ���ϴ� flag ����
    int flag = 0;
    // Ű�� ã���� iterator ����
    struct node* node;
    // struct node* before; // �ʿ� ����!
    // ������ head���� ����
    node = hashTable[hashIndex].head;
    // ������ ��ȸ�ϸ鼭 key�� ã�´�.
    while (node != NULL) // NULL �� ���ö����� ��ȸ
    {
        if (node->key == key){
            // ������ �ٲ��ֱ� ��尡 1 . ����� ��� 2 . ��尡 �ƴѰ��
            if (node == hashTable[hashIndex].head){
                node->next->previous = NULL; // �߰� ���� ������ ��尡 �Ǿ����Ƿ� previous�� ����
                hashTable[hashIndex].head = node->next; // ���� ��尡 ���� ���
            }
            else{
                node->previous->next = node->next; // �� �� ����� ���� ���� �� �� ���
                node->next->previous = node->previous; // �� �� ����� ���� ���� �� �� ���
            }
            // ������ �۾� ����
            hashTable[hashIndex].count--;
            free(node);
            flag = 1;
        }
        node = node->next;
    }
    // flag�� ���� ���� ��� �ٸ��� ����
    if (flag == 1){ // ������ �Ǿ��ٸ�
        printf("\n [ %d ] ��/�� �����Ǿ����ϴ�. \n", key);
    }
    else{ // Ű�� ��� ������ �ȵ� ���
        printf("\n [ %d ] ��/�� �������� �ʾ� �������� ���߽��ϴ�.\n", key);
    }
}
// Ű�� �ָ� value�� �˷��ִ� �Լ�
void search(int key){
    int hashIndex = hashFunction(key);
    struct node* node = hashTable[hashIndex].head;
    int flag = 0;
    while (node != NULL)
    {
        if (node->key == key){
            flag = 1;
            break;
        }
        node = node->next;
    }
    if (flag == 1){ // Ű�� ã�Ҵٸ�
        printf("\n Ű�� [ %d ], ���� [ %d ] �Դϴ�. \n", node->key, node->value);
    }
    else{
        printf("\n �������� ���� Ű�� ã�� �� �����ϴ�. \n");
    }
}
// �ؽ����̺� ��ü�� ������ִ� �Լ�
void display(){
    // �ݺ��� ����
    struct node* iterator;
    printf("\n========= display start ========= \n");
    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashTable[i].head;
        printf("Bucket[%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key : %d, val : %d)  <-> ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n========= display complete ========= \n");
}

int main(){
    // �ؽ����̺� �޸� �Ҵ�
    hashTable = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
    
    // 15 ���� �� �߰�
    for (int i=0; i < 16; i++){
        add(i, 10*i);
    }
    // � �� �߰�
    add(21, 210);
    add(31, 310);
    add(41, 410);

    display();

    remove_key(31);
    remove_key(11);
    remove_key(51);

    display();

    search(11);
    search(1);
}
