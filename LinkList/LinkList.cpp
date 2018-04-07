#include "LinkList.h"
#include <iostream>
using namespace std;

LinkList::~LinkList(){
    NODE *p = head;
    while(p){
        p = head;
        head = head->next;
        delete(p);
    }
}

bool LinkList::clearSqList(){
     NODE *p = head;
     while(head){
         p = head;
         head = head->next;
         delete(p);
     }
}

int LinkList::Length(){
    NODE *p = head;
    int len = 0;
    while(p != nullptr){
        len++;
        p = p->next;
    }
    return len;
}

bool LinkList::GetElem(int i, int *e){
     NODE *p = head;
     int j = 0;
     while(p && j < i){
         p = p->next;
         j++;
     }
    if(p == nullptr)
        return false;
    *e = p->data;
    return true;
}

int LinkList::LocateElem(int e){
    int i = 0;
    NODE *p = head;
    while(p != nullptr){
        if(p->data == e)
            return i;
        else
            p = p->next;
        i++;
    }
    std::cout << "表中不存在指定的元素" << std::endl;
    return -1;
}

//取上一个元素
bool LinkList::priorElem(int cur_e, int *pre_e){
     NODE *p = head;
    if(p->data == cur_e)
        return false;//是头节点，不存在上一个元素
    while(p->next != nullptr){
        if(p->next->data == cur_e){
            *pre_e = p->data;
            return true;
        }
        else
            p = p->next;
    }
    return false;//遍历完不存在或者只有一个头节点
}

//取下一个元素
bool LinkList::NextElem(int cur_e, int *next_e){
    NODE *p = head;
    if(head == nullptr || head->next == nullptr)
        return false;
    while(p->next != nullptr){
        if(p->data == cur_e){
            *next_e = p->next->data;
            return true;
        }
        else
            p = p->next;
    }
    return false;
}

//在指定下标插入元素e
bool LinkList::Insert(int i, int e){
     NODE *p = head;
     NODE *s;
    int j = 0;
    if(i == 0){
        s = (NODE *)new NODE[1];
        s->data = e;
        s->next = p;
        head = s;
        return true;
    }
    if(p == nullptr)
        return false;
    while(p && j < i-1){
        p = p->next;
        j++;
    }
    s = (NODE *)new NODE[1];
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//删除指定下标的元素，并把删除的值赋给*e
bool LinkList::Delete(int i, int *e){
    NODE *p = head;
    NODE *s;
    if(p == nullptr)
        return false;
    int j = 0;
    if(i == 0){
        head = head->next;
        *e = p->data;
        delete p;
        p = nullptr;
        return true;
    }
    while(p && j < i-1){
        p = p->next;
        j++;
    }
    if(p == nullptr)
        return false;
    s = p->next;
    p->next = p->next->next;
    *e = s->data;
    delete s;
    s = nullptr;
    return true;
}

//反转链表
NODE *LinkList::Reverse(){
    if(head == nullptr || head->next == nullptr)
        return head;
    NODE *p = head;
    NODE *q = head->next;
    NODE *r;
    head->next = nullptr;
    while(q){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
    return head;
}