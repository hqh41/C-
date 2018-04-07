#include "LinkList.h"
#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int *p = &a;
    LinkList li;
    li.Insert(0, 5);
    li.Insert(1, 4);
    li.Insert(2, 12);
    li.Insert(3, 5);
    li.Insert(3, 6);
    li.Insert(1, 7);
    li.Delete(4, p);
    cout << "debug" << endl;
    cout << "链表长度" << li.Length() << endl;
    cout << "各个元素的值是:";
    for(int i = 0; i < li.Length(); i++){
        if(li.GetElem(i, p))
            cout << *p << "->";
    }
    cout << endl;
    cout << "反转后各个元素的值是:";
    NODE *re_li = li.Reverse();
    while(re_li){
        cout << re_li->data << "->";
        re_li = re_li->next;
    }
    cout << endl;
}