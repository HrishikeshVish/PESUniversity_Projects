
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define DEFAULT_ORDER 4

#define MIN_ORDER 3
#define MAX_ORDER 20
#define load_limit 3

#define BUFFER_SIZE 256

typedef struct record {
	int value;
} record;


typedef struct node {
	void ** pointers;
	int * keys;
	struct node * parent;
	bool is_leaf;
	int num_keys;
	int mylevel;
	struct node * next; 
} node;

typedef struct dumppackage{
int parentlevel;
int mylevel;
struct node *n;


}dpack;
int order = DEFAULT_ORDER;


node * queue = NULL;
int levelcount = 0;

bool verbose_output = false;

int cut(int length);
int get_left_index(node * parent, node * left);
int get_neighbor_index(node * n);
int height(node * const root);
int path_to_root(node * const root, node * child);

void enqueue(node * new_node);
//void print_leaves(node * const root);
//void print_tree(node * const root);
void find_and_print(node * const root, int key, bool verbose);



node * adjust_root(node * root);
node * coalesce_nodes(node * root, node * n, node * neighbor,int neighbor_index, int k_prime);
node * delete_entry(node * root, node * n, int key, void * pointer);
node * delete(node * root, int key);
node * dequeue(void);
node * find_leaf(node * const root, int key, bool verbose);

node * insert(node * root, int key, int value);
node * insert_into_leaf(node * leaf, int key, record * pointer);
node * insert_into_leaf_after_splitting(node * root, node * leaf, int key,record * pointer);
node * insert_into_node(node * root, node * parent, int left_index, int key, node * right);
node * insert_into_node_after_splitting(node * root, node * parent,int left_index,int key, node * right);
node * insert_into_parent(node * root, node * left, int key, node * right);
node * insert_into_new_root(node * left, int key, node * right);

node * make_node(void);
node * make_leaf(void);

node * redistribute_nodes(node * root, node * n, node * neighbor,int neighbor_index,int k_prime_index, int k_prime);
node * start_new_tree(int key, record * pointer);




