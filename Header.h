#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <fstream>
using namespace std;
struct Machine;
struct RoutingTable;
template <typename T>
struct Node
{
	T val;
	Node* next, * prev;
};

 
template<typename T>
struct DoublyNode
{
	T data;
	DoublyNode<T>* next;
	DoublyNode<T>* prev;
	DoublyNode()//Constructor to initialize node member pointers with NULL
	{
		next = NULL;
		prev = NULL;
		//data = "";
	}
};
template<class T>
class DoublyLinkedList
{
	DoublyNode<T>* head;
	int Elements;
public:
	DoublyLinkedList(long double size=0)//User will input size and this constructor helps initialize with list of size N node chain
	{
		head = NULL;
		Elements = size;
		Create_Space_N(size);

	}
	void Create_Space_N(long double size)//Creating space of N Size
	{
		long double x = 0;
		for (int i = 0; i < size; i++) {
			T* a = new T;
			insert(*a);
		}
	}
	int getElements()const
	{
		return Elements;
	}
	bool insert(T data)
	{
		if (isEmpty())
		{
			head = new DoublyNode<T>;
			head->data = data;
			Elements++;
			return true;
		}
		else
		{
			DoublyNode<T>* Curr = head;
			while (Curr->next != NULL)
				Curr = Curr->next;

			Curr->next = new DoublyNode<T>;
			Curr->next->data = data;
			Curr->next->prev = Curr;

			Elements++;

			return true;
		}
	}
	int Search(T key)//To search element and returning index
	{
		DoublyNode<T>* Curr = head;
		int count = 0;
		while (Curr != NULL)
		{
			if (Curr->data == key)
			{
				return count;
			}
			Curr = Curr->next;
			count++;
		}
		return -1;
	}
	T& getAt(int idx)//Function to get Data at specified idx
	{
		DoublyNode<T>* DATA = NULL;
		if (idx >= 0 && idx < Elements)
		{
			DATA = head;
			for (int i = 0; i < idx; i++)
			{
				DATA = DATA->next;
			}
			return DATA->data;
		}

	}
	bool Delete_At(int idx)//Deleting the specified node
	{
		if (!isEmpty())
		{
			if (idx >= 0 && idx < Elements)
			{
				if (idx == 0)
				{
					if (Elements == 1)
					{
						delete head;
						head = NULL;
						Elements--;
					}
					else
					{
						DoublyNode<T>* Curr = head->next;
						Curr->prev = NULL;
						delete head;
						head = Curr;
						Elements--;
					}
					return true;
				}
				else
				{
					DoublyNode<T>* Curr = head;
					for (int i = 1; i < idx; i++)
					{
						Curr = Curr->next;
					}
					DoublyNode<T>* Prev = Curr->prev;
					DoublyNode<T>* Next = Curr->next;
					delete Curr;
					Prev->next = Next;
					if (Next != NULL)
					{
						Next->prev = Prev;
					}
					Elements--;
					return true;
				}
			}
			else
				return false;
		}
		else
			return false;
	}
	void Display()
	{
		if (!isEmpty())
		{
			DoublyNode<T>* Curr = head;
			while (Curr != NULL)
			{
				cout << Curr->data << " ";
				Curr = Curr->next;
			}
			cout << endl;
		}
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	void clear()//Function to Clear The List
	{
		while (!isEmpty())
		{
			Delete_At(1);
		}
	}
};


template <typename Type>
struct LinkedList 
{

	
	int Length = 0;
	Node<Type>* head = NULL;
	Node<Type>* temp = 0;
	void insert(Type value) {
		Node<Type>* newnode = new Node<Type>;
		newnode->val = value;
		newnode->next = 0;
		if (head == 0) {
			head = newnode;
			temp = head;
		}
		else {
			temp->next = newnode;
			temp = temp->next;
		}




	}

	bool Present(Type a) {

		Node<Type>* t = head;
		while (t) {

			if (t->val == a) { return true; }

			t = t->next;

		}

		return false;
	}
};


template <class T>
struct QueueNode
{
	T data;
	QueueNode<T>* next;
	QueueNode(T dat)
	{
		data = dat;
		next = NULL;
	}
	~QueueNode()
	{

	}
};//DataNodes we'll be using to Store Data in queue
template <class T, class Count>
class Queue
{
	QueueNode<T>* Front;
	QueueNode<T>* Rear;
	Count QueueItems;
public:

	Queue() {
		Front = NULL;
		Rear = NULL;
		QueueItems = 0;
	}

	QueueNode<T>* front()
	{
		return Front;
	}
	T back() {
		return Rear->data;
	}

	bool enqueue(T data)
	{
		if (is_empty())
		{
			Front = new QueueNode<T>(data);
			Rear = Front;
			QueueItems++;
		}
		else
		{
			Rear->next = new QueueNode<T>(data);
			Rear = Rear->next;
			QueueItems++;
		}
		return true;
	}

