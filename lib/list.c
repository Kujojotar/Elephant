#include "list.h"
#include "interrupt.h"
#include "thread.h"

void list_init(struct list* list){
    list->head.prev = NULL;
    list->head.next = &list->tail;
    list->tail.prev = &list->head;
    list->tail.next = NULL;
}

void list_insert_before(struct list_elem* before, struct list_elem* elem){
    enum intr_status old_status = intr_disable();

    before->prev->next = elem;
    elem->prev = before->prev;
    elem->next = before;
    before->prev = elem;
 
    intr_set_status(old_status);
}

void list_push(struct list* plist, struct list_elem* elem){
    list_insert_before(plist->head.next, elem);
}

void list_append(struct list* plist,struct list_elem* elem){
    list_insert_before(&plist->tail, elem);
}

void list_remove(struct list_elem* pelem){
    enum intr_status old_status = intr_disable();
    
    pelem->prev->next = pelem->next;
    pelem->next->prev = pelem->prev;

    intr_set_status(old_status);
}

struct list_elem* list_pop(struct list* plist){
    struct list_elem* elem = plist->head.next;
    list_remove(elem);
    return elem;
}

bool list_empty(struct list* plist){
    return (plist->head.next == &plist->tail ? true : false);
}

uint32_t list_len(struct list* plist){
    struct list_elem* elem = plist->head.next;
    uint32_t length = 0;
    while(elem!=&plist->tail){
        length++;
        elem = elem->next;
    }
    return length;
}

/* 把列表plist中的每个元素elem和arg传给回调函数func,
 *  * arg给func用来判断elem是否符合条件.
 *   * 本函数的功能是遍历列表内所有元素,逐个判断是否有符合条件的元素。
 *    * 找到符合条件的元素返回元素指针,否则返回NULL. */
struct list_elem* list_traversal(struct list* plist, function func, int arg) {
   struct list_elem* elem = plist->head.next;
/* 如果队列为空,就必然没有符合条件的结点,故直接返回NULL */
   if (list_empty(plist)) { 
      return NULL;
   }

   while (elem != &plist->tail) {
      if (func(elem, arg)) {		  // func返回ture则认为该元素在回调函数中符合条件,命中,故停止继续遍历
	 return elem;
      }					  // 若回调函数func返回true,则继续遍历
      elem = elem->next;	       
   }
   return NULL;
}

bool elem_find(struct list* plist, struct list_elem* obj_elem){
    struct list_elem* elem = plist->head.next;
    while(elem != &plist->tail){
        if(elem==obj_elem){
            return true;
        }
        elem = elem->next;
    }
    return false;
}