record * make_record(int value);
record * find(node * root, int key, bool verbose, node ** leaf_out);
void loadnode(node*root, int key);
node* load(node* par,node* me, char* name, int level){
	if(level<load_limit){
	
	node* root = (node*)malloc(sizeof(node));
	char point[20], key[20],parent[20], isleaf[20], numkeys[20], mylevel[20], next[20];
	int lev = root->mylevel;
	strcpy(point, name);
	strcpy(key, name);
	strcpy(parent, name);
	strcpy(isleaf, name);
	strcpy(numkeys, name);
	strcpy(mylevel, name);
	strcpy(next, name);
	
	int i;
	strcat(point, ".point");
	strcat(key, ".key");
	strcat(parent, ".par");
	strcat(isleaf, ".isl");
	strcat(numkeys, ".nk");
	strcat(mylevel, ".ml");
	strcat(next, ".nx");
	
	FILE*fp = fopen(numkeys,"r");
	int temp;
	fscanf(fp, "%d", &temp);
	
	root->num_keys= temp;
	fclose(fp);
	
	if(level == 0){
		
	return me;
	}
	if(level == 0){
		root->parent = NULL;
	}
	
	fp = fopen(isleaf,"r");
	
	fscanf(fp, "%d", &temp);
	root->is_leaf = temp;
	fclose(fp);
	fp = fopen(mylevel,"r");
	fscanf(fp, "%d", &temp);
	root->mylevel = temp;
	fclose(fp);
	fp = fopen(key, "r");
	for(i = 0; i<root->num_keys; i++){
		
		fscanf(fp, "%d", &temp);
		root->keys[i] = temp;
}
	fclose(fp);

	fp = fopen(point, "r");
	char n2[20];
	node *t;
	
	int t2;
	printf("Before scanf\n");
	fscanf(fp, "%d", &t2);
	printf("t2 = %d\n", t2);
	
	if(fp!=NULL){
		for(i = 0; i<root->num_keys; i++){
			
			fscanf(fp,"%d", &t2);
			
			printf("After scan\n");
			sprintf(n2, "%d",t2);
			printf("n2 = %s\n", n2);
			t = load(root, (node*)root->pointers[i],n2, level+1);
			root->pointers[i] = (void*)t;
			
		}
	}
	fclose(fp);
	
	return root;
}
else{
	return NULL;
}

}
void loadfromfile(node * p,int value, int index){
	char name[100];
	sprintf(name, "%d", value);
	node* root = (node*)malloc(sizeof(node));
	char point[20], key[20],parent[20], isleaf[20], numkeys[20], mylevel[20], next[20];
	int lev = root->mylevel;
	strcpy(point, name);
	strcpy(key, name);
	strcpy(parent, name);
	strcpy(isleaf, name);
	strcpy(numkeys, name);
	strcpy(mylevel, name);
	strcpy(next, name);
	
	int i;
	strcat(point, ".point");
	strcat(key, ".key");
	strcat(parent, ".par");
	strcat(isleaf, ".isl");
	strcat(numkeys, ".nk");
	strcat(mylevel, ".ml");
	strcat(next, ".nx");
	
	FILE*fp = fopen(numkeys,"r");
	int temp;
	fscanf(fp, "%d", &temp);
	
	root->num_keys= temp;
	fclose(fp);
	

	
	fp = fopen(isleaf,"r");
	
	fscanf(fp, "%d", &temp);
	root->is_leaf = temp;
	fclose(fp);
	fp = fopen(mylevel,"r");
	fscanf(fp, "%d", &temp);
	root->mylevel = temp;
	fclose(fp);
	fp = fopen(key, "r");
	for(i = 0; i<root->num_keys; i++){
		
		fscanf(fp, "%d", &temp);
		root->keys[i] = temp;
}
	fclose(fp);

	fp = fopen(point, "r");
	char n2[20];
	node *t;
	
	int t2;
	printf("Before scanf\n");
	fscanf(fp, "%d", &t2);
	printf("t2 = %d\n", t2);
	
	if(fp!=NULL){
		for(i = 0; i<root->num_keys; i++){
			
			fscanf(fp,"%d", &t2);
			
			printf("After scan\n");
			sprintf(n2, "%d",t2);
			printf("n2 = %s\n", n2);
			t = loadnode(root, (node*)root->pointers[i],n2, root->mylevel+1);
			root->pointers[i] = (void*)t;
			
		}
	}
	fclose(fp);
	p->pointers[index] = (void*)root;
	
}
void loadnode(node*root, int key){
	
	int value;
	int n = root->num_keys;
	int i;
	for(i=0;i<n-1;i++){
		if(key<root->keys[i+1] && key>=root->keys[i] ){
			if(!root->is_leaf){
			
			loadnode((node*)root->pointers[i],key);
		}
		else{
			value = i+((((root->mylevel)%10)+1)*10);
			loadfromfile(root, value, i);
		}
		}
	}

}


void find_and_print(node * const root, int key, bool verbose) {
 node * leaf = NULL;
 record * r = find(root, key, verbose, NULL);
 if(r==NULL){
 	char c[20];
 	FILE *fp = fopen("key_file.txt", "r");
 	int n;
 	fscanf(fp,"%d", &n);
 	int keys[n];
 	int i;
 	for(i=0;i<n;i++){
 		fscanf(fp,"%d", &keys[i]);
 	}
 	for(i=0;i<n;i++){
 		if(key == keys[i]){
 			loadnode(root, key);
 			return;
		 }
	 }
 }
 char c[20];
 itoa(key, c, 10);
 strcat(c,".txt");
 FILE *fp = fopen(c, "r");
 char c2[100];
 fscanf(fp, "%s", c2);
 if (fp == NULL)
  printf("Record not found under key %d.\n", key);
 else
  printf("The value of the record under key %d is %s\n", key, c2);
}

void enqueue(node * new_node) {
	node * c;
	if (queue == NULL) {
		queue = new_node;
		queue->next = NULL;
	}
	else {
		c = queue;
		while(c->next != NULL) {
			c = c->next;
		}
		c->next = new_node;
		new_node->next = NULL;
	}
}


node * dequeue(void) {
	node * n = queue;
	queue = queue->next;
	n->next = NULL;
	return n;
}


