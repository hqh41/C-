//
// Created by houqinghua on 2018/4/6.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H
typedef struct node{
    int data;
    struct node *next;
}NODE;

class LinkList{
private:
    NODE *head;
public:
    LinkList(){head = nullptr;}
    ~LinkList();
    bool clearSqList();
    bool isEmpty(){
        return head = nullptr;
    }
    int Length();
    bool GetElem(int i, int *e);
    int LocateElem(int e);
    bool priorElem(int cur_e, int *pre_e);
    bool NextElem(int cur_e, int *next_e);
    bool Insert(int i, int e);
    bool Delete(int i, int *e);
    NODE *Reverse();
};

#endif //LINKLIST_LINKLIST_H
