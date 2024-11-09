#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct node {
    int cof, exp;
    struct node* next;
};
typedef struct node term;
//term* start = NULL;

// Function to create a new node

term* getnode(int c,int e) {
    term* temp = new term;
    temp->cof=c;
    temp->exp=e;
    temp->next = NULL;
    return temp;
}

// Function to create a polynomial

term* createpoly(term* p) {
    term* temp;
    term* newnode;
    char ch;
    while (1) {
        cout << "DO YOU WANT TO ADD THE TERMS (y/n): ";
        cin >> ch;
        if (ch == 'n')
            break;
        int c,e;
        cout<<"Enter the cofficient\t: ";
        cin>>c;
        cout<<"Enter the Exponent\t: ";
        cin>>e;        
        newnode = getnode(c,e);
        if (p == NULL) {
            p = newnode;
        } else {
            temp = p;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    return p;
}

// Function to display the polynomial

void display(term* p) {
    term* temp = p;
    while (temp != NULL) {
        cout << (temp->cof > 0 && temp != p ? "+" : "") 
             << temp->cof << "x^" << temp->exp << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to add two polynomials

void addpoly(term* t1, term* t2) {
    cout << "Additon of given two Polynomial = ";
    while (t1 != NULL && t2 != NULL) {
        if (t1->exp == t2->exp) {
            cout << "+" << t1->cof + t2->cof << "x^" << t1->exp << " ";
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->exp > t2->exp) {
            cout << "+" << t1->cof << "x^" << t1->exp << " ";
            t1 = t1->next;
        } else {
            cout << "+" << t2->cof << "x^" << t2->exp << " ";
            t2 = t2->next;
        }
    }

    // If any terms remain in the first polynomial
    
    while (t1 != NULL) {
        cout << "+" << t1->cof << "x^" << t1->exp << " ";
        t1 = t1->next;
    }

    // If any terms remain in the second polynomial
    
    while (t2 != NULL) {
        cout << "+" << t2->cof << "x^" << t2->exp << " ";
        t2 = t2->next;
    }
    cout << endl;
}
// Function to sub two polynomials

void subpoly(term* t1, term* t2) {
    cout << "subtraction of given two Polynomial = ";
    while (t1 != NULL && t2 != NULL) {
        if (t1->exp == t2->exp) {
            cout << "+ " << t1->cof - t2->cof << "x^" << t1->exp << " ";
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->exp > t2->exp) {
            cout << "+ " << t1->cof << "x^" << t1->exp << " ";
            t1 = t1->next;
        } else {
            cout << "+ " << t2->cof << "x^" << t2->exp << " ";
            t2 = t2->next;
        }
    }

    // If any terms remain in the first polynomial
    
    while (t1 != NULL) {
        cout << "+ " << t1->cof << "x^" << t1->exp << " ";
        t1 = t1->next;
    }

    // If any terms remain in the second polynomial
    
    while (t2 != NULL) {
        cout << "+ " << t2->cof << "x^" << t2->exp << " ";
        t2 = t2->next;
    }
    cout << endl;
}

// Code to multiply two Polynomial
term* mulpoly(term *P1,term *P2)
{
  term *C,*start,*A,*B,*New;
  start=NULL;
  A=P1;
  B=P2;
  while(A!=NULL)
  { C=NULL;
     while(B!=NULL)
     {
     C=getnode(A->cof*B->cof,A->exp+B->exp);
     if(start==NULL)
     {
       start=C;
     }
     else{
               New=start;
               while(New->next!=NULL)
               {
               	New=New->next;
               }
               New->next=C;
               New=New->next;
     }
     B=B->next;
     }
     A=A->next;
     B=P2;
  }
  return start;  
}

int main() 
{
    term* p1 = NULL;
    term* p2 = NULL;
    // Create two polynomials
    
    cout << "ENTER FIRST POLYNOMIAL\n";
    p1 = createpoly(p1);
    
    cout << "ENTER SECOND POLYNOMIAL\n";
    p2 = createpoly(p2);

    // Display the polynomials
    
    cout << "\nFirst polynomial = ";
    display(p1);
    cout<<endl;
    cout << "\nSecond polynomial = ";
    display(p2);
    cout<<endl;
    cout<<endl;
    //Operation on polynomial
    
    int ch;
    char c;
    do{cout<<"---------Choice Menu--------- \n";
       cout<<"Press 1 for Add two polynomial\n";
       cout<<"Press 2 for Subtract two polynomial \n";
       cout<<"Press 3 for Multiply two polynomial\n";
       cout<<"Press 4 for exit\n";
       cout<<"Enter your Choice\n";
       cin>>ch;
       switch(ch)
       {
        case 1:addpoly(p1,p2);
             break;
        case 2:subpoly(p1,p2);
             break;
        case 3:
        cout<<"The Multiplied Polynomial is :  ";
              display(mulpoly(p1,p2));
              break;
        case 4: exit(0);
        default :cout<<"Invalid Choice\n";
         }
         cout<<"Do you want to perform another operation on Polynomial(Y \ N)\n";
         cin>>c;
       }while(c=='y'||c=='Y');
     
     }