void print_leaves(node * const root) {
	if (root == NULL) {
		printf("Empty tree.\n");
		return;
	}
	int i;
	node * c = root;
	while (!c->is_leaf)
		c = c->pointers[0];
	while (true) {
		for (i = 0; i < c->num_keys; i++) {
			if (verbose_output)
				printf("%p ", c->pointers[i]);
			printf("key - %d record - %d", c->keys[i],find(root, c->keys[i], false, NULL)->value );
		}
		if (verbose_output)
			printf("%p ", c->pointers[order - 1]);
		if (c->pointers[order - 1] != NULL) {
			printf(" | ");
			c = c->pointers[order - 1];
		}
		else
			break;
	}
	printf("\n");
}

int height(node * const root) {
	int h = 0;
	node * c = root;
	while (!c->is_leaf) {
		c = c->pointers[0];
		h++;
	}
	return h;
}

int path_to_root(node * const root, node * child) {
	int length = 0;
	node * c = child;
	while (c != root) {
		c = c->parent;
		length++;
	}
	return length;
}


void print_tree(node * const root) {

	node * n = NULL;
	int i = 0;
	int rank = 0;
	int new_rank = 0;

	if (root == NULL) {
		printf("Empty tree.\n");
		return;
	}

	
	queue = NULL;
	enqueue(root);
	while(queue != NULL) {
		n = dequeue();
		
		if (n->parent != NULL && n == n->parent->pointers[0]) {
			new_rank = path_to_root(root, n);
			if (new_rank != rank) {
				rank = new_rank;
				printf("\n");
			}
		}
		if (verbose_output) 
			printf("(%p)", n);
		for (i = 0; i < n->num_keys; i++) {
			if (verbose_output)
				printf("%p ", n->pointers[i]);
			printf("%d ", n->keys[i]);
		}
		if (!n->is_leaf)
			for (i = 0; i <= n->num_keys; i++)
				enqueue(n->pointers[i]);
		if (verbose_output) {
			if (n->is_leaf) 
				printf("%p ", n->pointers[order - 1]);
			else
				printf("%p ", n->pointers[n->num_keys]);
		}
		printf("| ");
	}
	printf("\n");
}
void dumpnode(node *root);
void dumptree(node * const root) {
	
	node * n = NULL;
	int i = 0;
	int rank = 0;
	int new_rank = 0;

	if (root == NULL) {
		return;
	}
	root->mylevel = 0;
	queue = NULL;
	enqueue(root);
	while(queue != NULL) {
		n = dequeue();
		
		dumpnode((node*)n);
		if (n->parent != NULL && n == n->parent->pointers[0]) {
			new_rank = path_to_root(root, n);
			if (new_rank != rank) {
				rank = new_rank;
	
			}
		}

		for (i = 0; i < n->num_keys; i++) {
			if (verbose_output)
				printf("%p ", n->pointers[i]);
			printf("%d ", n->keys[i]);
		}
		if (!n->is_leaf){
		
			for (i = 0; i <= n->num_keys; i++){
				
				((node*)n->pointers[i])->mylevel = i+((((n->mylevel)%10)+1)*10);
				enqueue(n->pointers[i]);
			}
			
		}
			
		if (verbose_output) {
			if (n->is_leaf) 
				printf("%p ", n->pointers[order - 1]);
			else
				printf("%p ", n->pointers[n->num_keys]);
		}
		printf("| ");
	}
	printf("\n");
}
void dumpnode(node *root){
	int i;
	char point[20], key[20],parent[20], isleaf[20], numkeys[20], mylevel[20], next[20];
	int lev = root->mylevel;
	char name[20];
	sprintf(point, "%d", lev);
	sprintf(key, "%d", lev);
	sprintf(parent, "%d", lev);
	sprintf(isleaf, "%d", lev);
	sprintf(numkeys, "%d", lev);
	sprintf(mylevel, "%d", lev);
	sprintf(next, "%d", lev);
	
	strcat(point, ".point");
	strcat(key, ".key");
	strcat(parent, ".par");
	strcat(isleaf, ".isl");
	strcat(numkeys, ".nk");
	strcat(mylevel, ".ml");
	strcat(next, ".nx");
	
	FILE *fp = fopen(isleaf, "w");
	fprintf(fp, "%d", root->is_leaf);
	fclose(fp);
	
	 fp = fopen(numkeys, "w");
	fprintf(fp, "%d", root->num_keys);
	fclose(fp);
	 fp = fopen(mylevel, "w");
	fprintf(fp, "%d", root->mylevel);
	fclose(fp);
	if(root->parent!=NULL){
	
	fp = fopen(parent, "w");
	fprintf(fp, "%d", root->parent->mylevel);
	fclose(fp);
	}
	
	fp = fopen(point, "w");

	
	
	for (i = 0; i < root->num_keys; i++){
				
			fprintf(fp, "%d ", i+ (((root->mylevel)%10)+1)*10);		
		}
		
	fclose(fp);
	fp = fopen(key, "w");
	for (i = 0; i <= root->num_keys; i++){
	fprintf(fp, "%d ", root->keys[i]);
	
	}
	fclose(fp);
	
}


