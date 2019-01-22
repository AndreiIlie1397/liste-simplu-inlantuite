#include <iostream>
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
    nod *next;
};
nod *prim, *ultim;
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
void suma()
{
    int i;
    nod1 *p=prim1;
    nod2 *q=prim2;
    for(i=1; i<=nr; i++)
    {
        if(prim==NULL)
        {
            prim=new nod;
            prim->inf=p->inf1+q->inf2;
            prim->next=0;
            ultim=prim;
        }
        else
        {
            p=p->next1;
            q=q->next2;
            nod *c;
            c=new nod;
            c->inf=p->inf1+q->inf2;
            ultim->next=c;
            ultim=c;
            ultim->next=0;
        }
    }
}
void afisare()
{
    nod *sum=prim;
    while(sum->next!=NULL)
    {
        if(sum->next->inf>9)
        {
            sum->next->inf=sum->next->inf%10;
            sum->inf=sum->inf+1;
        }
        cout<<sum->inf;
        sum=sum->next;
    }
    cout<<ultim->inf%10;
    cout<<endl;
}
int main()
{
    cout<<"Suma a doua numere mari"<<endl<<endl;
    cout<<"Introduceti numarul de noduri pentru primul numar: ";
    cin>>nr;
    creare1(nr);
    cout<<"Introduceti numarul de noduri pentru al doilea numar: ";
    cin>>nr;
    creare2(nr);
    suma();
    afisare();
}
