#include <iostream>
#include "node.hpp"
#include "list.hpp"
using namespace std;


void ListeSimple (void)
{
    std::cout << "ListeSimple : \n\n";

    shared_ptr <CNode <int>> Tete;

    // Le dernier element cree est toujours le premier de la liste


    for (unsigned i (0); i < 5; ) {
        shared_ptr <CNode<int>> tmp ( new CNode<int> (i++, Tete));
        Tete = tmp;
        std::cout << Tete << endl;
    }

    for (shared_ptr <CNode <int>> Ptr (Tete); Ptr; Ptr = Ptr->GetNextNode ())
        std::cout << Ptr->GetData() << "; ";

    std::cout << '\n';

    // Dans cette version, le destructeur de C1Link detruit son
    //   suivant donc la destruction de la liste est recursive

    //delete Tete;

}// ListeSimple ()


void ListeSimpleV2 ()
{
    cout << "ListeSimpleV2 : \n\n";

    CList<int> AList;

    // Le dernier element cree est toujours le premier de la liste

    for (unsigned i = 20; i; i -= 2) AList.AddAfter (AList.Begin (), i);
    cout << "hfejkrhg " << endl;

    for (unsigned i (0); i < 5; ) {
        AList.push_front (i++);
    }



    AList.Show ();
//	AList.Show ();
/*	int i;
    cin >>i;
    CNodeInt* ptr = AList.Find (i);
    AList.Add (3*i, ptr);
    AList.Show ();

    cout << ((ptr != NULL)?  " " : "non ") << "trouve" << endl;
*/
    //cout << "valeur trouvée" << ptr -> GetData () << endl;

    //delete AList;

    /*CNodeInt* ptr = AList.Find (2);
    cout << ((ptr != NULL)?  " " : "non ") << "trouve" << endl;
    AList.Delete (ptr);
    AList.Show ();*/

    //AList.Delete (AList.Find (0));

    AList.push_back (6);
    AList.push_back (7);


    AList.Delete (AList.Find (2));
    AList.Delete (AList.Find (12));
    AList.Delete (AList.Find (20));
    AList.Show ();
    //delete ptr;
    cout << endl;

}

int main()
{
    std::cout << "Hello World!" << std::endl;
    ListeSimple();
    ListeSimpleV2 ();
    return 0;
}