node * find_leaf(node * const root, int key, bool verbose) {
	if (root == NULL) {
		if (verbose) 
			printf("Empty tree.\n");
		return root;
	}
	int i = 0;
	node * c = root;
	while (!c->is_leaf) {
		if (verbose) {
			printf("[");
			for (i = 0; i < c->num_keys - 1; i++)
				printf("%d ", c->keys[i]);
			printf("%d] ", c->keys[i]);
		}
		i = 0;
		while (i < c->num_keys) {
			if (key >= c->keys[i]) i++;
			else break;
		}
		if (verbose)
			printf("%d ->\n", i);
		c = (node *)c->pointers[i];
	}
	if (verbose) {
		printf("Leaf [");
		for (i = 0; i < c->num_keys - 1; i++)
			printf("%d ", c->keys[i]);
		printf("%d] ->\n", c->keys[i]);
	}
	return c;
}


record * find(node * root, int key, bool verbose, node ** leaf_out) {
    if (root == NULL) {
        if (leaf_out != NULL) {
            *leaf_out = NULL;
        }
        return NULL;
    }

	int i = 0;
    node * leaf = NULL;

	leaf = find_leaf(root, key, verbose);

	for (i = 0; i < leaf->num_keys; i++)
		if (leaf->keys[i] == key) break;
    if (leaf_out != NULL) {
        *leaf_out = leaf;
    }
	if (i == leaf->num_keys)
		return NULL;
	else
		return (record *)leaf->pointers[i];
}


int cut(int length) {
	if (length % 2 == 0)
		return length/2;
	else
		return length/2 + 1;
}



record * make_record(int value) {
	record * new_record = (record *)malloc(sizeof(record));
	
		new_record->value = value;
	
	return new_record;
}


node * make_node(void) {
	node * new_node;
	new_node = malloc(sizeof(node));
	if (new_node == NULL) {
		perror("Node creation.");
		exit(EXIT_FAILURE);
	}
	new_node->keys = malloc((order - 1) * sizeof(int));
	if (new_node->keys == NULL) {
		perror("New node keys array.");
		exit(EXIT_FAILURE);
	}
	new_node->pointers = malloc(order * sizeof(void *));
	if (new_node->pointers == NULL) {
		perror("New node pointers array.");
		exit(EXIT_FAILURE);
	}
	new_node->is_leaf = false;
	new_node->num_keys = 0;
	new_node->parent = NULL;
	new_node->next = NULL;
	return new_node;
}


node * make_leaf(void) {
	node * leaf = make_node();
	leaf->is_leaf = true;
	return leaf;
}


int get_left_index(node * parent, node * left) {

	int left_index = 0;
	while (left_index <= parent->num_keys && 
			parent->pointers[left_index] != left)
		left_index++;
	return left_index;
}


node * insert_into_leaf(node * leaf, int key, record * pointer) {

	int i, insertion_point;

	insertion_point = 0;
	while (insertion_point < leaf->num_keys && leaf->keys[insertion_point] < key)
		insertion_point++;

	for (i = leaf->num_keys; i > insertion_point; i--) {
		leaf->keys[i] = leaf->keys[i - 1];
		leaf->pointers[i] = leaf->pointers[i - 1];
	}
	leaf->keys[insertion_point] = key;
	leaf->pointers[insertion_point] = pointer;
	leaf->num_keys++;
	return leaf;
}


