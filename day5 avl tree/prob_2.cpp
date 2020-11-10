
// NAME : SACHIN KHOJA
// ROLL NO : 18NA30015

// level order treversal is used to print avl tree in its shape
//diffrent levels of tree are printed in new lines

#include<iostream>

using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;
    int height;
};

 // private inheritance to inherite node data as private members
class avl_tree : private node{

private:
    node* root;

    node* insert(int x, node* t);

    node* singleRightRotate(node* &t);

    node* singleLeftRotate(node* &t);

    node* doubleLeftRotate(node* &t);

    node* doubleRightRotate(node* &t);

    node* findMin(node* t);

    node* findMax(node* t);

    int height(node* t);

    int getBalance(node* t);

    // leve order treversal for printing in its shape

    void  printLevelOrder(node* root);

    void  printGivenLevel(node* root, int level);

public:

// these functions are made because root is private variable and cannot be used by object directly


// so overloaded member function are created that can access private root variable
    avl_tree()
    {
        root = NULL; // zero argument constructor
    }

   // to add elemet in tree
    void insert(int x)
    {
        root = insert(x, root); // call overloaded private insert function so that private root is accessible
    }

//print avl tree

       void tree()
    {
        printLevelOrder(root);  // inorder traversal to print in sorted order
        cout << endl;
    }
};


// class function defination

node* avl_tree :: insert(int x, node* t)
    {
        // adding element in empty tree
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }

        // adding elements as per conditions of avl tree
        else if(x < t->data)
        {
            // adding in left sub-tree
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                //applying rotation for balancing

                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            //adding in right sub-tree
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                //applying rotation for balancing
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

node* avl_tree :: singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

node* avl_tree :: singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

node* avl_tree :: doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

node* avl_tree :: doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

node* avl_tree :: findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

node* avl_tree :: findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

int avl_tree ::  height(node* t)
    {
        if (t == NULL){
            return -1;
        }
        else{
            return t->height;
        }
    }

int avl_tree ::  getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

void avl_tree :: printLevelOrder(node* root)  
{  
    int h = height(root);
    int i;
    for (i = 0; i <= h; i++) 
        printGivenLevel(root, i); 
        cout<< "\n"; // to print next level in new line
}  
  
// to
void avl_tree :: printGivenLevel(node* root, int level)  
{  
    if (root == NULL) { 
        return;  
    }
    if (level == 0)  
        cout << root->data << " ";  
    else if (level > 0)  
    {  
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1);  
    }  
}



int main()
{
    avl_tree t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(35);
    t.insert(67);
    t.insert(43);
    t.insert(21);
    t.insert(10);
    t.insert(89);
    t.insert(38);
    t.insert(69);

    t.tree();
    


    return 0;
}

