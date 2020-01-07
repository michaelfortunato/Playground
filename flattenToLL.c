#include <stdlib.h>
#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
struct llist {
    int val;
    struct llist* next;
};
typedef struct llist llist;

llist *flattenToLL(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    llist *node1 = (llist*)malloc(sizeof(llist));
    node1->val = root->val;
    llist *node2 = flattenToLL(root->left);
    llist *node3 = flattenToLL(root->right);
    node1->next = node2;
    llist *head = node2;

    if (node2 == NULL && node3 != NULL) {
        node1->next = node3;
        return node1;
    } else if(node2 == NULL && node3 == NULL) {
        return node1;
    } else {
        llist *iter = node2;
        while (iter->next != NULL) {
            iter = iter->next;
        }

        iter->next = node3;
        return node1;
    }   
}

int main(int argc, char *argv[]) {
/*    1
     / \
    2   5
   / \   \
  3   4   6
*/
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root -> val = 1; 
    root -> left = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    
    root->left->val = 2;
    root->left->left = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->left->left->val = 3;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->left->right->val = 4;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    
    root->right  = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->right->val = 5;
    root->right->left = NULL;
    root->right->right = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->right->right->val = 6;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    llist *head = flattenToLL(root);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    return 0;
}