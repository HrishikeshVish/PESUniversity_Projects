#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node node;

struct tree{
	struct node *root;
};


typedef struct tree tree;

void insert(tree*, int);
int sum1(node*, int);

int main(){
	
	tree *tre = (tree*)malloc(sizeof(tree));
	tre->root = NULL;
	insert(tre, 4);
	insert(tre, 2);
	insert(tre, 3);
	insert(tre, 1);
	insert(tre, 6);
	insert(tre, 5);
	insert(tre, 7);
	printf("%d", sum1(tre->root, -7));
	
}

void insert(tree * tree, int data){
	node *t = (node *)malloc(sizeof(node));
	t->data = data;
	t->left =NULL;
	t->right = NULL;
	if(tree->root == NULL){
		tree->root = t;
		return;
	}
	
	node *t2 = tree->root;
	while(t2!=NULL){
		if(t2->data > data){
			if(t2->left == NULL){
				t2->left = t;
				return;
			}
			t2 = t2->left;
		}
		else{
			if(t2->right == NULL){
				t2->right = t;
				return;
			}
			t2 = t2->right;
		}
	}
	
}

int sum1(node *root, int sum){
	if(root->left == NULL && root->right==NULL){
		if(root->data == sum){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	if(root->left==NULL){
		root->right->data  = root->right->data + root->data;
		return 1*sum1(root->right, sum);
	}
	else if(root->right==NULL){
		root->left->data = root->left->data + root->data;
		return 1*sum1(root->left, sum);
	}
	else{
	
	root->left->data = root->left->data + root->data;	
	root->right->data  = root->right->data + root->data;
	
	return ( 1*sum1(root->left,sum) + 1*sum1(root->right,sum))>=1?1:0;
		
	}
	

}
