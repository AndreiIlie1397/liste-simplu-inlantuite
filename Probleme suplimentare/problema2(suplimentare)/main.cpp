#include <iostream>

using namespace std;
struct nod
{
    int inf;
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
void elemente()
{
    nod *p=prim;
    int i=0, j=0, x=0;
    float ma;
    while(p)
    {
        if(p->inf%2==0)
            i++;
            else
            {
                x=x+p->inf;
               j++;
            }
        p=p->next;
    }
    ma=(float)x/j;
    cout<<"Sunt "<<i<<" elemente pare";
    cout<<endl;
    cout<<"Media aritmetica a elementelor impare este "<<ma;
    cout<<endl;
}
void afisare()
{
    nod *p=prim;
    while(p)
    {
        cout<<p->inf<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    cout<<"Introduceti numarul de noduri: ";
    cin>>nr;
    creare_adaugare(nr);
    afisare();
    elemente();
}