	T dequeue()
	{
		T data = NULL;
		if (!is_empty())
		{
			if (QueueItems == 1)
			{
				data = Front->data;
				delete Front;
				Front = NULL;
				Rear = NULL;
				QueueItems--;
			}
			else
			{
				QueueNode<T>* Temp = Front->next;
				data = Front->data;
				Front = Temp;
				QueueItems--;
			}
		}
		return data;
	}
	bool is_empty()
	{
		if (QueueItems == 0)
			return true;
		else
			return false;
	}
	~Queue()
	{
		while (QueueItems != 0)
		{
			T data = dequeue();
		}
	}
};


template<typename T2>
class circularlinkedlist
{
public:
	int length;
	Node<T2>* head, * tail;
	circularlinkedlist()
	{
		length = 0;
		head = NULL;
		tail = NULL;
	}
	T2& insert(T2 var)
	{
		//cout << var.id << endl;
		Node<T2>* newnode = new Node<T2>;
		newnode->val = var;
		//	newnode->next = 0;
		if (head == NULL)
		{
			tail = newnode;
			head = newnode;
			newnode->next = head;
		}
		else
		{
			tail->next = newnode;
			newnode->next = head;
			tail = tail->next;
			head->prev = tail;
		}
		length++;
		return newnode->val;
	}
	T2& getatindex(long double i)
	{
		long double ind = 0;
		Node<T2>* temp = head;
		do
		{
			if (ind > i - 1)
			{
				return temp->val;
			}
			temp = temp->next;
			ind++;
		} while (temp != head);
		cout << "Does not exist" << endl;
	}
	T2& insertatindex(T2 var, int ind)
	{
		if (length >= ind + 1)
		{
			int index = 0;
			Node<T2>* newnode = new Node<T2>;
			newnode->val = var;
			Node<T2>* temp = head;
			do
			{
				temp = temp->next;
				index++;
			} while (index < ind - 1);
			if (ind == 0)
			{
				newnode->next = head;
				head = newnode;
			}
			else
			{
				newnode->next = temp->next;
				temp->next = newnode;
			}

			length++;
			return newnode->val;
		}
		cout << "Index is out of range so no identifier was added." << endl;
	}
	T2& deleteatindex(int ind)
	{
		int index = 0;
		if (length >= ind + 1)
		{
			Node<T2>* temp = head;
			while (index < ind - 1)
			{
				temp = temp->next;
				index++;
			}
			if (ind == 0)
			{
				head = head->next;
				temp->next = NULL;
				tail->next = head;
				return temp->val;
			}
			else
			{
				Node<T2>* temp2 = temp->next;
				temp->next = temp->next->next;
				return temp2->val;

			}
		}
		else
		{
			cout << "Index out of range so no identifier was deleted" << endl;
		}
	}
};
/*This function is responsible for writing data inside the specified file
Input path must be used without file extension because extension of .txt is constant here*/
void WritingOnFile(string Path, long double hash, string valu)
{
	fstream inFile(Path + ".txt", ios::app);
	
	inFile  << valu << endl;
}

/*AVLNode Class which store the FilePath and Key and line number where that dataline exist
AVLTree takes height of node*/
struct AVLNode
{
	string FilePath;
	long double key;
	int Line;
	AVLNode* left;
	AVLNode* right;
	int height;
	AVLNode()
	{
		left = NULL;
		right = NULL;
		height = -1;
		Line = -1;
	}


};
/*
	This Class is Responsible for Storing data of machines in Files
	->Method that we are using here to store machine data is whenever data inside file exceeds 100 lines we then create a new file for that AVLTree
	There is no limit for storing data,Every Data must be stored with unique key,incase key collisions occurr then data could be lost from machine before storing into any file
	->In AVLTree we used 4 types of rotation to Balance the tree at every insertion and deletion
		AVLTree balancing condition suppose int x = leftheigh-rightheight;
			then x must be in range of [-1,1]
		other than that,We must used rotations according to conditions to make AVLTree balanced
*/
class AVLTree
{
	AVLNode* root;
public:

