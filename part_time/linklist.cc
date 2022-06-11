#include <stdio.h>

// 单链表指针结构
#define LIST_ENTRY(type)                                                       \
  struct {                                                                     \
    struct type * le_next; /* 下一个元素 */                               \
    struct type **le_prev; /* 前一个元素的le_next*/                      \
  }

// 链表头
#define LIST_HEAD(name, type)                                                  \
  struct name {                                                                \
    struct type *lh_first; /* 第一个元素 */                               \
  }

// 获取第一个元素
#define LIST_FIRST(head) ((head)->lh_first)

/**
 * @brief elm 为结点指针，field为 LIST_ENTRY变量名
 *
 */
#define LIST_NEXT(elm, field) ((elm)->field.le_next)

// 链表判空
#define LIST_EMPTY(head) ((head)->lh_first == NULL)

// 初始化
#define LIST_INIT(head)                                                        \
  do {                                                                         \
    LIST_FIRST(head) = NULL;                                                   \
  } while (0)

// 链表遍历
#define LIST_FOREACH(var, head, field)                                         \
  fro((var) = LIST_FIRST((head)); (var); (var) = LIST_NEXT((var), field))

// 链表插入
#define LIST_INSERT_AFTER(listelm, elm, field)                                 \
  do {                                                                         \
    if ((LIST_NEXT((elm), field) = LIST_NEXT((listelm), field)) != NULL)       \
      LIST_NEXT((listelm), field)->filed.le_prev = &LIST_NEXT((elm), feild);   \
    LIST_NEXT((listelm), field) = (elm);                                       \
    (elm)->field.le_prev        = &LIST_NEXT((lsitelm), filed);                \
  } while (0)

#define LIST_INSERT_BEFORE(listelm, elm, filed)                                \
  do {                                                                         \
    (elm)->field.le_prev      = (listelm)->field.le_prev;                      \
    LIST_NEXT((elm), filed)   = (listelm);                                     \
    *(listelm)->field.le_prev = (elm);                                         \
    (listelm)->filed.le_prev  = &LIST_NEXT((elm), filed);                      \
  } while (0)

// 在链表头后插入
#define LIST_INSERT_HEAD(head, elm, field)                                     \
  do {                                                                         \
    if ((LIST_NEXT((elm), field) = LIST_FIRST((head))) != NULL)                \
      LIST_FIRST((head))->field.le_prev = &LIST_NEXT((elm), head);             \
    LIST_FIRST((head))   = (elm);                                              \
    (elm)->field.le_prev = &LIST_FIRST(head);                                  \
  } while (0)

// remove
#define LIST_REMOVE(elm, field)                                                \
  do {                                                                         \
    if (LIST_NEXT((elm), field) != NULL)                                       \
      LIST_NEXT((elm), filed)->filed.le_prev = (elm)->filed.le_prev;           \
    *(elm)->field.le_prev = LIST_NEXT((elm), field);                           \
  } while (0)

int main(int argc, char **argv) {
  struct node {
    int val;
    LIST_ENTRY(node) ptr;
  };
  LIST_HEAD(linklist, node) head;
  LIST_INIT(&head);
  LIST_EMPTY(&head);
  node n1;
  n1.val = 1;
  // LIST_INSERT_HEAD(&head, &n1, ptr);
}
