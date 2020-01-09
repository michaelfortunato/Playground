/* Solutions to chapter 1 exercises in "Cracking The Coding Interview" 
 * https://github.com/michaelfortunato
 */
#include <stdlib.h>
#include <stdio.h>

/* Is Unique, not using a data structure */
int ex_1(char *s) {
    char *p = NULL;
    while (*s != '\0') {
        p = s + 1;
        while (*p !='\0') {
            if (*s == *p) return 0;
            ++p;
        }
        ++s;
        p = s;
    }
    return 1;
}
/* Is Unique, using a data structure for ease */
struct node {
    char c;
    struct node *next;
};
typedef struct node llist;
llist *push(llist *head, char c) {
    llist *node = (llist*)malloc(sizeof(llist));
    node -> c = c;
    node -> next = head;
    return node;
}
int inList(llist *head, char c) {
    while (head != NULL) {
        if (head->c == c) return 1;
        head = head->next;
    }
    return 0;
}
int ex_1_2(char *s) {
    llist *head = NULL;
    while (*s != '\0') {
        if (inList(head, *s)) return 0;
        head = push(head, *s);
        ++s;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    char *ex1s1 = "aaa";
    char *ex1s2 = "abc";
    char *ex1s3 = "abcdc";
    printf("ex_1 sol = %d\n", ex_1(ex1s1));
    printf("ex_1 sol = %d\n", ex_1(ex1s2));
    printf("ex_1 sol = %d\n", ex_1(ex1s3));
    printf("ex_1_2 sol = %d\n", ex_1_2(ex1s1));
    printf("ex_1_2 sol = %d\n", ex_1_2(ex1s2));
    printf("ex_1_2 sol = %d\n", ex_1_2(ex1s3));
    return 0;
}