	string CurrFile;
	int FileNo;
	int LineNo;
	long double machineid;
	AVLTree()
	{
		machineid = -1;
		FileNo = 1;
		LineNo = 0;
		CurrFile = "RING_FILE";
		root = NULL;
	}
	void BREADTH_FIRST_TRAVERSAL_PRINT();
	AVLNode* insert(string value, AVLNode* node, long double hash)
	{
		if (LineNo == 100)
		{
			LineNo = 0;
			FileNo++;
		}
		if (root == NULL && node==NULL)
		{
			root = new AVLNode;
			root->Line = LineNo;
			root->key = hash;
			root->FilePath = CurrFile + to_string(machineid) + to_string(FileNo);
			WritingOnFile(root->FilePath, hash , value);
			cout << " Insertion in Line Number " << LineNo+1 << endl;
			LineNo++;
			return root;
		}
		else if (node == NULL)
		{
			node = new AVLNode;
			node->Line = LineNo;
			cout << " Insertion in Line Number " << LineNo+1 << endl;
			node->key = hash;
			node->FilePath = CurrFile + to_string(machineid) + to_string(FileNo);
			WritingOnFile(node->FilePath, hash, value);
			LineNo++;
			return node;
		}
		else if (hash < node->key)
		{
			node->left = insert(value, node->left, hash);
			if (getBalanceFactor(node) == 2)
			{
				if (hash < node->left->key)
					node = ROTATION_LL(node);
				else
					node = ROTATION_LR(node);
			}
			node->height = max(getheight(node->left), getheight(node->right)) + 1;
			return node;
		}
		else if (hash > node->key)
		{
			node->right = insert(value, node->right, hash);
			if (getBalanceFactor(node) == -2)
			{
				if (hash > node->right->key)
					node = ROTATION_RR(node);
				else
					node = ROTATION_RL(node);
			}
			node->height = max(getheight(node->left), getheight(node->right)) + 1;
			return node;
		}
		return node;
	}
	int max(int v1, int v2)
	{
		if (v1 > v2)
			return v1;
		else
			return v2;
	}
	AVLNode* getRoot()
	{
		return root;
	}
	void display(AVLNode* node)
	{
		if (node == NULL)
			return;
		display(node->left);
		cout << node->key << " ";
		display(node->right);

	}
	int getheight(AVLNode* node)
	{
		if (node == NULL)
			return -1;
		else
			return node->height;
	}
	int getBalanceFactor(AVLNode* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		int Left_Height = getheight(node->left);
		int Right_Height = getheight(node->right);
		int Balance_Factor = Left_Height - Right_Height;
		return Balance_Factor;
	}
	AVLNode* ROTATION_LL(AVLNode* K1)
	{
		AVLNode* K2;
		K2 = K1->left;
		K1->left = K2->right;
		K2->right = K1;
		K1->height = max(getheight(K1->left), getheight(K1->right)) + 1;
		K2->height = max(getheight(K2->left), K1->height) + 1;
		return K2;

	}
	void setRoot(AVLNode* node)
	{
		root = node;
	}
	AVLNode* ROTATION_RR(AVLNode* K1)
	{
		AVLNode* K2;
		K2 = K1->right;
		K1->right = K2->left;
		K2->left = K1;
		K1->height = max(getheight(K1->left), getheight(K1->right)) + 1;
		K2->height = max(getheight(K2->right), K1->height) + 1;
		return K2;
	}
	AVLNode* ROTATION_RL(AVLNode* node)
	{
		node->right = ROTATION_LL(node->right);
		return ROTATION_RR(node);
	}
	AVLNode* ROTATION_LR(AVLNode* node)
	{
		node->left = ROTATION_RR(node->left);
		return ROTATION_LL(node);
	}
	AVLNode* Delete_Node(long double hash, AVLNode* node,AVLNode*& NodeRecieve,bool &FindTrue)
	{
		if (node == NULL)
		{
			return node;
		}
		if (hash < node->key)
		{
			node->left = Delete_Node(hash, node->left,NodeRecieve,FindTrue);
		}
		else if (hash > node->key)
		{
			node->right = Delete_Node(hash, node->right, NodeRecieve, FindTrue);
		}
		else if(hash == node->key)
		{
			if (hash == node->key && FindTrue==false)//Here we are using reference variable to indicate if we reached the required node
			{
				NodeRecieve->key = node->key;
				NodeRecieve->Line = node->Line;
				NodeRecieve->FilePath = node->FilePath;
				FindTrue = true;
			}
			if (node->right == NULL)//Case if right is null then left will be returned and node will be deleted
			{
				AVLNode* temp = node->left;
				delete node;
				node = NULL;
				return temp;
			}
			else if (node->left == NULL)//Case if we have left child is null then right will be returned and node will be deleted
			{
				AVLNode* temp = node->right;
				delete node;
				node = NULL;
				return temp;
			}
			AVLNode* temp = minimum_value_node(node->right);//Getting bottom left most node inorder to delete required node without affecting the structure of tree
			node->key = temp->key;
			node->Line = temp->Line;
			node->FilePath = temp->FilePath;
			node->right = Delete_Node(temp->key, node->right, NodeRecieve, FindTrue);
			if (getBalanceFactor(node) == 2)//If Balance Factor 2 than tree will be balanced by using Left to Right Rotations 
			{
				if (hash < node->left->key)//Checking if we have to perform double rotation or single
					node = ROTATION_LL(node);//Single left Rotation
				else
					node = ROTATION_LR(node);//Double Left Rotation
			}
			else if (getBalanceFactor(node) == -2)//If Balance Factor 2 than tree will be balanced by using Right to Left Rotations 
			{
				if (hash > node->right->key)//Checking if we have to perform double rotation or single
					node = ROTATION_RR(node);//Single Right Rotation
				else
					node = ROTATION_RL(node);//Double Right Rotation
			}
			node->height = max(getheight(node->left), getheight(node->right)) + 1;
		}
		return node;
	}
	AVLNode* Delete_Node(long double hash) //Pash hash key id to delete the required node
	{
		bool Found = false;//bool to Indicates if we have gotten the node's data or not
		AVLNode* NodeRecieve = new AVLNode;
		root = Delete_Node(hash,root,NodeRecieve,Found);
		return NodeRecieve;//This returned NodeRecieve is the data we fetched and deleted from the AVLTree
	}
	void display()
	{
		display(root);
	}
	void insert(string value, long double hash)//This function inserts some string values based on ther hash value which is of type long double;
	{
		root = insert(value, root, hash);
	}

	AVLNode* minimum_value_node(AVLNode* node)//this function helps us to get bottom most left nodes 
	{
		if (node == NULL)
		{
			return NULL;
		}
		while (node->left != NULL)
		{
			node = node->left;
		}
		return node;
	}
	/*
		-> Use of Queue
		-> Printing AVLTree according to levels
	
	*/
	void BREADTH_FIRST_TRAVERSAL()
	{
		Queue<AVLNode*, int> Visited;
		AVLNode* Curr = root;
		int nodes = 0;
		int levels = 0;
		if (root != NULL)
		{
			int x = Curr->height;
			cout << Curr->key << " " << endl;
			nodes = 0;
			levels = 1;
			do {
				if (Curr->left != NULL)
				{
					cout << Curr->left->key << " ";
					Visited.enqueue(Curr->left);
				}
				else
				{
					cout << "-" << " ";
				}
				if (Curr->right != NULL)
				{
					cout << Curr->right->key << " ";
					Visited.enqueue(Curr->right);
				}
				else
				{
					cout << "-" << " ";
				}
				nodes += 2;
				if (pow(2, levels) == nodes)
				{
					levels++;
					nodes = 0;
					cout << endl;
				}
				Curr = Visited.dequeue();
			} while (!Visited.is_empty());
		}
		cout << endl;
	}

};
long double rand(long double MIN, long double MAX)/*Using random library,we created a function that return the pure random number between specified range
												  Just because it can help us generate values of large sizes and here we are generating random numbers of type long double*/
{
	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<long double> distr(MIN, MAX);
	long double x = distr(eng);
	return x;
}
string getCharBin(char X)
{
	int x = 0;
	if (X >= '0' && X <= '9')
	{
		x = int(X);
	}
	else
	{
		x = 9 + (int(X % 97) + 1);
	}
	char* arr = new char[5];
	for (int i = 0; i < 4; i++)
	{
		arr[i] = '0';
	}
	arr[4] = '\0';
	int count = 3;
	while (x > 0)
	{
		if (x % 2 == 0)
			arr[count] = '0';
		else
			arr[count] = '1';
		x /= 2;
		count--;
	}
	return arr;
}
string HexToBin(string X, int nibble)
{
	string Data = "";
	for (int i = 0; i < nibble; i++)
	{
		Data = Data + getCharBin(X[i]);
	}
	return Data;
}
/*
	This function Takes key string and gives us hash of the given key according to bits that we specify to the functions
*/
long double Hash(string key, int bits)
{
	SHA1 sha1;
	sha1(key);
	string Binary = HexToBin(sha1.getHash(), 40);//160 bits to bits require
	int count = 160;
	long double val = 0;
	for (int i = 0; i < bits; i++)
	{
	//	cout << Binary[count - 1 - i];
		if (Binary[count - i - 1] == '1')
		{
			val += pow(2, i);
		}
	}
	//cout << endl;
	return val;
}
struct Identifiers {
	long double id;
	Machine* checkMachine;

