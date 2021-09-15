#include<iostream>
#include "sha1.h"
#include "Header.h"
#include<GL/glut.h>
#include<GL/GLU.h>
#include<GL/GL.h>
#include "util.cpp"
using namespace std;
/*Three variables just to control the visualization of Tree Data structure in graphics mode*/
/*When user input to display visuals of tree data structure of Specfied machine then everything stops and program just display the visuals*/
/*Press b pr B to stop visualization */
bool visualizationMode = false;
long double machineid = -1;
struct Coords//Just to store Coordinates to create Edges between Root and child nodes,Simply we can use it to store coordinates of line
{
    int Node1;
    int Node2;
    int x1;
    int y1;
    int x2;
    int y2;
    Coords()
    {
        x1 = -1;
        y1 = -1;
        x2 = -1;
        y2 = -1;
        Node1 = -1;
        Node2 = -1;
    }
};
void renderBitmapString(float x, float y, const char* chars)//This function takes coordinates and print string using glutBitmapCharacter
{
    const char* c;
    glRasterPos2f(x, y);
    for (c = chars; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }
}

/*To draw Tree Node at specified location with specified key value*/
void DrawTreeNode(int sx, int sy, int radius, int key)
{
    DrawCircle(sx, sy, radius + 2, colors[BLACK]);
    DrawCircle(sx, sy, radius, colors[RED]);
    string s = to_string(key);
    const char* a = s.c_str();
    DrawString(sx, sy, "", colors[BLACK]);
    renderBitmapString(sx - 13, sy - 5, a);
}
void AVLTree::BREADTH_FIRST_TRAVERSAL_PRINT()//This function Draw Tree Data structure and representing Edges between parent-childs
{
    DoublyLinkedList<bool> NodeChecks;
    int sy = 810;
    int sx = 1024 / 2;
    int radius = 15;
    Queue<AVLNode*, int> Visited;
    AVLNode* Curr = root;
    int nodes = 0;
    int levels = 0;
    DoublyLinkedList<int> KeyList;
    DoublyLinkedList<int> RealtiveRootKey;
    DoublyLinkedList<int> Edges_Coords;
    if (root != NULL)
    {

        int x = Curr->height;
        NodeChecks.insert(true);
        KeyList.insert(Curr->key);
        RealtiveRootKey.insert(-1);
        RealtiveRootKey.insert(Curr->key);
        RealtiveRootKey.insert(Curr->key);
        nodes = 0;
        levels = 1;
        do
        {
            if (Curr->left != NULL)
            {
                RealtiveRootKey.insert(Curr->left->key);
                RealtiveRootKey.insert(Curr->left->key);
                NodeChecks.insert(true);
                KeyList.insert(Curr->left->key);
                Visited.enqueue(Curr->left);
            }
            else
            {
                RealtiveRootKey.insert(-1);
                RealtiveRootKey.insert(-1);
                KeyList.insert(-1);
                NodeChecks.insert(false);
            }
            if (Curr->right != NULL)
            {
                RealtiveRootKey.insert(Curr->right->key);
                RealtiveRootKey.insert(Curr->right->key);
                KeyList.insert(Curr->right->key);
                NodeChecks.insert(true);
                Visited.enqueue(Curr->right);
            }
            else
            {
                RealtiveRootKey.insert(-1);
                RealtiveRootKey.insert(-1);
                KeyList.insert(-1);
                NodeChecks.insert(false);
            }
            nodes += 2;
            if (pow(2, levels) == nodes)
            {
                levels++;
                nodes = 0;
            }
            Curr = Visited.dequeue();
        } while (!Visited.is_empty());
    }
    int nodeIds = 0;
    int backSpace = 0;
    int nodecount = 0;
    int spaceWid = 50;
    DoublyLinkedList<int> KeyCoord;
    DoublyLinkedList<int> XCoords;
    DoublyLinkedList<int> YCoords;
    DoublyLinkedList<Coords> Edges;
    for (int i = 0; i < NodeChecks.getElements(); i++)
    {
        if (NodeChecks.getAt(i) && KeyList.getAt(i) != -1)
        {
            DrawTreeNode(sx - backSpace, sy, radius, KeyList.getAt(i));
            string x = to_string(RealtiveRootKey.getAt(i));
            const char* a = x.c_str();
            //DrawString(sx - backSpace, sy, "", colors[BLACK]);
            //renderBitmapString(sx - backSpace, sy,a);

            Coords* EdgeAxis = new Coords;
            if (!KeyCoord.isEmpty())
            {
                int idx = KeyCoord.Search(RealtiveRootKey.getAt(i));
                cout << RealtiveRootKey.getAt(i) << endl;
                //cout << idx << endl;
                {
                    EdgeAxis->Node1 = RealtiveRootKey.getAt(i);
                   
                    EdgeAxis->x1 = XCoords.getAt(idx);
                    EdgeAxis->y1 = YCoords.getAt(idx);
                    EdgeAxis->Node2 = KeyCoord.getAt(i);
                    EdgeAxis->x2 = sx - backSpace;
                    EdgeAxis->y2 = sy;
                }
                Edges.insert(*EdgeAxis);
                KeyCoord.insert(KeyList.getAt(i));
                XCoords.insert(sx - backSpace);
                YCoords.insert(sy);
            }
            else
            {
                KeyCoord.insert(KeyList.getAt(i));
                XCoords.insert(sx - backSpace);
                YCoords.insert(sy);
            }
            nodecount++;
            backSpace -= (spaceWid * 2);
        }
        else
        {

            nodecount++;
            backSpace -= (spaceWid * 2);
        }
        if (nodecount % 2 == 0)
        {
            backSpace += 2 * radius;
        }
        if (pow(2, nodeIds) == nodecount)
        {
            nodeIds++;
            nodecount = 0;
            sy -= 50;
            backSpace = nodeIds * spaceWid;
            spaceWid -= 5;
            radius -= 1;
        }
    }
    for (int i = 0; i < Edges.getElements(); i++)//This loops iterate and inside it,written program helps to create edges between childs and parents
    {
        int x1 = Edges.getAt(i).x1;
        int x2 = Edges.getAt(i).x2;
        int y1 = Edges.getAt(i).y1;
        int y2 = Edges.getAt(i).y2;
        int Node1 = Edges.getAt(i).Node1;
        int Node2 = Edges.getAt(i).Node2;
        if (Node1 != -1 && Node2 != -1 && x1 != -1 && x2 != -1 && y2 != -1 && y1 != -1)
            DrawLine(x1, y1 - 15, x2, y2 + 13, 4, colors[BLACK]);
    }
    cout << endl;
}
void SetCanvasSize(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void Run_Model()
{
    static bool initializer = true;
    int Bytes = 0, Number = 0;
    int choice;
    if (initializer)
    {
        cout << "Enter the Number of Bytes : ";
        cin >> Bytes;
        cout << "Enter the Number of Machines : ";
        cin >> Number;
        cout << "Do you want to Randomly Assign Machines ? (Press 0 for No ,Any Number for Yes)" << endl;
        cin >> choice;
        initializer = false;
    }
    static IdentifierSpace check(Number, choice, Bytes);
    system("cls");

    bool Exit = false;
    while (!Exit && !visualizationMode)
    {
        system("cls");
        int InputVar = -1;
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t----------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t                 Select Option From the Menu                     " << endl;
        cout << "\t\t\t\t\t\t----------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t1. Insertion in Machine" << endl;
        cout << "\t\t\t\t\t\t2. Deletion in Machine" << endl;
        cout << "\t\t\t\t\t\t3. Tree Visualization" << endl;
        cout << "\t\t\t\t\t\t4. Delete the Machine From Identifier Space" << endl;
        cout << "\t\t\t\t\t\t5. Insert the Machine in Identifier Space" << endl;
        cout << "\t\t\t\t\t\t6. Display Routing Tables" << endl;
        cout << "\t\t\t\t\t\t7. Exit" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\tEnter Input : ";
        cin >> InputVar;
        system("cls");
        if (InputVar == 7)
        {
            Exit = true;
            break;
        }
        else if (InputVar == 6)
        {
            check.DisplayRoutingTable();
        }
        else if (InputVar == 5)
        {
            long double newmachine = 0;
                cout << "Enter the Machine Id to be Inserted (-1 if you dont want to Insert) " << endl;
                cin >> newmachine;
                    check.InsertMachine(newmachine);
        }
        else if (InputVar == 4)
        {
            long double deletemachine = 0;
            cout << "Enter the Machine Id to be Deleted (-1 if you dont want to Delete) " << endl;
            cin >> deletemachine;
            if (deletemachine != -1) {
                check.RemoveTheMachine(deletemachine);
            }
        }
        else if (InputVar == 3)
        {
            visualizationMode = true;
            machineid = -1;
            while (machineid < 0)
            {
                cout << "Please Enter Machine ID : ";
                cin >> machineid;
                if (machineid < 0)
                {
                    cout << "Message : Input is not valid" << endl;
                }
            }
            break;
        }
        else if (InputVar == 2)
        {
            bool more = true;
            while (more)
            {
                cout << " DELETION " << endl;
                string a;
                more = false;
                long double c;
                cout << "Enter the Key :";
                cin >> a;
                cout << "Enter the Machine Id  That you want to Start the Deletion :";
                cin >> c;

                check.Delete(a, check.indexResponsible(c));

                char proc = '?';
                cout << "Do you Want to Enter More ?(0 for No and Any key for Yes)" << endl;
                cin >> proc;
                if (proc == '0')
                {
                    break;
                }
                else
                    more = true;
            }
        }
        else if (InputVar == 1)
        {
            bool more = true;
            while (more)
            {
                more = false;
                cout << " INSERTION " << endl;
                string a;
                string b;
                long double c;
                cin.ignore();
                cout << "Enter the Key :";
                getline(cin, a);
                cin.ignore();
                cout << "Enter the Value ";
                getline(cin, b);
                cin.ignore();
                cout << "Enter the Machine Id  That you want to Start the Insertion :";
                cin >> c;

                check.Insert(a, b, check.indexResponsible(c));
                cout << endl;
                char proc = '?';
                cout << "Do you Want to Enter More ?(0 for No and Any key for Yes)" << endl;
                cin >> proc;
                if (proc == '0')
                {
                    break;
                }
                else
                {
                    more = true;
                }
            }
        }
        else
        {
            cout << "Message : Input is not valid" << endl;
        }
        cin.ignore();
        cout << "Do you to proceed again?(Yes(Y for Main Menu) or No(N for Exit)) : ";
        char proc = '?';
        while ((proc != 'Y' && proc != 'y') && (proc != 'N' && proc != 'n'))
        {
            cin >> proc;
            if (((proc != 'Y' && proc != 'y') && (proc != 'N' && proc != 'n')))
            {
                cout << "Message : Incorrect Input" << endl;
                cout << "Enter Again : ";
            }
        }
        if (proc == 'N' || proc == 'n')
        {
            system("cls");
            cout << "Message : Bye Bye" << endl;
            break;
        }
    }
    if (visualizationMode == true)
    {
        check.Machines.getatindex(check.indexResponsible(machineid)).checkMachine->NodeData->BREADTH_FIRST_TRAVERSAL();
        check.Machines.getatindex(check.indexResponsible(machineid)).checkMachine->NodeData->BREADTH_FIRST_TRAVERSAL_PRINT();
    }
}
void Visualization() 
{
	
	glClearColor(0.529, 0.808, 0.92, 0.2);
	glClear(GL_COLOR_BUFFER_BIT); 
	
    Run_Model();

	glutSwapBuffers();
}
void PrintableKeys(unsigned char key, int x, int y)
{
	if (key == 27) 
    {
        exit(1);
	}
	if (key == 'b' || key == 'B')
	{
        visualizationMode = false;
        machineid = -1;

	}
	glutPostRedisplay();
}
void Timer(int m) 
{
	glutTimerFunc(1000.0, Timer, 0);
}

int main(int argc, char* argv[]) 
{
	int width = 1020, height = 840;
	InitRandomizer();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(width, height);
	glutCreateWindow("RING DHT"); 
	SetCanvasSize(width, height);
	glutDisplayFunc(Visualization);
	glutKeyboardFunc(PrintableKeys);
	glutTimerFunc(1000.0, Timer, 0);
	glutMainLoop();
	return 1;
}