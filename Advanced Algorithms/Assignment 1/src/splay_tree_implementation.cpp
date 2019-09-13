#include "../include/splay_tree.hpp"

using namespace std;


class splay_tree_implementation : public splay_tree
{
private:
	class node{
	public: node *left, *right;
    int data;};


    node *tree;

    int num_nodes;
  
    vector<int> a;

 
  
	inline node* rgt_rot(node *n)
	{
  	  node *t = n->left;
  	  n->left = t->right;
   	  t->right = n;

   	 return t;
	};


	inline node* splay(node *Node, int data)
	{
   		if(Node == NULL){ return NULL;}
    	if (Node->data == data)
        	return Node;




        
        if (Node->data<data && Node->right==NULL)
            return Node;

        if (Node->data < data && Node->right->data > data)
        {
            Node->right->left = splay(Node->right->left, data);

            if (Node->right->left)
                Node->right = rgt_rot(Node->right);
        }

        else if (Node->data < data && Node->right->data < data)
        {
            Node->right->right = splay(Node->right->right, data);
            Node = lft_rot(Node);
        }

        if(Node->data <data && Node->right !=NULL){
        	return lft_rot(Node);
		}
		if(Node->data < data && Node->right == NULL){
			return Node;
		}

      
    


      
        if (Node->data >= data && Node->left == NULL)
            return Node;

        if (Node->data >=data && Node->left->data > data)
        {
            Node->left->left = splay(Node->left->left, data);
            Node = rgt_rot(Node);
        }

        else if (Node->data >= data && Node->left->data < data)
        {
            Node->left->right = splay(Node->left->right, data);
            if (Node->left->right)
                Node->left = lft_rot(Node->left);
        }

        
		if(Node->data >=data && Node->left == NULL){
			return Node;
		}
		if(Node->data >= data && Node->left !=NULL){
			return rgt_rot(Node);
		}
        
    
	}	;

    inline vector<int> postorder(node *n)
    {
    	if(n == NULL) return a;
		else{
            a = postorder(n->left);
            a = postorder(n->right);
			a.push_back(n->data);
			return a;
            }
        
    };

    inline vector<int> inorder(node *n)
    {
    	if (n == NULL) return a;
		else{
            a = inorder(n->left);
            a.push_back(n->data);a = inorder(n->right);
			return a;
            }
        
    };

	inline node* lft_rot(node *oldnode)
	{
    	node *newnode = oldnode->right;
    	oldnode->right = newnode->left;newnode->left = oldnode;

    	return newnode;
	};
    inline vector<int> preorder(node *n)
    {
    	if(n == NULL) return a;
    		
		
		else{
            a.push_back(n->data);
            a = preorder(n->left);a= preorder(n->right);
			return a;
            
        }
    };
inline node * insert_at_root(node *root, node *location, int ch){
	switch(ch){
	case 1: location->right = root; 
			location->left = root->left; 
			root->left = NULL; 
			return root; 
			break;
	case 0: location->left = root; 
			location->right = root->right;
			root->right = NULL; 
			return root; 
			break;
	}

};
inline node* modify_tree_afterremoving(node *tree, int cas, int data){
	node *temp = tree;
	switch(cas){
		case 0: tree= tree->right; delete temp; return tree;
		case 1: tree = splay(tree->left, data);
				tree->right = temp->right;
				delete temp; return tree;
				

}
}

public:

    int find(int);
    inline void insert(int data)
	{
    if (tree == NULL)
    	{
			tree = new node();
			tree->data = data;
			tree->left = tree->right = NULL;
    		this->num_nodes++;
			return;
    	}


	int i = find(data);
	if(i == 1) return;
   
    else
    {
	
    node *temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	tree = tree->data>=data?insert_at_root(tree, temp, 1):insert_at_root(tree,temp, 0); 



        tree = temp;
        this->num_nodes++;
    }
	


};

			
    void remove(int);
	splay_tree_implementation()
	{
    num_nodes = 0;
    tree = NULL;
	}   


	inline int get_num_nodes()
	{
    	return num_nodes;
	};









    inline vector<int> pre_order(){
    	    a.clear();
    		
    		return preorder(tree);;
	
	
	};
    
   inline vector<int> post_order(){
    	a.clear();
    	
    	return postorder(tree);;
	};
    
    inline vector<int> in_order(){
    	a.clear();
    	
    	return inorder(tree);
	};
    
    ~splay_tree_implementation();
};


int splay_tree_implementation::find(int data)
{
    if(tree == NULL){return 0;}
    tree = splay(tree, data);
    if(tree->data == data){return 1;}

    return 0;
}


void splay_tree_implementation::remove(int i)
{
    if(get_num_nodes() == 0){
	tree = NULL;
	}
    if (tree == NULL){return;};
        

    tree = splay(tree, i);

    if (tree->data != i){return;};
        

  
	tree = tree->left == NULL ? modify_tree_afterremoving(tree, 0, i):modify_tree_afterremoving(tree, 1, i);
	 


    this->num_nodes--;
    



    return;
}


splay_tree_implementation::~splay_tree_implementation()
{
    delete tree;
    tree = NULL;
    num_nodes = 0;
}