	Identifiers() {//Innitializing the values
		id = -1;
		checkMachine = 0;
	

	}
	

};
struct RoutingTable {
	int row;//Which Row of the Routing Table
	long double nextindenifier;//Routing Node responsible
	Identifiers* JumpPtr;//Shortcut Address
	RoutingTable() { //Initializing the values
		row = 0;
		nextindenifier = 0;
		JumpPtr = 0;
	}
	void makeRoutes(long double p, int i) {//find the Routing Node for that Machine
		row = i;
		nextindenifier = p + pow(2, i);
	}
	 
};
struct Machine {
	//Space means the Identifiers space is of how many Bytes
	int space;
	//Machine ID
	long double ID;
	//For storing the range that Machine is Responsible for
	long double rangeMin;
	long double rangeMax;
	// AVL TREE root
	AVLTree* NodeData;
	DoublyLinkedList<RoutingTable> Route;//Doubley LINKED list of Routes

	Machine(int c,long double d, long double a = 0, long double b = 0) {//(SPACE, ID , RANGEMIN , RANGEMAX)
		ID = d;
		space = c;
		rangeMin = a;
		rangeMax = b;
		NodeData = new AVLTree;
		NodeData->machineid = ID;
		Route.Create_Space_N(space);//Initializing the Size of my Doubly linked list of Routes

		cout << "Machine has range from " << rangeMin << "   to   " << rangeMax << endl;
		this->CreateRoutingTable();//Creating the Routing Nodes
	}
	void CreateRoutingTable() {//Creating the Routing Nodes of the Table
		long double h = pow(2, space);//Total circle
		cout << "	Routing Table" << endl;
		for (int i = 0; i < space; i++) {
			Route.getAt(i).makeRoutes(ID, i);
			if (Route.getAt(i).nextindenifier >= h) {//for keeping the Round ROBIN format
				Route.getAt(i).nextindenifier -= h;
			}

			cout << " Row : " << Route.getAt(i).row +1<< "     Routing Node ID: " << Route.getAt(i).nextindenifier << endl;
			
		}
	}
	void ConfirmRoutes(circularlinkedlist<Identifiers> Machines, int len) {//Confirming that which Machine is Responsible for the Routing NODES


		for (int i = 0; i < space; i++) {//Loop for Numebr of Rows OF Routing Table

			for (int j = 0; j < len; j++) {//Loop for the total Number of Machines
		//Finding the Machiens Responsible 
				if (Route.getAt(i).nextindenifier>= Machines.getatindex(j).checkMachine->rangeMin&& Route.getAt(i).nextindenifier<= Machines.getatindex(j).checkMachine->rangeMax) {
					Route.getAt(i).JumpPtr = &Machines.getatindex(j);
					cout << Route.getAt(i).nextindenifier << "  -> " << Route.getAt(i).JumpPtr->id << endl;
					break;
				}
				if (j == len - 1) {
					Route.getAt(i).JumpPtr = &Machines.getatindex(0);
					cout << Route.getAt(i).nextindenifier << "  -> " << Route.getAt(i).JumpPtr->id << endl;
					break;
				
				}

			}
			
		}
	
	}

};

struct IdentifierSpace {
	
