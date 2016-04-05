#include"lista_circular.cpp"
using namespace std;

int main()
{
    CList *lista;
    lista = new CList;
    lista->addToHead(24);
    lista->addToTail(5);
    lista->addToTail(6);
    lista->addToTail(7);
    cout<<lista->head<<endl;
    cout<<lista->tail->next<<endl;
    cout<<lista->tail->next->info<<endl;

    //cout<<lista->deleteFromTail()<<endl;
}
