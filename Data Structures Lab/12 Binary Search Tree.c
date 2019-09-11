#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

typedef struct tree {
    node* root;
} tree;


void tree_initialize(tree* tree);
void tree_insert(tree* tree, int data);

/* Print elements on successive lines */
void tree_print_inorder(tree* tree);
void tree_print_preorder(tree* tree);
void tree_print_postorder(tree* tree);

/* Advisory: While some guarded discernment could perhaps lead you to 
 * more efficient implementations, you are requested to provide suitable recursive
 * solutions for the following function declarations. 
 */

int tree_count_leaves(tree* tree);


node* tree_max(tree* tree);
node* tree_min(tree* tree);
int tree_count_nodes(tree* tree);
int tree_count_internal_nodes(tree* tree);
void tree_destruct(tree *tree);

int main() {
    int choice, loop = 1;
    tree my_tree;
    tree_initialize(&my_tree);
    while(loop) {
        scanf("%d", &choice);
        switch(choice) {
            int number_of_elements, element, index;
            node *min_node, *max_node;
            case 0:
                /* Insert elements */ 
                scanf("%d", &element);
                tree_insert(&my_tree, element);
                break;
            case 1:
                /* Print elements in the inorder fashion */
                tree_print_inorder(&my_tree);

                //printf("\n");
                break;
            case 2:
                /* Print elements in the preorder fashion */
                tree_print_postorder(&my_tree);
                //printf("\n");
                break;
            case 3: 
                tree_destruct(&my_tree);
                loop = 0;
            
        }
    }
    return 0;
}


void tree_initialize(tree* tree)
{
    tree->root = (node*)malloc(sizeof(node));
    tree->root = NULL;
}

void tree_insert(tree* tree, int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data=data;
    temp->left=temp->right=NULL;
    node *cur = (node*)malloc(sizeof(node));
    node *prev = (node*)malloc(sizeof(node));
    if(tree->root==NULL)
        tree->root = temp;
    else 
    {
        cur = tree->root;
        while(cur!=NULL)
        {
            prev=cur;
            if(data>(cur->data))
                cur=cur->right;
            else if(data<(cur->data))
                cur=cur->left;
            else
                return;    
        }
        if(data>(prev->data))
            prev->right = temp;
        else if(data<(prev->data))
            prev->left = temp;
        else
            return;
    }
}

/* Print elements on successive lines */
void inorder(node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%d",t->data);
        inorder(t->right);
    }
}

void tree_print_inorder(tree* tree)
{
    
    node *temp = tree->root;
    inorder(temp);
}


void postorder(node *t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d",t->data);
    }
}

void tree_print_postorder(tree* tree)
{
    node *temp = tree->root;
    postorder(temp);    
}


void tree_destruct(tree *tree)
{
}