	circularlinkedlist<Identifiers> Machines;//Circular Linked List of Machines 
	int NumberOfMachines;//Total Number of Machines 
	int bits;//Bytes of Identifier space
	IdentifierSpace(int MachineNumber, bool random, int n = 160) {
		bits = n;
		NumberOfMachines = MachineNumber;
		int tempMachine = MachineNumber;
	
		int tempindex = 0;
		if (random) {//If Random Machines are to be Assigned


			cout << "               Randomly Creating Machines     " << endl;
			cout << endl;
			long double x = pow(2, n);

			long double y = x / MachineNumber;//Keeping the Logic to 160 Bytes si divinding the Path
			long double Min = 0;
			long double Max = y;
			long double lastMachine = -1;
			bool createRandomMachine = false;
			Identifiers temp;

			long double RandomNumber = rand(Min, Max);
			//Logic is Making a Machine in every Divided Path
			for (long double i = 0; i < x; i += 1.0) {
				if (i > x) { break; }

				if (i > RandomNumber && MachineNumber != 0) {
					Identifiers insert;
					insert.id = i;
					cout << "*******Creating a Machine at Id  No " << i << "  **********" << endl;
					insert.checkMachine = new Machine(n, i, lastMachine + 1, i);
					if (lastMachine == -1) {
						temp = insert;
					}
					lastMachine = i;
					Min += y;
					Max += y;
					RandomNumber = rand(Min, Max - 1);

					MachineNumber--;

					if (MachineNumber == 0) {//If last Random Machien is Made in eg 25 Node so for changing the ranges of First Machine as it is a circular Path
						if (i != x - 1) {

							temp.checkMachine->rangeMin = i + 1;
							cout << "		Need to Chnage the Range of Machine  with ID " << temp.checkMachine->rangeMax << endl;
							cout << "The New RANGE is from   " << temp.checkMachine->rangeMin << "    to     " << temp.checkMachine->rangeMax << endl;
						}

					}
					Machines.insert(insert);

				}

			}

		}
		else {
			//Manually assigning the Machines
			cout << "              Making Machine Manually " << endl;

			long double* array = new long double[MachineNumber];
			for (int i = 0; i < MachineNumber; i++) {
				cout << "Enter the Id of Machine Number " << i + 1 << endl;
				cin >> array[i];
			}
			for (int i = 0; i < MachineNumber; i++) {//Sorting the MACHINE iDS
				for (int j = 0; j < MachineNumber; j++) {
					if (array[i] < array[j]) {
						long double temp = array[i];
						array[i] = array[j];
						array[j] = temp;

					}

				}

			}
			long double x = pow(2, n);
			int index = 0;
			long double lastMachine = 0;
			if (array[NumberOfMachines - 1] != x - 1) {
				lastMachine = array[NumberOfMachines - 1];
			}
			//making Machines
			for (long double i = 0; i < x; i += 1.0) {
				if (i > x) { break; }

				if (i > array[index] - 1 && index != MachineNumber) {
					Identifiers insert;
					insert.id = i;
					cout << "*******Creating a Machine at Id  No " << i << "  **********" << endl;

					insert.checkMachine = new Machine(n, i, lastMachine + 1, i);
					lastMachine = i;
					index++;
					Machines.insert(insert);
				}
			}
			delete[]array;
		}
		long double save = Machines.getatindex(0).checkMachine->rangeMin;
		Machines.getatindex(0).checkMachine->rangeMin = 0;
		//Making the Routing Table of The Machines
		for (int i = 0; i < tempMachine; i++) {
			Machines.getatindex(i).checkMachine->ConfirmRoutes(Machines, tempMachine);

		}
		Machines.getatindex(0).checkMachine->rangeMin = save;

	}
	void Insert(string key, string value, int MachineIndex) {
		if (MachineIndex == -1) {//if User Dont Want to create Machines
			return;
		}
		LinkedList<long double>* check = new LinkedList<long double>;//Preventing from Recursive path
		cout << endl;
		cout << "*************** INSERTION ***************" << endl;
		cout << "Insertion Query Came to Machine ID " << Machines.getatindex(MachineIndex).id << endl;

		long double Location = Hash(key, bits);

		cout << "Location to Insert After Hashing is " << Location << endl;
		bool insert = false;

		Identifiers* temp = &Machines.getatindex(MachineIndex);//stating my Path from given Machine By user

		while (!insert) {

			//Condition 1 Check 
		//Checking the Machine Ranges whether it can Store or Not 

			//Below if else the Possible cases of cehcking the Location 
			if (temp->checkMachine->rangeMin <= temp->checkMachine->rangeMax) {
				if (Location >= temp->checkMachine->rangeMin && Location <= temp->checkMachine->rangeMax) {
					cout << "Insertion of The Value in Machine ID " << temp->id << endl;
					insert = true;
					temp->checkMachine->NodeData->insert(value, Location);
					break;
				}
			}
			else {
				if (Location <= temp->checkMachine->rangeMax || Location >= temp->checkMachine->rangeMin) {
					cout << "Insertion of The Value in Machine ID " << temp->id << endl;
					temp->checkMachine->NodeData->insert(value, Location);
					insert = true;
					break;
				}
			}

			cout << endl;
			cout << "Checking the Routing Table of  " << temp->id << endl;
			if (temp->checkMachine->Route.getAt(0).JumpPtr->id >= Location) {//Condition 2 of Routing Table
				cout << "Moving to " << temp->checkMachine->Route.getAt(0).JumpPtr->id << endl;
				check->insert(temp->checkMachine->Route.getAt(0).JumpPtr->id);
				temp = temp->checkMachine->Route.getAt(0).JumpPtr;
			}
			else if (temp->checkMachine->Route.getAt(0).JumpPtr->id < Location) {
				bool found = false;
				//Condition 3 of  Routing Table
				for (int j = 1; j < bits; j++) {
					//Checking whether the Routing machine is responsible or Not
					if (temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMin <= temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMax) {
						if (Location >= temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMin && Location <= temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMax) {
							temp = temp->checkMachine->Route.getAt(j - 1).JumpPtr;
							cout << "Moving to " << temp->id << endl;

							check->insert(temp->id);
							found = true;
							break;
						}
					}
					else {
					
						if (Location <= temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMax || Location >= temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMin) {

							temp = temp->checkMachine->Route.getAt(j - 1).JumpPtr;
							cout << "Moving to " << temp->id << endl;
							check->insert(temp->id);
							found = true;
							break;
						}
					}

		//checking if Location is less then the node
					if (temp->checkMachine->Route.getAt(j).JumpPtr->id > Location) {
						temp = temp->checkMachine->Route.getAt(j - 1).JumpPtr;
						cout << "Moving to " << temp->id << endl;
						check->insert(temp->id);
						found = true;
						break;
					}
					else if (Location > temp->checkMachine->Route.getAt(j - 1).JumpPtr->id) {
						if (temp->checkMachine->Route.getAt(j).JumpPtr->id < temp->checkMachine->Route.getAt(j - 1).JumpPtr->id) {
							temp = temp->checkMachine->Route.getAt(j - 1).JumpPtr;
							cout << "Moving to " << temp->id << endl;
							check->insert(temp->id);
							found = true;
							break;
						}

					}



				}

				if (!found) {//if Not Found the VALUE

					int x = bits;

					while (temp->id == temp->checkMachine->Route.getAt(x - 1).JumpPtr->id) {
						x = x - 1;
					}
					if (!check->Present(temp->checkMachine->Route.getAt(x - 1).JumpPtr->id)) {
						temp = temp->checkMachine->Route.getAt(x - 1).JumpPtr;
					}
					else {
						temp = temp->checkMachine->Route.getAt(x - 2).JumpPtr;

					}
					cout << "Moving to " << temp->id << endl;
				}


			}

		}

	}
	void Delete(string key, int MachineIndex) {
		LinkedList<long double>* check = new LinkedList<long double>;
		AVLNode* deleted = 0;
		cout << endl;
		cout << "**************** DELETION ******************" << endl;

		cout << "Deletion Query Came to Machine ID " << Machines.getatindex(MachineIndex).id << endl;
		long double Location = Hash(key, bits);

		cout << "Location to Delete After Hashing is " << Location << endl;
		bool Delete = false;
		Identifiers* temp = &Machines.getatindex(MachineIndex);

		while (!Delete) {

			//Condition 1 Check 
		//Checking the Machine Ranges whether it can Store or Not 
			if (temp->checkMachine->rangeMin <= temp->checkMachine->rangeMax) {//same cases for the Path as Insertion
				if (Location >= temp->checkMachine->rangeMin && Location <= temp->checkMachine->rangeMax) {

					cout << "Deletion of The Value in Machine ID " << temp->id << endl;
					AVLNode* t = new AVLNode;

					deleted = temp->checkMachine->NodeData->Delete_Node(Location);
					if (deleted->Line == -1) {
						cout << "The value DoesNot Exists in Tree" << endl;
						return;
					}
					cout << "The Line to Be Deleted From File is " << deleted->Line + 1 << endl;
					Delete = true;
					break;
				}
			}
			else {
				if (Location <= temp->checkMachine->rangeMax || Location >= temp->checkMachine->rangeMin) {

					cout << "Insertion of The Value in Machine ID " << temp->id << endl;

					deleted = temp->checkMachine->NodeData->Delete_Node(Location);
					if (deleted->Line == -1) {
						cout << "The value DoesNot Exists in Tree" << endl;
						return;
					}
					cout << "The Line to Be Deleted From File is " << deleted->Line + 1 << endl;
					Delete = true;
					break;
				}
			}

			cout << endl;
			cout << "Checking the Routing Table of  " << temp->id << endl;
			if (temp->checkMachine->Route.getAt(0).JumpPtr->id >= Location) {//Condition 2 of Routing Table

				cout << "Moving to " << temp->checkMachine->Route.getAt(0).JumpPtr->id << endl;
				temp = temp->checkMachine->Route.getAt(0).JumpPtr;
			}
			else if (temp->checkMachine->Route.getAt(0).JumpPtr->id < Location) {
				bool found = false;
				//Condition 3 of  Routing Table
				for (int j = 1; j < bits; j++) {

					if (temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMin <= temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMax) {
						if (Location >= temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMin && Location <= temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMax) {
							temp = temp->checkMachine->Route.getAt(j - 1).JumpPtr;
							cout << "Moving to " << temp->id << endl;
							found = true;
							break;
						}
					}
					else {

						if (Location <= temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMax || Location >= temp->checkMachine->Route.getAt(j).JumpPtr->checkMachine->rangeMin) {

							temp = temp->checkMachine->Route.getAt(j - 1).JumpPtr;
							cout << "Moving to " << temp->id << endl;
							found = true;
							break;
						}
					}

					if (temp->checkMachine->Route.getAt(j).JumpPtr->id > Location) {
						temp = temp->checkMachine->Route.getAt(j - 1).JumpPtr;
						cout << "Moving to " << temp->id << endl;
						found = true;
						break;
					}

					//if location is less than the path
					if (temp->checkMachine->Route.getAt(j).JumpPtr->id > Location) {
						temp = temp->checkMachine->Route.getAt(j - 1).JumpPtr;
						cout << "Moving to " << temp->id << endl;
						check->insert(temp->id);
						found = true;
						break;
					}
					else if (Location > temp->checkMachine->Route.getAt(j - 1).JumpPtr->id) {
						if (temp->checkMachine->Route.getAt(j).JumpPtr->id < temp->checkMachine->Route.getAt(j - 1).JumpPtr->id) {
							temp = temp->checkMachine->Route.getAt(j - 1).JumpPtr;
							cout << "Moving to " << temp->id << endl;
							check->insert(temp->id);
							found = true;
							break;
						}

					}



				}


				if (!found) {//If routing is Unsuccessful in above path

					int x = bits;

					while (temp->id == temp->checkMachine->Route.getAt(x - 1).JumpPtr->id) {
						x = x - 1;
					}
					if (!check->Present(temp->checkMachine->Route.getAt(x - 1).JumpPtr->id)) {
						temp = temp->checkMachine->Route.getAt(x - 1).JumpPtr;
					}
					else {
						temp = temp->checkMachine->Route.getAt(x - 2).JumpPtr;

					}
					cout << "Moving to " << temp->id << endl;
				}
			}

		}

		ifstream input;
		input.open(deleted->FilePath + ".txt");//Managing the Files after deletion
		circularlinkedlist<string> data;

		int count = 0;

		while (!input.eof()) {//storing all the data of the file
			string a;
			getline(input, a);
			cout << a.length() << endl;
			data.insert(a);
			count++;

		}
		input.close();

		ofstream output;
		output.open(deleted->FilePath + ".txt");
		//Storing the data after deletion of the line
		Node <string>* listptr = data.head;
		for (int i = 0; i < count - 1; i++) {

			if (deleted->Line == i) {
				output << " " << endl;

			}
			else {
				output << listptr->val << endl;

			}
			listptr = listptr->next;

		}

		output.close();



	}
	int MachineResponsible(long double Location) {
		//give this function the Machine Id and it will tell tha Which Machine is Responsible 
		for (int i = 0; i < NumberOfMachines; i++) {
			if (Machines.getatindex(i).checkMachine->rangeMin <= Machines.getatindex(i).checkMachine->rangeMax) {
				if (Location >= Machines.getatindex(i).checkMachine->rangeMin && Location <= Machines.getatindex(i).checkMachine->rangeMax) {
					return i;
				}
			}
			else {

				if (Location >= Machines.getatindex(i).checkMachine->rangeMin || Location <= Machines.getatindex(i).checkMachine->rangeMax) {
					cout << Machines.getatindex(i).checkMachine->rangeMin << "   ,  " << Machines.getatindex(i).checkMachine->rangeMax << endl;

					return i;
				}
			}
		}
		return -1;

	}
	//Insetion of MACHINE
	void InsertMachine(long double Machineid) {
		for (int i = 0; i < NumberOfMachines; i++) {
			if (Machines.getatindex(i).id == Machineid) {
				cout << "Machines Already Exists " << endl;
				return;
			}

		}

		cout << endl;

		cout << "***************** Adding a New Machine ************ " << endl;


		Identifiers Toinsert;
		Toinsert.id = Machineid;


		int lastresponsible = MachineResponsible(Machineid);

		Machine* Savetemp=0;
		Machine* ModifiedMachine=0;
		int max = 0, min = 0;
		if (Machines.getatindex(lastresponsible).checkMachine->rangeMin == Machineid) {
			max = Machines.getatindex(lastresponsible).checkMachine->rangeMax;
			min = Machines.getatindex(lastresponsible).checkMachine->rangeMin;
			Savetemp = Machines.getatindex(lastresponsible).checkMachine;
			cout << "Readjusting the Ranges of Machines" << endl;
			Machines.getatindex(lastresponsible).checkMachine = new Machine(bits, Machines.getatindex(lastresponsible).id, min + 1, max);
			ModifiedMachine = Machines.getatindex(lastresponsible).checkMachine;
			cout << "Creating the New Machine and its Routing Table " << endl;
			Toinsert.checkMachine = new Machine(bits, Machineid, min, min);
		}
		else if ((Machines.getatindex(lastresponsible).checkMachine->rangeMax) - 1 == Machineid) {//Just Before the Machine ADDITION 
			max = Machines.getatindex(lastresponsible).checkMachine->rangeMax;
			min = Machines.getatindex(lastresponsible).checkMachine->rangeMin;
			Savetemp = Machines.getatindex(lastresponsible).checkMachine;
			cout << "Readjusting the Ranges of Machines" << endl;
			Toinsert.checkMachine = new Machine(bits, Machineid, min, max - 1);
			cout << "Creating the New Machine and its Routing Table " << endl;
			Machines.getatindex(lastresponsible).checkMachine = new Machine(bits, Machines.getatindex(lastresponsible).id, max, max);
			ModifiedMachine = Machines.getatindex(lastresponsible).checkMachine;
		}

		else {
			if (Machines.getatindex(lastresponsible).checkMachine->rangeMax > Machines.getatindex(lastresponsible).checkMachine->rangeMin) {
				max = Machines.getatindex(lastresponsible).checkMachine->rangeMax;
				min = Machines.getatindex(lastresponsible).checkMachine->rangeMin;
				Savetemp = Machines.getatindex(lastresponsible).checkMachine;
				cout << "Readjusting the Ranges of Machines And Routing Tables " << endl;
				Machines.getatindex(lastresponsible).checkMachine = new Machine(bits, Machines.getatindex(lastresponsible).id, Machineid + 1, max);
				ModifiedMachine = Machines.getatindex(lastresponsible).checkMachine;
				cout << "Creating the New Machine and its Routing Table " << endl;
				Toinsert.checkMachine = new Machine(bits, Machineid, min, Machineid);
			}
			else {
				long double total = pow(2, bits);

				max = Machines.getatindex(lastresponsible).checkMachine->rangeMax;
				min = Machines.getatindex(lastresponsible).checkMachine->rangeMin;
				Savetemp = Machines.getatindex(lastresponsible).checkMachine;
				cout << "Readjusting the Ranges of Machines And Routing Tables " << endl;
				if (Machineid + 1 > total) {
					Machines.getatindex(lastresponsible).checkMachine = new Machine(bits, Machines.getatindex(lastresponsible).id, (Machineid + 1) - total, max);
					ModifiedMachine = Machines.getatindex(lastresponsible).checkMachine;
				}
				else {
					Machines.getatindex(lastresponsible).checkMachine = new Machine(bits, Machines.getatindex(lastresponsible).id, Machineid + 1, max);
					ModifiedMachine = Machines.getatindex(lastresponsible).checkMachine;
				}
				cout << "Creating the New Machine and its Routing Table " << endl;
				Toinsert.checkMachine = new Machine(bits, Machineid, min, Machineid);
			}
		}

		int newplace = -1;
		bool insert = false;
		for (int i = 0; i < NumberOfMachines;) {
			if (Machines.getatindex(i).id < Machineid) {

				i++;
			}

			else {
				insert = true;
				Toinsert=Machines.insertatindex(Toinsert, i);
				newplace = i;
				break;
			}
		}

		if (!insert) {
			Toinsert=Machines.insert(Toinsert);
			newplace = NumberOfMachines;
		}

		cout << endl;
		NumberOfMachines++;
		
		


		long double save = -1;
		//Machines.getatindex(0).checkMachine->rangeMin = 0;
		//cout << NumberOfMachines << endl;
		int ind = -1;
		
		for (int i = 0; i < NumberOfMachines; i++) {
		
			if (Machines.getatindex(i).checkMachine->rangeMax < Machines.getatindex(i).checkMachine->rangeMin) {
				save = Machines.getatindex(i).checkMachine->rangeMin;
				Machines.getatindex(i).checkMachine->rangeMin = 0;
				ind = i;
		
			}

			Machines.getatindex(i).checkMachine->ConfirmRoutes(Machines, NumberOfMachines);
			
		}
		if (ind != -1) {
			Machines.getatindex(ind).checkMachine->rangeMin = save;

		}

	
		if (Savetemp->NodeData->LineNo != 0) {
			ifstream input;
		
			input.open(Savetemp->NodeData->CurrFile + to_string(Savetemp->ID) + to_string(Savetemp->NodeData->FileNo) + ".txt");
			circularlinkedlist<string> data;

			int count = 0;

			while (!input.eof()) {
				string a;
				getline(input, a);

				data.insert(a);
				count++;

			}
			input.close();
			ofstream cl;
			cl.open(Savetemp->NodeData->CurrFile + to_string(Savetemp->ID) + to_string(Savetemp->NodeData->FileNo) + ".txt");
			cl << "";
			cl.close();
			cout << endl;
			cout << "*********************** Modifying the Files As New Machine is Inserted ***************" << endl;
			max = ModifiedMachine->rangeMax;
			min = ModifiedMachine->rangeMin;
		
			while (min != max + 1) {

				if (min >= pow(2, bits)) {
					min -= pow(2, bits);
				}
				AVLNode* t = Savetemp->NodeData->Delete_Node(min);
				if (t->Line != -1) {
					ModifiedMachine->NodeData->insert(data.getatindex(t->Line), min);
				}
				delete t;
				min++;
			}
			max = Toinsert.checkMachine->rangeMax;
			min = Toinsert.checkMachine->rangeMin;


			while (min != max + 1) {

				if (min >= pow(2, bits)) {
					min -= pow(2, bits);
				}
				AVLNode* t = Savetemp->NodeData->Delete_Node(min);
				if (t->Line != -1) {

					Toinsert.checkMachine->NodeData->insert(data.getatindex(t->Line), min);
				}


				min++;
			}
		}




	}

