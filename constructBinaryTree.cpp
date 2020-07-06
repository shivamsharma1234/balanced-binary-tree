// Shivam Sharma
// 9910902830
// Libraries 
#include <iostream>
#include <string>
#include<bits/stdc++.h> 
using namespace std;
#define COUNT 5
// Data structure to store a Binary Tree node
struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};



/* The function calculates whether the tree is balanced or not
and return the difference if not balanced otherwise return 0 for balanced */
bool checkBalanced(Node* root, int* height) 
{ 
  
    /* leftHeight --> Height of left subtree  
    rightHeight --> Height of right subtree */
    int leftHeight = 0, rightHeight = 0; 
  
    /* l will be true if left subtree is balanced  
    and r will be true if right subtree is balanced */
    int l = 0, r = 0; 
  
    if (root == NULL) { 
        *height = 0; 
        return 1; 
    } 
  
    /* Get the left and right height of the into l and r */
    l = checkBalanced(root->left, &leftHeight); 
    r = checkBalanced(root->right, &rightHeight); 
  
    /* Height of current node is max of heights of left and  
    right subtrees plus 1*/
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; 
  
    /* If difference b/w left and right height is greater than 1 return 0 
    for unbalanced tree */
    // cout<<leftHeight<<"  "<<rightHeight<<" "<<abs(leftHeight -rightHeight)<<"  \n";
    if (abs(leftHeight -rightHeight) >= 2) 
        return 0; 
  
    /* If this node is balanced and left and right subtrees  
    are balanced then return true */
    else
        return l && r; 
} 


// this functions insert nodes tocreate an balanced tree
void balanaceInsert(Node* temp, int key) 
{ 
    queue<Node*> q; 
    q.push(temp); 
  
    // we will do level traversal to insert nodes
    while (!q.empty()) { 
        Node* temp = q.front(); 
        q.pop(); 
  
        if (!temp->left) { 
            temp->left = new Node(key); 
            break; 
        } else
            q.push(temp->left); 
  
        if (!temp->right) { 
            temp->right = new Node(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
} 

// Funtion prints the nodes in inorder traversal 
void printTree(Node *root, int space, bool isRight)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    printTree(root->right, space, true);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    if (isRight)
    cout<<".---";
    else
    cout<<"`---";
    cout<<root->data<<"\n";  
  
    // Process left child  
    printTree(root->left, space, false);  
}  
  



// this functions insert nodes tocreate an unbalanced tree
Node* unbalanaceInsert(Node* root, int key){ 
  
    // x is the pointer for traversing the tree
    Node* x = root; 
  
    // Pointer y maintains the trailing pointer of x 
    Node* y = NULL; 
  
    // new node to be inserted
    Node* newnode = new Node(key); 

    while (x != NULL) { 
        // cout<<"Flag:"<<flag++<<"\n";
        y = x; 
        if (x->data) 
            x = x->left; 
        else
            x = x->right; 
    } 
    
    // If root is null then assign the newnode to it
    if(y == NULL){
        y = newnode;}
  
    // If the left child is null then assign value to it
    else if(y->left==NULL)
        y->left = newnode; 

    // else assign the new node its right child 
    else
        y->right = newnode; 
    
  
    // Returns the tree pointer
    return y; 
} 

int main(int argc, const char* argv[])
{
    int height = 0; 
    int treeNodes = 0;
    
	
    Node* root=NULL;
	
    int choice=-1;
    if ( argc > 1 ) {
        choice = atoi( argv[1] );
        treeNodes= atoi(argv[2]);
    }
    else{
        while((choice>=1)&&(choice<=3))
        cout<<"Kindly give choice as 1, 2 or 3\n";
        cout<<"1.Tree is empty.\n";
        cout<<"2.Tree has > 15 nodes and not balanced.\n";
        cout<<"3.Tree has > 15 nodes and balanced.\n";
        cout<<"4.Exit.\n";
        cin>>choice;
        treeNodes= 20;
        if(choice==4)
           return 0;
        
    }
    cout<<"-------------------------------------------------------------------\n";
    cout <<"Your Choice is:"<<choice<<"\n"; 
    cout<<"-------------------------------------------------------------------\n";

    // Consruct the binary tree
    int i=0;
    if (choice==1)
    {
        cout<<"1.Tree is empty.\n";
    }
    else if (choice==2)
    {
      
        cout<<"2.Tree has > 15 nodes and not balanced.\n";
        cout<<"Tree nodes given:"<<treeNodes<<"\n";
        // Construct above tree
        root = new Node(0);

        for(i=1;i<=treeNodes;i++)
            unbalanaceInsert(root, i);
        
    }
    else if (choice==3)
    {
        
        cout<<"2.Tree has > 15 nodes and balanced.\n";
        cout<<"Tree nodes given:"<<treeNodes<<"\n";
        root = new Node(0);
        for(i=1;i<=treeNodes;i++)
            balanaceInsert(root, i);
        
    }
    
    // print constructed binary tree
    cout<<"-------------------------------------------------------------------\n";
    cout<<"Tree Printed:\n";
    // Pass initial space count as 0  
    printTree(root, 0, false);  
    cout<<"-------------------------------------------------------------------\n";
    int balance = checkBalanced(root, &height);
    if(balance) 
    {cout << "A balanced tree has been constructed with height difference "<<balance<<"\n";} 
    else
    {cout << "An unbalanced tree has been constructed with height difference greater than 1\n" ;}
    cout<<"-------------------------------------------------------------------\n";

    cout.flush();
	return 0;
}