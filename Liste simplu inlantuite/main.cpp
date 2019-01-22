#include<iostream>
using namespace std;
struct nod
{
    int inf;
    nod *next;
};
nod  *prim, *ultim;
int nr, val, val1, n;
int nrNoduri() ///calculeaza numarul de noduri
{
    int nr=0;
    nod *p=prim;
    while(p!=NULL)
    {
        p=p->next;
        nr++;
    }
    return nr;
}
int esteVida() ///verificare daca lista nu contine noduri
{
    return prim==NULL;
}
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
void afisare() ///afisare lista
{
    nod *p=prim;
    while(p)
    {
        cout<<p->inf<<" ";
        p=p->next;
    }
    cout<<endl;
}
void adaugaFinal(int x) ///adaugarea unui nod la finalul listei nod
{
    nod *p,*q=prim;
    if (esteVida())
        creare_adaugare(x);
    else
    {
        p=new nod;
        p->inf=x;
        p->next=NULL;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
    }
}
void adaugaInceput(int x)
{
    nod *p;
    if(esteVida())
        creare_adaugare(x);
    else
    {
        p=new nod;
        p->inf=x;
        p->next=prim;
        prim=p;
    }
}
void cauta(int x)
{
    nod *p=prim;
    int gasit=0, poz=0;
    while((p!=NULL)&&(!gasit))
    {
        if(p->inf==x)
            gasit=1;
        p=p->next;
        poz++;
    }
    if(gasit==0)
    {
        cout<<"Valoarea "<<x<<" nu se afla in lista";
        cout<<endl;
    }
    else
    {
        cout<<"Valoarea "<<x<<" se afla in lista pe pozitia "<<poz;
        cout<<endl;
    }
}
void cautaPozitie(int k) ///cauta nodul care se afla pe pozitia k
{
    nod *p=prim, *aux;
    int gasit=0, i;
    while((p!=NULL)&&(!gasit))
    {
        if(k==1)
        {
            gasit=1;
            cout<<"Pe pozitia 1 se afla elementul "<<prim->inf;
            cout<<endl;
        }
        else
        {
            p=prim;
            for(i=1; i<=k-2; i++)
                p=p->next;
            aux=p->next;
            cout<<"Pe pozitia "<<k<<" se afla elementul "<<aux->inf;
            cout<<endl;
            gasit=1;
        }
    }
}
void adaugaPePozitie(int k,int x) ///adaugare unui nod cu informatia x pe pozitia k
{
    int i;
    nod *p,*q=prim;
    if(k<=1)
        adaugaInceput(x);
    else if(k>nrNoduri())
        adaugaFinal(x);
    else
    {
        for(i=1; i<=k-2; i++)
            q=q->next;
        p=new nod;
        p->inf=x;
        p->next=q->next;
        q->next=p;
    }
}
void stergereNod(int x) ///sterge nodul x din lista
{
    if (prim->inf==x)
    {
        nod *aux=prim;
        prim =prim->next;
        delete aux;
    }
    else
    {
        nod *q = prim;
        while (q->next->inf != x)
            q = q->next;
        nod *aux = q->next;
        q->next = q->next->next;
        delete aux;
    }
}
void stergerePozitie(int k) ///sterge nodul care se afla pe pozitia k
{
    int i;
    nod *aux, *p;
    if(k==1)
    {
        aux=prim;
        prim=prim->next;
        delete aux;
    }
    else
    {
        p=prim;
        for(i=1; i<=k-2; i++)
            p=p->next;
        aux=p->next;
        p->next=aux->next;
        delete aux;
    }
}
void stergereAll() ///sterge toata lista
{
    nod *aux;
    while(prim!=NULL)
    {
        aux=prim;
        prim=prim->next;
        delete aux;
    }
    cout<<"Au fost sterse toate elementele";
}
int main()
{
    cout<<"Introduceti numarul de noduri: ";
    cin>>nr;
    creare_adaugare(nr);
    afisare();
    cout<<"Introduceti valoarea pe care doriti sa o introduceti la sfarsitul listei: ";
    cin>>n;
    adaugaFinal(n);
    afisare();
    cout<<"Introduceti valoarea pe care doriti sa o introduceti la inceputul listei: ";
    cin>>n;
    adaugaInceput(n);
    afisare();
    cout<<"Introduceti o valoare pe care doriti sa o introduceti in lista: ";
    cin>>val;
    cout<<"Introduceti pozitia pe care doriti sa se regaseasca acea valoare: ";
    cin>>val1;
    adaugaPePozitie(val1,val);
    afisare();
    cout<<"Introduceti un element pe care doriti sa il cautati in lista: ";
    cin>>val;
    cauta(val);
    cout<<"Introduceti pozitia elementului pe care doriti sa il cautati: ";
    cin>>val;
    cautaPozitie(val);
    cout<<"Introduceti un element pe care doriti sa il stergeti din lista: ";
    cin>>val;
    stergereNod(val);
    afisare();
    cout<<"Introduceti pozitia de pe care doriti sa stergeti elementul: ";
    cin>>val;
    stergerePozitie(val);
    afisare();
    stergereAll();
    afisare();
    return 0;
}