node * insert_into_leaf_after_splitting(node * root, node * leaf, int key, record * pointer) {

	node * new_leaf;
	int * temp_keys;
	void ** temp_pointers;
	int insertion_index, split, new_key, i, j;

	new_leaf = make_leaf();

	temp_keys = malloc(order * sizeof(int));
	if (temp_keys == NULL) {
		perror("Temporary keys array.");
		exit(EXIT_FAILURE);
	}

	temp_pointers = malloc(order * sizeof(void *));
	if (temp_pointers == NULL) {
		perror("Temporary pointers array.");
		exit(EXIT_FAILURE);
	}

	insertion_index = 0;
	while (insertion_index < order - 1 && leaf->keys[insertion_index] < key)
		insertion_index++;

	for (i = 0, j = 0; i < leaf->num_keys; i++, j++) {
		if (j == insertion_index) j++;
		temp_keys[j] = leaf->keys[i];
		temp_pointers[j] = leaf->pointers[i];
	}

	temp_keys[insertion_index] = key;
	temp_pointers[insertion_index] = pointer;

	leaf->num_keys = 0;

	split = cut(order - 1);

	for (i = 0; i < split; i++) {
		leaf->pointers[i] = temp_pointers[i];
		leaf->keys[i] = temp_keys[i];
		leaf->num_keys++;
	}

	for (i = split, j = 0; i < order; i++, j++) {
		new_leaf->pointers[j] = temp_pointers[i];
		new_leaf->keys[j] = temp_keys[i];
		new_leaf->num_keys++;
	}

	free(temp_pointers);
	free(temp_keys);

	new_leaf->pointers[order - 1] = leaf->pointers[order - 1];
	leaf->pointers[order - 1] = new_leaf;

	for (i = leaf->num_keys; i < order - 1; i++)
		leaf->pointers[i] = NULL;
	for (i = new_leaf->num_keys; i < order - 1; i++)
		new_leaf->pointers[i] = NULL;

	new_leaf->parent = leaf->parent;
	new_key = new_leaf->keys[0];

	return insert_into_parent(root, leaf, new_key, new_leaf);
}



node * insert_into_node(node * root, node * n, 
		int left_index, int key, node * right) {
	int i;

	for (i = n->num_keys; i > left_index; i--) {
		n->pointers[i + 1] = n->pointers[i];
		n->keys[i] = n->keys[i - 1];
	}
	n->pointers[left_index + 1] = right;
	n->keys[left_index] = key;
	n->num_keys++;
	return root;
}



node * insert_into_node_after_splitting(node * root, node * old_node, int left_index, int key, node * right) {

	int i, j, split, k_prime;
	node * new_node, * child;
	int * temp_keys;
	node ** temp_pointers;


	temp_pointers = malloc((order + 1) * sizeof(node *));

	temp_keys = malloc(order * sizeof(int));


	for (i = 0, j = 0; i < old_node->num_keys + 1; i++, j++) {
		if (j == left_index + 1) j++;
		temp_pointers[j] = old_node->pointers[i];
	}

	for (i = 0, j = 0; i < old_node->num_keys; i++, j++) {
		if (j == left_index) j++;
		temp_keys[j] = old_node->keys[i];
	}

	temp_pointers[left_index + 1] = right;
	temp_keys[left_index] = key;

	split = cut(order);
	new_node = make_node();
	old_node->num_keys = 0;
	
	for (i = 0; i < split - 1; i++) {
		old_node->pointers[i] = temp_pointers[i];
		old_node->keys[i] = temp_keys[i];
		old_node->num_keys++;
	}
	
	old_node->pointers[i] = temp_pointers[i];
	k_prime = temp_keys[split - 1];
	
	for (++i, j = 0; i < order; i++, j++) {
		new_node->pointers[j] = temp_pointers[i];
		new_node->keys[j] = temp_keys[i];
		new_node->num_keys++;
	}
	
	new_node->pointers[j] = temp_pointers[i];
	free(temp_pointers);
	free(temp_keys);
	new_node->parent = old_node->parent;
	for (i = 0; i <= new_node->num_keys; i++) {
		child = new_node->pointers[i];
		child->parent = new_node;
	}


	return insert_into_parent(root, old_node, k_prime, new_node);
}



