#include"ListaEnlazada.cpp"

Nodo * combinar_listas(ListaEnlazada *L1,ListaEnlazada *L2)
{
    Nodo *t1,*t2,*H;
    if(L1->cabeza==nullptr and L2->cabeza==nullptr)
    {
        cout<<"Las listas estan vacias"<<endl;
    }
    else
    {
        t1 = L1->cabeza;
        t2 = L2->cabeza;

        if (t1->num<t2->num)
            H = L1->cabeza;
        else
            H = L2->cabeza;

        Nodo *A = H;
        cout<<H->num<<endl;

        while(t1!=nullptr and t2!=nullptr)
        {
            //cout<<t1<<" "<<t2<<endl;
            if(t1==nullptr or t2==nullptr)
                return A;

            if(t1->num <= t2->num)
            {
                t1 = t1->next;
                H->next=t2;
                H = H->next;
                cout<<H->num<<endl;
            }

            //cout<<t1<<" "<<t2<<endl;
            if(t1==nullptr or t2==nullptr)
                return A;
            if(t2->num <= t1->num)
            {
                t2 = t2->next;
                H->next=t1;
                H=H->next;
                cout<<H->num<<endl;
            }
            //cout<<t1<<" "<<t2<<endl;
            if(t1==nullptr or t2==nullptr)
                return A;

        }
    }
}


int main()
{
    ListaEnlazada *A;
    A = new ListaEnlazada;
    A->agrCabeza(12);
    A->agrCabeza(5);
    A->agrCabeza(1);

    cout<<"DIRECCIONES LISTA A: "<<endl;
    cout<<A->cabeza<<" "<<endl;
    cout<<A->cabeza->next<<endl;
    cout<<A->cabeza->next->next<<endl;

    ListaEnlazada *B;
    B = new ListaEnlazada;
    B->agrCabeza(19);
    B->agrCabeza(8);
    B->agrCabeza(2);

    cout<<"DIRECCIONES LISTA B: "<<endl;
    cout<<B->cabeza<<endl;
    cout<<B->cabeza->next<<endl;
    cout<<B->cabeza->next->next<<endl;


    Nodo *EZ = combinar_listas(A,B);
    cout<<"Nueva Lista: "<<endl;
    while (EZ!=nullptr)
    {
        cout<<"Direccion: "<<EZ<<" "<<EZ->num<<endl;
        EZ = EZ->next;
    }
    return 0;
}