	void RemoveTheMachine(long double Machineid) {
		cout << endl;
		cout << "******************* Removing A Machine **************" << endl;
		bool found = false;
		int index = -1;
		Machine* deleted = 0;
		Identifiers* Responsible = 0;
		for (int i = 0; i < NumberOfMachines; i++) {
			if (Machines.getatindex(i).id == Machineid) {
				
				found = true;
				index = i;
				deleted = Machines.getatindex(i).checkMachine;
				Responsible = &Machines.getatindex((i + 1)%NumberOfMachines);
				break;
			}
		}

		if (!found) {
			cout << "There is No Machine with this Id " << endl;
			return;
		}


		if (deleted->NodeData->LineNo != 0) {
			ifstream input;

			input.open(deleted->NodeData->CurrFile + to_string(deleted->ID) + to_string(deleted->NodeData->FileNo) + ".txt");
			circularlinkedlist<string> data;

			int count = 0;

			while (!input.eof()) {
				string a;
				getline(input, a);


				data.insert(a);
				count++;


			}

			data.deleteatindex(count - 1);



			input.close();
			ofstream cl;
			cl.open(deleted->NodeData->CurrFile + to_string(deleted->ID) + to_string(deleted->NodeData->FileNo) + ".txt");
			cl << "";
			cl.close();
			cout << endl;
			cout << "*********************** Modifying the Files As Machine is Deleted ***************" << endl;


			Responsible->checkMachine->rangeMin = deleted->rangeMin;
			long double min = deleted->rangeMin;
			long double max = deleted->rangeMax;
			bool first = true;
			while (min != max + 1) {

				if (min >= pow(2, bits)) {
					min -= pow(2, bits);
				}

				AVLNode* t = deleted->NodeData->Delete_Node(min);

				if (t->Line != -1) 
				{
					Responsible->checkMachine->NodeData->insert(data.getatindex(t->Line), min);
				}

				min += 1.0;
			}

		}
		Machines.deleteatindex(index);
		NumberOfMachines--;



		cout << endl;
		cout << "Making changes in the new Routing Table " << endl;

		long double save = -1;
		int ind = -1;

		for (int i = 0; i < NumberOfMachines; i++) {

			if (Machines.getatindex(i).checkMachine->rangeMax < Machines.getatindex(i).checkMachine->rangeMin) {
				save = Machines.getatindex(i).checkMachine->rangeMin;
				Machines.getatindex(i).checkMachine->rangeMin = 0;
				ind = i;

			}

			Machines.getatindex(i).checkMachine->ConfirmRoutes(Machines, NumberOfMachines);

		}
		if (ind != -1) {
			Machines.getatindex(ind).checkMachine->rangeMin = save;

		}
		
		this->DisplayRoutingTable();

	}
	void DisplayRoutingTable() {

		for (int x = 0; x < NumberOfMachines; x++) {

			cout << "********** Finalized Routing Table of Node " << Machines.getatindex(x).id << endl;

			for (int k = 0; k < bits; k++)
			{
				cout << "Row : " << k + 1 << "    Jumping Machine Id  :" << Machines.getatindex(x).checkMachine->Route.getAt(k).JumpPtr->id << endl;
			}

			cout << endl;




		}



	}

	int indexResponsible(long double id) {
	
		for (int i = 0; i < NumberOfMachines; i++) {
			if (Machines.getatindex(i).id == id) {
				return i;
			}
		
		}
		return -1;

	}

};