node * insert_into_parent(node * root, node * left, int key, node * right) {

	int left_index;
	node * parent;

	parent = left->parent;

	

	if (parent == NULL)
		return insert_into_new_root(left, key, right);


	left_index = get_left_index(parent, left);



	if (parent->num_keys < order - 1)
		return insert_into_node(root, parent, left_index, key, right);


	return insert_into_node_after_splitting(root, parent, left_index, key, right);
}


node * insert_into_new_root(node * left, int key, node * right) {

	node * root = make_node();
	root->keys[0] = key;

	root->pointers[0] = left;
	root->pointers[1] = right;


	root->num_keys++;
	root->parent = NULL;
	left->parent = root;
	right->parent = root;


	return root;
}



node * start_new_tree(int key, record * pointer) {

	node * root = make_leaf();
	root->keys[0] = key;
	root->pointers[0] = pointer;
	root->pointers[order - 1] = NULL;
	root->parent = NULL;
	root->num_keys++;

	return root;
}



node * insert(node * root, int key, int value) {

	record * record_pointer = NULL;
	node * leaf = NULL;


	record_pointer = find(root, key, false, NULL);
    if (record_pointer != NULL) {       

        record_pointer->value = value;
        char c[20];
        itoa(key, c, 10);
        strcat(c,".txt");
        FILE *fp = fopen(c, "w");
        fprintf(fp, "%d ", record_pointer->value);
        fclose(fp);
        return root;
    }


	record_pointer = make_record(value);
	    char c[20];
        itoa(key, c, 10);
        strcat(c,".txt");
        FILE *fp = fopen(c, "w");
        fprintf(fp, "%d ", record_pointer->value);
        fclose(fp);

	if (root == NULL) 
		return start_new_tree(key, record_pointer);


	leaf = find_leaf(root, key, false);


	if (leaf->num_keys < order - 1) {
		leaf = insert_into_leaf(leaf, key, record_pointer);
		return root;
	}


	return insert_into_leaf_after_splitting(root, leaf, key, record_pointer);
}


int get_neighbor_index(node * n) {

	int i;


	for (i = 0; i <= n->parent->num_keys; i++)
		if (n->parent->pointers[i] == n)
			return i - 1;


	printf("Search for nonexistent pointer to node in parent.\n");
	printf("Node:  %#lx\n", n);
	exit(EXIT_FAILURE);
}


node * remove_entry_from_node(node * n, int key, node * pointer) {

	int i, num_pointers;


	i = 0;
	while (n->keys[i] != key)
		i++;
	for (++i; i < n->num_keys; i++)
		n->keys[i - 1] = n->keys[i];


	num_pointers = n->is_leaf ? n->num_keys : n->num_keys + 1;
	i = 0;
	while (n->pointers[i] != pointer)
		i++;
	for (++i; i < num_pointers; i++)
		n->pointers[i - 1] = n->pointers[i];


	n->num_keys--;


	if (n->is_leaf)
		for (i = n->num_keys; i < order - 1; i++)
			n->pointers[i] = NULL;
	else
		for (i = n->num_keys + 1; i < order; i++)
			n->pointers[i] = NULL;

	return n;
}


node * adjust_root(node * root) {

	node * new_root;

	if (root->num_keys > 0)
		return root;




	if (!root->is_leaf) {
		new_root = root->pointers[0];
		new_root->parent = NULL;
	}



	else
		new_root = NULL;

	free(root->keys);
	free(root->pointers);
	free(root);

	return new_root;
}

