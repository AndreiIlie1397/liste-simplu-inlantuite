#include <iostream>
#include <math.h>
using namespace std;
struct nod1
{
    int inf1;
    nod1 *next1;
};
nod1  *prim1, *ultim1, *p;
struct nod2
{
    int inf2;
    nod2 *next2;
};
nod2  *prim2, *ultim2, *q;
struct nod
{
    int inf;
    nod *next, *prev;
};
nod *prim, *ultim, *r;
int nr;
void creare1(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(prim1==NULL)
        {
            prim1=new nod1;
            cout<<"Valoarea de adaugat in lista: ";
            cin>>prim1->inf1;
            prim1->next1=0;
            ultim1=prim1;                                                                                                                                                               //            si ultimul
        }
        else
        {
            nod1 *c;
            c=new nod1;
            cout<<"Valoarea de adaugat in lista: ";
            cin>>c->inf1;
            ultim1->next1=c;
            ultim1=c;
            ultim1->next1=0;
        }
    }
}
void creare2(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(prim2==NULL)
        {
            prim2=new nod2;
            cout<<"Valoarea de adaugat in lista: ";
            cin>>prim2->inf2;
            prim2->next2=0;
            ultim2=prim2;                                                                                                                                                               //            si ultimul
        }
        else
        {
            nod2 *c;
            c=new nod2;
            cout<<"Valoarea de adaugat in lista: ";
            cin>>c->inf2;
            ultim2->next2=c;
            ultim2=c;
            ultim2->next2=0;
        }
    }
}
void creare(long double C)
{
    prim=new nod;
if(fmod(C, 10)==9)
        C=C+1;
    if(fmod(C, 10)!=8)
    C=C/10;
    prim->inf=C;
    prim->next=0;
    ultim=prim;
}
void produs()
{
    long double a=0, b=0, c;
    int x=0, y=0;
    nod1 *p=prim1;
    nod2 *q=prim2;
    while(p)
    {
        x=x+1;
        a=a*10+p->inf1;
        p=p->next1;
    }
    while(q)
    {
        y=y+1;
        b=b*10+q->inf2;
        q=q->next2;
    }
    if(x>=y)
    {
        for(int i=1; i<=x; i++)
        {
            c=fmod(a,10)*b*pow(10,i);
            a=a/10;
        }
    }
    else
    {
        for(int i=1; i<=y; i++)
        {
            c=a*pow(10,i)*fmod(b,10);
            b=b/10;
        }
    }
    creare(c+1);
}
void afisare()
{
    nod *p=prim;
    while(p)
    {
        cout<<p->inf;
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    cout<<"Produsul a doua numere mari"<<endl<<endl;
    cout<<"Introduceti numarul de noduri pentru primul numar: ";
    cin>>nr;
    creare1(nr);
    cout<<"Introduceti numarul de noduri pentru al doilea numar: ";
    cin>>nr;
    creare2(nr);
    produs();
    afisare();
    return 0;
}
