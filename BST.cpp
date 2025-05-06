#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;
};

class BST
{
public:
	node *root;

	BST()
	{
		root=NULL;
	}
	void insert();
	void inorder(node *temp);
	void inorder()
	{
		inorder(root);
	}
	void smallest( );
	void biggest();
	int search (int key);
	void mirror (node *root);
	int height(node *r);
};

void BST::insert()
{
	node *newnode, *temp;
	int flag=0;

	newnode=new node(); // Memory allocation
	newnode->left = newnode->right=NULL;

	cout<<"Insert value of new node: ";
	cin>>newnode->data;
	if (root==NULL)
	{
		root=newnode;
		flag=1;
		cout<<"Node added successfully.\n";
		return;
	}
	else
	{
		temp=root;
	}

	while (true)
	{
		if (newnode->data < temp->data)
		{	// Add to left subtree
			if (temp->left==NULL)
			{
				temp->left=newnode;
				flag = 1;
				cout<<"\nNode added successfully.\n";
				break;
			}
			else
			{
				temp=temp->left;
			}
		}
		else
		{	// Add to right subtree
			if (temp->right==NULL)
			{
				temp->right=newnode;
				flag=1;
				cout<<"\nNode added successfully.\n";
				break;
			}
			else
			{
				temp=temp->right;
			}
		}
	}
}

void BST :: inorder (node *temp)
{
	int cnt;
	if (temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);
		cnt++;
	}
}

void BST :: smallest()
{
	node *temp=root;
	// Traverse to the leftmost node
	while (temp != NULL && temp->left != NULL)
	{
		temp=temp->left;
	}
	if (temp != NULL)
	{
		cout<<"\nSmallest Number: "<<temp->data ;
	}
}

void BST :: biggest()
{
	node *temp=root;
	while (temp != NULL && temp->right != NULL)
	{
		temp=temp->right;
	}
	if (temp != NULL)
	{
		cout<<"\nBiggest number : "<<temp->data;
	}
}

void BST :: mirror(node *root)
{	node *temp;
	if (root!=NULL)
	{
		mirror(root->left);
		mirror(root->right);
		
		node *temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
int BST :: search (int key)
{	node *temp=root;
	while (temp !=NULL)
	{   if (key < temp->data)
		{
			if (temp->left !=NULL)
			{	temp=temp->left;
			}
			else
			{	return 0;
			}
		}

		else if (key > temp->data)
		{
			if (temp->right != NULL)
			{	temp=temp->right;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 1;
		}
    }
   return 0;
}
int BST :: height(node *r)
{
	int r_height, l_height;
 	if(r == NULL)
	 {
	  return 0; 
	 }
 	else if(r->left == NULL && r->right == NULL)
	 {
	  return 0;
	 }
	 l_height = height(r->left);
	 r_height = height(r->right);
	 
	 if(r_height > l_height)
	 {
	  return (r_height + 1);
	 }
	 else
	 {
	  return (l_height + 1);
	 }
}
int main()
{
	BST b;
	int cnt,choice;
	int res=0;
	do
	{
		cout<<"\n*****MENU*****";
		cout<<"\n1.Insert";
		cout<<"\n2.Inorder traversal";
		cout<<"\n3.Smallest";
		cout<<"\n4.Biggest";
		cout<<"\n5.Mirror Image";
		cout<<"\n6.Search";
		cout<<"\n7.Height";
		cout<<"\n8.Exit";
		cout<<"\nEnter your choice:";
		cin>>choice;
		switch (choice)
		{
		case 1:
			cout<<"How many nodes do you want to insert ? :- ";
			cin>>cnt;
			for(int i = 0; i<cnt; i++)
			{
				b.insert();
			}
			break;
		case 2:
			cout<<"\nINORDER TRAVERSAL\n";
			b.inorder();
			break;
		case 3 :
			b.smallest();
			break;
		case 4:
			b.biggest();
			break;
		case 5 :
			cout<<"\nMirror image is : ";
			b.mirror(b.root);
			
			b.inorder();
			break;
		case 6 :
			int key;
			cout<<"\nEnter the key to be search : ";
			cin>>key;
			res =b.search(key);
			if (res==1)
				cout<<"\nElement found ";
			else
				cout<<"\nElement not found ";
			break;
		case 7:
               int res;
               res = b.height(b.root);
               cout << "\nThe height is : " << res;
               break;
		case 8 :
			cout<<"Exit";
			break;
		}
	} while (choice!=8);

	return 0;
}
