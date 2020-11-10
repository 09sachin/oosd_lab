#include<iostream>
#include<math.h>

using namespace std;

class point{
    public:
    float x;
    float y;
}; // vertex of polygon

class node{
    public:
    point data;
    node * next;
    node * prev;

}; //doubly linked list node


//doubly linked list
class linked_list {

private:
node * head;
node * tail;

public:
void add_back(point a); //add a vertex at back of linked list
void add_front(point a); //add a vertex at front of linked list
void del_front(); // delete a vertex of polygon stored in linked list from front(i.e first vertex)
void del_back(); // delete a vertex of polygon stored in linked list from front(i.e last vertex)
void del_index(int a); // delete a vertex of polygon at given index 
int length(); //number of vertex in polygon
point get_value_at_index(int a); //return vertex at requested index
void print_list(); // print all vertices
int search(point a);  // search vertex in polygon and return its index


linked_list(){
    head = NULL;
    tail = NULL;

} // empty linked list constructor

};

//add front function defination
void linked_list::add_front(point a){
    node * link = new node;

    (link->data).x = a.x;
    (link->data).y = a.y; // add data of x and y coordinate
    link->next = head;
    link->prev = NULL;

    if (head!=NULL){
    head->prev = link;
    }

    if(head == NULL){
        tail = link;
    }

    head = link; //new head

};

//add back function defination
void linked_list::add_back(point a){
    node * link = new node;
    
    (link->data).x = a.x;
    (link->data).y = a.y; // add data of  and y

    if (head==NULL){
        link->next = NULL;
        link->prev = NULL;
        head = link;
        tail = link;
    } // update head in case of empty list

    else if (head!=NULL and head==tail){
        head->next = link;
        link->prev = head;
        tail = link;
    } // single element list case
    
    else{
        tail->next = link;
        link->prev = tail;
        tail = link;
    } // update just tail of linked list

    link->next = NULL;
    
};

//delete front function defination
void linked_list:: del_front(){
    if (head==NULL){
        cout << "Empty list\n"; // nempty list
    }
    else if(head!=NULL and head==tail){
        delete head;
        cout << "Full list deleted\n";
        head= NULL;
    }// all delete
    else{
    head = head->next;
    delete head->prev;
    head->prev= NULL; 
    }
}

//delete back function defination
void linked_list:: del_back(){
   
    if (tail==NULL){
    }

    else if (tail->prev==NULL){
	tail = NULL;
    }

    else{
	tail = tail -> prev;
	delete (tail->next);
	tail->next = NULL;
   }
}

//delete at an index function defination
void linked_list :: del_index(int a){
    node * find = head;
    int count=0;

    while(find!=NULL){
        if(a==0){
            del_front();//if we need to delete first element
            break;
        }
        if(count == a){
            // delete from inner of list
            (find->prev)->next = find->next;
            if(find->next==NULL){
                tail = find->prev; //case of deleting last element
            }
            delete find;
           
            break;
        }
         count ++;
        find = find->next;
    }
    
}

//print list
void linked_list :: print_list(){
    node * current  = head;

    while(current!=NULL){
        cout << "(" <<(current->data).x <<","<< (current->data).y << ")" << endl;
        current = current->next;
    }
}

//find lenght
int linked_list :: length(){
    node * current  = head;
    int count = 0;

    while(current!=NULL){
        count++;//increase lenght till NULL
        current = current->next;
    }

    return count;//return count

}

//get values at requested index
point linked_list :: get_value_at_index(int a){
    node * current  = head;
    int count = 0;

    while(current!=NULL){
        //linear time seaching
        if(count==a){
            return current->data;
        }
        count++;
        current = current->next;
    }

    return head->data; //return data of requested index(i.e. x and y)

}

//linear seach function O(n) time here
int linked_list :: search(point a){
    node * current  = head;
    int count = 0;
//linear seaching to match data and return index where it matched data
    while(current!=NULL){
        if((current->data).x == a.x and (current->data).y == a.y){

            break;
        }
        current = current->next;
        count ++ ;
    }
    return count;
}

