#include<iostream>
# define SPACE 10

using namespace std;

class Treenode
{
    public:
        int value;
        Treenode* left;
        Treenode* right;

        Treenode()
        {
            value = 0;
            this->left = NULL;
            this->right = NULL;
        }

        Treenode(int value)
        {
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinarySearchTree1
{
    public:
        Treenode* root;

        BinarySearchTree1()
        {
            root = NULL;
        }

        bool isEmpty()
        {
            if (root == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        //insert into tree
        void insertNode(Treenode* new_node)
        {
            if (root == NULL)
            {
                root = new_node;
                cout<<"Value inserted"<<endl;
            }
            else
            {
                Treenode* temp = root;
                while (temp != NULL)
                {
                    if (temp->value == new_node->value)
                    {
                        cout<<"Value already exist"<<endl;
                        return;
                    } 
                    else if ((new_node->value < temp->value) && (temp->left == NULL))
                    {
                        temp->left = new_node;
                        cout<<"Value inserted."<<endl;
                        break;
                    }
                    else if (new_node->value < temp->value)
                    {
                        temp= temp->left;
                    }
                    else if ((new_node->value > temp->value) && (temp->right == NULL))
                    {
                        temp->right = new_node;
                        cout<<"Value inserted"<<endl;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }

        // print preoprder
        void printPreorder(Treenode* root)   //(root,left,right)
        {
            if (root == NULL)
            {
                return;
            }
            //first print data of node
            cout<<root->value<<"\t";
            //then recur on left subtree
            printPreorder(root->left);
            //now recur on right subtree
            printPreorder(root->right);
        }

        //print inorder
        void printInorder(Treenode* root)   //(left, root, right)
        {
            if (root == NULL)
            {
                return;
            }
            //first recur left child
            printInorder(root->left);
            //then print data of node
            cout<<root->value<<"\t";
            // now recur on right child
            printInorder(root->right);
        }

        //search node
        Treenode* iterativeSearch(int val)
        {
            if(root == NULL)
            {
                return root;
            }
            else
            {
                Treenode* temp = root;
                while (temp != NULL)
                {
                    if(val == temp->value)
                    {
                        return temp;
                    }
                    else if(val < temp->value)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                return NULL;
            } 
        }

        //print Postorder
        void printPostOrder(Treenode* root) //(left, right, root)
        {
            if (root == NULL)
            {
                return;
            }
            //first recur on left subtree
            printPostOrder(root->left);
            //then recur on right subtree
            printPostOrder(root->right);
            //print data of the node
            cout<<root->value<<"\t";
        }

        // Print bst tree
        void print2D(Treenode* r, int space)
        {
            if (r == NULL)  //Base case
                return;
            space += SPACE;     //increase distance between levels
            print2D(r->right, space);   //process right child first
            cout<<endl;
            for (int i = SPACE; i < space; i++) //print current node after space count
                cout<<"";
            cout<<r->value<<"\n";
            print2D(r->left, space); //process left child
        }
};

int main()
{
    BinarySearchTree1 bst;
    int option,val;

    do
    {
        cout<<"----------------------------------------------"<<endl;
        cout<<"What operation do you want to perform ? Select 0 to exit."<<endl;
        cout<<"1. Insert Node"<<endl;
        cout<<"2. Search Node"<<endl;
        cout<<"3. Delete Node"<<endl;
        cout<<"4. Print BST values"<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<endl;

        cin>>option;
        Treenode* new_node = new Treenode();
        switch (option)
        {
        case 1:
            cout<<"Insert"<<endl;
            cout<<"Enter the value :"<<endl;
            cin>>val;
            new_node->value = val;
            bst.insertNode(new_node);
            cout<<endl;
            break;

        case 2:
            cout<<"Search"<<endl;
            cout<<"Enter value of node to search"<<endl;
            cin>>val;
            new_node = bst.iterativeSearch(val);
            if(new_node != NULL)
            {
                cout<<"Value Found"<<endl;
            }
            else
            {
                cout<<"Value not found"<<endl;
            }
            break;

        case 3:
            cout<<"Delete"<<endl;
            break;

        case 4:
            cout<<"Print"<<endl;
            bst.print2D(bst.root,5);
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"Print preOrder"<<endl;
            bst.printPreorder(bst.root);
            cout<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"Print inOrder"<<endl;
            bst.printInorder(bst.root);
            cout<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"Print postOrder"<<endl;
            bst.printPostOrder(bst.root);
            cout<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            break;            
        
        default:
            cout<<"Enter Proper Option"<<endl;
        }

    } while (option != 0);
    
}