#include <iostream>
#include <vector>
using namespace std;

class nod
{
public:
    int data;
    nod * next;
    nod()
    {
        data=0;
        next=NULL;

    }
    nod(int val)
    {
        data=val;
        next=NULL;

    }

    friend class Clist;
};
class Clist
{
public:
    nod *start,*last;
    Clist()
    {
        last=NULL;
        start=NULL;
    }
    void k_del(int k);
    void rev();
    void del_start();
    void print_list();
    void add_end(int val);
    friend ostream & operator << (ostream & out,const Clist & c);
    friend istream & operator >> (istream & in,Clist & c);
    friend Clist & operator + (Clist &x,Clist &y);
};
Clist newclist=Clist();
int main()
{
    int x,selected,k;
    Clist c[3];
    cout<<"MENIU"<<endl
        <<"(1)Selecteaza Lista 1-2-3 [1 default]"<<endl
        <<"(2)Adauga elemente in lista selectata -1 pt a termina inputul"<<endl
        <<"(3)Afiseaza elementele din lista selectata"<<endl
        <<"(4)Stergerea primului element din lista selectata"<<endl
        <<"(5)Inversarea ordini unei liste selectate"<<endl
        <<"(6)Eliminarea din K in K pasi [se ignora primul elem]"<<endl
        <<"(7)Adunarea celor doua liste [1,2] in lista cu numarul 3"<<endl
        <<"(8)exit "<<endl;
    while(true)
    {
        cout<<endl<<"|>";
        cin>>x;
        switch(x)
        {
        case 1 :
            cin>>selected;
            --selected;
            break;
        case 2 :
            cin>>c[selected];
            break;
        case 3 :
            cout<<c[selected];
            break;
        case 4 :
            c[selected].del_start();
            break;
        case 5 :
            c[selected].rev();
            break;
        case 6 :
            cout<<"cati pasi"<<endl;
            cin>>k;
            c[selected].k_del(k);
            break;
        case 7 :
            c[2]=c[0]+c[1];
            cout<<c[2]<<endl;
            break;
        default:
            return 0;
        }


    }


    return 0;
}
void Clist::print_list()
{
    nod * s;
    s=this->start;
    if(s==NULL)
    {
        cout<<"lista vida"<<endl;
        return;
    }
    else
    {
        cout<<s->data<<" ";
        s=s->next;
        while (s!=start)
        {

            cout<<s->data<<" ";
            s=s->next;
        }

    }
}
void Clist::add_end(int val)
{
    nod * p;
    p = new nod;
    nod * s;
    s = new nod;
    if(this->start==this->last && this->last==NULL )
    {
        p->data=val;
        this->start=p;
        this->last=p;
        this->last->next=this->start;
        this->start->next=p;

    }
    else
    {   vector <int> temp;
        s=this->start;
        temp.push_back(s->data);
        s=s->next;
        while (s!=this->start)
        {

            temp.push_back(s->data);
            s=s->next;
        }
        for(int i=0; i<temp.size(); i++)
            if(temp[i]==val)
        {

         cout<<"este deja in coada";
        return;
        }

        p->data=val;
        this->last->next=p;
        p->next=this->start;
        this->last=p;

    }


}
ostream & operator << (ostream & out,const Clist& c)
{
    nod * s;
    s=c.start;
    if(s==NULL)
    {
        out<<"lista vida";
        return out;
    }
    else
    {
        out<<s->data<<" ";
        s=s->next;
        while (s!=c.start)
        {

            out<<s->data<<" ";
            s=s->next;
        }

    }
    return out;

}
istream & operator >> (istream & in,Clist & c)
{
    int val;
    while(in>>val && val!=-1)
        c.add_end(val);

    return in;
}
void Clist::del_start()
{
    if(this->start==this->last && this->last==NULL)
    {
        cout<<"Nu am ce sa sterg!"<<endl;
        return;
    }
    else if (this->start==this->last)
    {
        this->start=NULL;
        this->last=NULL;
    }
    else

    {
        this->start=this->start->next;
        this->last->next=this->start;
    }
}
void Clist::rev()
{
    vector <int> temp;

    nod * s;
    s=this->start;
    if (s==NULL)
    {
        cout<<"Nu am ce sa inversez"<<endl;
        return;
    }
    else
    {
        temp.push_back(s->data);
        s=s->next;
        while (s!=this->start)
        {

            temp.push_back(s->data);
            s=s->next;
        }

    }

    this->start=this->last=NULL;
    for(int i=temp.size()-1; i>=0; i--)
        this->add_end(temp[i]);
}
void Clist::k_del(int k)
{

    nod * s=this->start;
    if(s==NULL)
    {
        cout<<"nu am ce sa sterg"<<endl;
        return;
    }
    else
    {
        while (s!=s->next)
        {
            for(int i=0; i<k-1; i++)
                s=s->next;
            cout<<"il sterg pe " <<s->next->data<<endl;
            s->next=s->next->next;


        }

    }
}
Clist & operator + (Clist &x,Clist &y)
{
    if(x.start==NULL && y.start!=NULL)
        return y;
    if(x.start!=NULL && y.start==NULL)
        return x;

    x.last->next=y.start;
    y.last->next=x.start;
    newclist.start=x.start;
    newclist.last=y.last;
    return newclist;
}