//triangulate function by ear clipping algorithm
void triangulate(linked_list ls);

//area of triangle 
// a helper function to find if point is inside a triangle  or not
float area(point a, point b, point c) ;

// check requested point p is inside triangle or not
//O(n) time
bool isInside(point a, point b, point c, point p) ;

//To check a vertex is reflex or convex
//constant time
float angle(point v1, point v2, point v3);

int main(){

linked_list ls; //polygon

ls.add_front({0,0});
ls.add_back({0,2});
ls.add_back({1,1});
ls.add_back({2,2});
ls.add_back({2,0});
//a polygon
//given polygon is of this type
//
//      |\    /|
//      | \  / |
//      |  \/  |
//      |      |
//      |______|

triangulate(ls); //triangulate

return 0;

}

//function defination of triangulation
void triangulate(linked_list ls){

linked_list copy; // make of copy of polygon linked list

int length  = ls.length(); //length

for (int i = 0; i < length; i++)
{
    copy.add_back(ls.get_value_at_index(i)); //making copy of initial ls linked list
}

    if(length<3){
        cout << "Not a polygon";
    }
    else if(length==3){
        cout << "already triangle";
    }

    else{
        for (int i = 0; i < ls.length(); i++)
        {
           int a,b,c;
           a = i-1;
           b= i;
           c= i+1;
           // for looping circular over polygon
           if(a==-1){
               a = ls.length()-1; // to make sure -1 is last vertex of polygon
           }
           if(c == ls.length()){
               c = 0; //to make last+1 vetrex as first vertex of polygon
           }
           
      // first check that vetex is convex
           if(angle(ls.get_value_at_index(a),ls.get_value_at_index(b),ls.get_value_at_index(c))==-1 ){
               
               int count =0;
             
               if(ls.length()==3){
                   break; // stop when it is final triangle
               }
               //again looping over remaining vertex to make sure the vertex is not inside new polygon
               for (int i = 0; i < ls.length(); i++)
               { 
                   if(i!=a and i!=b and i!=c){
                       // if point is inside new polygon increase count
                    if(isInside(ls.get_value_at_index(a),ls.get_value_at_index(b),ls.get_value_at_index(c),ls.get_value_at_index(i))){
                    count++;
                   }
                   }
               }
               // if count is zero than vertex under consideration is an ear and need to be clipped
               if(count==0){
                int ind =  copy.search(ls.get_value_at_index(b)); // search in copied list
                
                //cout << ind;
                int first,second;
                first = ind -1;
                if(first==-1){
                    first = copy.length()-1;
                }
                
                second = ind+1;
                if(second==copy.length()){
                    second = 0;
                }
                cout << "(" << first <<","<< second <<")"<<endl; //triangulated diagonal

                   ls.del_index(b); // delete ear and new polygon is formed
               }
               
           }
         }
        
    }
}


//area of triangle
float area(point a, point b, point c) 
{ 
    float x1 = a.x;
    float x2 = b.x;
    float x3 = c.x;
    float y1 = a.y;
    float y2 = b.y;
    float y3 = c.y;
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 

// check point p is insdie triangle abc or not
bool isInside(point a, point b, point c, point p) 
{
   /* Calculate area of triangle ABC */
   float A = area (a,b,c); 
  
   /* Calculate area of triangle PBC */   
   float A1 = area (p,b,c); 
  
   /* Calculate area of triangle PAC */   
   float A2 = area (p,a,c); 
  
   /* Calculate area of triangle PAB */    
   float A3 = area (p,a,b); 
    
   /* Check if sum of A1, A2 and A3 is same as A */ 
   return (A == A1 + A2 + A3); 
} 

//to check nature of vertex
float angle(point a, point b, point c){

   float val;

   val = (b.x-a.x)*(c.y-b.y) -(c.x-b.x)*(b.y-a.y); //to check that vertex is convex or not

   if (val<0){
       return -1; //convex
   }
   else if(val==0){
       return 0; // online
   }
   else{
       return 1; //reflex
   }
}
