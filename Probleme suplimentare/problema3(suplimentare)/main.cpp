#include <iostream>

using namespace std;
struct nod
{
    float inf;
    nod *next;
};
nod  *prim, *ultim;
int nr;
void creare_adaugare(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(prim==NULL)
        {
            prim=new nod;
            cout<<"Valoarea de adaugat in lista: ";
            cin>>prim->inf;
            prim->next=0;
            ultim=prim;                                                                                                                                                               //            si ultimul
        }
        else
        {
            nod *c;
            c=new nod;
            cout<<"Valoarea de adaugat in lista: ";
            cin>>c->inf;
            ultim->next=c;
            ultim=c;
            ultim->next=0;
        }
    }
}
void medie()
{
    nod *p=prim, *q, *ma;
    while(p->next!=NULL)
    {
        q=p->next;
        ma=new nod;
        ma->inf=(p->inf+q->inf)/2;
        ma->next=p->next;
        p->next=ma;
        p=q;
    }
}
void afisare()
{
    nod *p=prim;
    while(p)
    {
        cout<<p->inf<<"   ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    cout<<"Introduceti numarul de noduri: ";
    cin>>nr;
    creare_adaugare(nr);
    medie();
    afisare();
    return 0;
}