node * coalesce_nodes(node * root, node * n, node * neighbor, int neighbor_index, int k_prime) {

	int i, j, neighbor_insertion_index, n_end;
	node * tmp;



	if (neighbor_index == -1) {
		tmp = n;
		n = neighbor;
		neighbor = tmp;
	}


	neighbor_insertion_index = neighbor->num_keys;



	if (!n->is_leaf) {

		/* Append k_prime.
		 */

		neighbor->keys[neighbor_insertion_index] = k_prime;
		neighbor->num_keys++;


		n_end = n->num_keys;

		for (i = neighbor_insertion_index + 1, j = 0; j < n_end; i++, j++) {
			neighbor->keys[i] = n->keys[j];
			neighbor->pointers[i] = n->pointers[j];
			neighbor->num_keys++;
			n->num_keys--;
		}


		neighbor->pointers[i] = n->pointers[j];


		for (i = 0; i < neighbor->num_keys + 1; i++) {
			tmp = (node *)neighbor->pointers[i];
			tmp->parent = neighbor;
		}
	}


	else {
		for (i = neighbor_insertion_index, j = 0; j < n->num_keys; i++, j++) {
			neighbor->keys[i] = n->keys[j];
			neighbor->pointers[i] = n->pointers[j];
			neighbor->num_keys++;
		}
		neighbor->pointers[order - 1] = n->pointers[order - 1];
	}

	root = delete_entry(root, n->parent, k_prime, n);
	free(n->keys);
	free(n->pointers);
	free(n); 
	return root;
}


node * redistribute_nodes(node * root, node * n, node * neighbor, int neighbor_index, 
		int k_prime_index, int k_prime) {  

	int i;
	node * tmp;


	if (neighbor_index != -1) {
		if (!n->is_leaf)
			n->pointers[n->num_keys + 1] = n->pointers[n->num_keys];
		for (i = n->num_keys; i > 0; i--) {
			n->keys[i] = n->keys[i - 1];
			n->pointers[i] = n->pointers[i - 1];
		}
		if (!n->is_leaf) {
			n->pointers[0] = neighbor->pointers[neighbor->num_keys];
			tmp = (node *)n->pointers[0];
			tmp->parent = n;
			neighbor->pointers[neighbor->num_keys] = NULL;
			n->keys[0] = k_prime;
			n->parent->keys[k_prime_index] = neighbor->keys[neighbor->num_keys - 1];
		}
		else {
			n->pointers[0] = neighbor->pointers[neighbor->num_keys - 1];
			neighbor->pointers[neighbor->num_keys - 1] = NULL;
			n->keys[0] = neighbor->keys[neighbor->num_keys - 1];
			n->parent->keys[k_prime_index] = n->keys[0];
		}
	}

	else {  
		if (n->is_leaf) {
			n->keys[n->num_keys] = neighbor->keys[0];
			n->pointers[n->num_keys] = neighbor->pointers[0];
			n->parent->keys[k_prime_index] = neighbor->keys[1];
		}
		else {
			n->keys[n->num_keys] = k_prime;
			n->pointers[n->num_keys + 1] = neighbor->pointers[0];
			tmp = (node *)n->pointers[n->num_keys + 1];
			tmp->parent = n;
			n->parent->keys[k_prime_index] = neighbor->keys[0];
		}
		for (i = 0; i < neighbor->num_keys - 1; i++) {
			neighbor->keys[i] = neighbor->keys[i + 1];
			neighbor->pointers[i] = neighbor->pointers[i + 1];
		}
		if (!n->is_leaf)
			neighbor->pointers[i] = neighbor->pointers[i + 1];
	}


	n->num_keys++;
	neighbor->num_keys--;

	return root;
}



node * delete_entry(node * root, node * n, int key, void * pointer) {

	int min_keys;
	node * neighbor;
	int neighbor_index;
	int k_prime_index, k_prime;
	int capacity;	

	n = remove_entry_from_node(n, key, pointer);
	
	if (n == root) 
		return adjust_root(root);
	

	min_keys = n->is_leaf ? cut(order - 1) : cut(order) - 1;



	if (n->num_keys >= min_keys)
		return root;


	neighbor_index = get_neighbor_index(n);
	k_prime_index = neighbor_index == -1 ? 0 : neighbor_index;
	k_prime = n->parent->keys[k_prime_index];
	neighbor = neighbor_index == -1 ? n->parent->pointers[1] : 
		n->parent->pointers[neighbor_index];

	capacity = n->is_leaf ? order : order - 1;


	if (neighbor->num_keys + n->num_keys < capacity)
		return coalesce_nodes(root, n, neighbor, neighbor_index, k_prime);


	else
		return redistribute_nodes(root, n, neighbor, neighbor_index, k_prime_index, k_prime);
}


