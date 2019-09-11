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
            case 1:printf("%d\n",tree_count_leaves(&my_tree));
            		break;
            case 2:
                /* Print the number of internal nodes */
                printf("%d\n", tree_count_internal_nodes(&my_tree));                
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

int leaves(node* t)
{
    int p;
    if(t==NULL) return 0;
    else if(!t->left && !t->right) return 1;
    else{ 
        p=(leaves(t->left)+leaves(t->right));
        return p;}
}
int tree_count_leaves(tree* tree)
{
    node *temp = tree->root;
    int x = leaves(temp);
    return x;
}


int count(node* t)
{
    if(t==NULL)
        return 0;
    int y = count(t->left);
    int z = count(t->right);
    int a = y+z+1;
    return a;
}
int tree_count_nodes(tree* tree)
{
    node *temp = tree->root;
    int y = count(temp);
    return y;
}
int tree_count_internal_nodes(tree* tree)
{
    node *temp = tree->root;
    int z =(count(temp))-(tree_count_leaves(tree));
    return z;
}
void tree_destruct(tree *tree)
{
}