node * delete(node * root, int key) {

	node * key_leaf = NULL;
	record * key_record = NULL;

	key_record = find(root, key, false, &key_leaf);

    

	if (key_record != NULL && key_leaf != NULL) {
		char s[30];
		sprintf(s, "%d", key);
		strcat(s, ".txt");
		int x = remove(s);
		root = delete_entry(root, key_leaf, key, key_record);
		free(key_record);
	}
	return root;
}


void destroy_tree_nodes(node * root) {
	int i;
	if (root->is_leaf)
		for (i = 0; i < root->num_keys; i++)
			free(root->pointers[i]);
	else
		for (i = 0; i < root->num_keys + 1; i++)
			destroy_tree_nodes(root->pointers[i]);
	free(root->pointers);
	free(root->keys);
	free(root);
}


node * destroy_tree(node * root) {
	destroy_tree_nodes(root);
	return NULL;
}


void print_leaves_to_file(node * const root, FILE * file) {
	if (root == NULL) {
		fprintf(file," ");
		return;
	}
	int i;
	node * c = root;
	while (!c->is_leaf)
		c = c->pointers[0];
	while (true) {
		for (i = 0; i < c->num_keys; i++) {
			fprintf(file,"%d\n", c->keys[i]);
		}
		if (c->pointers[order - 1] != NULL) {
			c = c->pointers[order - 1];
		}
		else
			break;
	}
	printf("\n");
}

int main() {
	char command[255];

	int status;
	FILE *key_file;

	char * input_file;
	FILE * fp;
	node * root;
	int input_key, input_key_2;
	char instruction;
	
	root = NULL;
	verbose_output = false;
	key_file=fopen("key_file.txt","r");
	int key,c,i=0,m=0;
	
	fscanf(key_file,"%d",&c);
	while(c!=i)
	{	
		fscanf(key_file,"%d",&key);
		root = insert(root, key,-1);
		i++;
	}
	fclose(key_file);
	printf("> ");
    char buffer[BUFFER_SIZE];
    int count = 0;
    bool line_consumed = false;
    
	while (scanf("%c", &instruction) != EOF) {
        line_consumed = false;
		switch (instruction) {
			
		case 'd':
			scanf("%d", &input_key);
			root = delete(root, input_key);
			strcpy(command, "del *.isl");
			system(command);
			strcpy(command, "del *.key");
			system(command);
			strcpy(command, "del *.ml");
			system(command);
			strcpy(command, "del *.nk");
			system(command);
			strcpy(command, "del *.point");
			system(command);
			strcpy(command, "del *.par");
			system(command);
			strcpy(command, "del *.isl");
			system(command);
			i--;
			dumptree(root);
			print_tree(root);
			break;
		case 'i':
			
            fgets(buffer, BUFFER_SIZE, stdin);
            line_consumed = true;
            count = sscanf(buffer, "%d %d", &input_key, &input_key_2);
            if (count == 1)
              input_key_2 = input_key;
			root = insert(root, input_key, input_key_2);
			i++;
		//	char command[255];
			strcpy(command, "del *.isl");
			system(command);
			strcpy(command, "del *.key");
			system(command);
			strcpy(command, "del *.ml");
			system(command);
			strcpy(command, "del *.nk");
			system(command);
			strcpy(command, "del *.point");
			system(command);
			strcpy(command, "del *.par");
			system(command);
			strcpy(command, "del *.isl");
			system(command);

			dumptree(root);
			print_tree(root);
			
			break;
	


		case 'l':
			print_leaves(root);
			break;
			
		case 'q':
			key_file=fopen("key_file.txt","w");
			fprintf(key_file,"%d\n",i);
			print_leaves_to_file(root,key_file);
			printf("\n");
			fclose(key_file);
		
			exit(0);
		case 't':
			print_tree(root);
			break;
		case 'f':
			scanf(" %d", &input_key);
   			find_and_print(root, input_key, instruction == 'p');
  			break;

		case 'x':
			if (root)
				root = destroy_tree(root);
		
			break;
		default:
		
			break;
		}
        if (!line_consumed)
           while (getchar() != (int)'\n');
		printf("> ");
	}
	printf("\n");


}
