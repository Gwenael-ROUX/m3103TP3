#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"


template <typename T>
class CList
{
private:
    std::shared_ptr <CNode<T>> m_fictionalHead;
    std::shared_ptr <CNode<T>> m_fictionalTail;

public:
    CList ();
    ~CList ();
    void Show () const;
    std::shared_ptr <CNode<T>> Find (const T & val) const;
    void Delete (std::shared_ptr <CNode<T>>);
    void push_front (const T & val);
};

template <typename T>
CList<T>::CList () : m_fictionalHead (new CNode<T> ()), m_fictionalTail (new CNode<T> ()) {
    m_fictionalTail->SetPrevNode (m_fictionalHead);
    m_fictionalHead->SetNextNode (m_fictionalTail);
}

template <typename T>
CList<T>::~CList ()
{

}

template <typename T>
std::shared_ptr <CNode<T>> CList<T>::Find (const T & val) const
{
    std::shared_ptr <CNode<T>> Ptr (m_fictionalHead->GetNextNode ());
    for (; Ptr != m_fictionalTail && Ptr -> GetData () != val ; Ptr = Ptr->GetNextNode ());
    Ptr ->GetNextNode() ->SetPrevNode (Ptr ->GetPrevNode());
    Ptr ->GetPrevNode() ->SetNextNode (Ptr ->GetNextNode());
    Ptr ->SetPrevNode (m_fictionalHead);
    Ptr ->SetNextNode (m_fictionalHead ->GetNextNode());
    Ptr ->GetNextNode() ->SetPrevNode (Ptr);
    m_fictionalHead ->SetNextNode(Ptr);
    return (Ptr == m_fictionalTail ? nullptr : Ptr);
}

template <typename T>
void CList<T>::Show () const
{
    for (std::shared_ptr<CNode<T>> Ptr (m_fictionalHead -> GetNextNode()); Ptr != m_fictionalTail; Ptr = Ptr->GetNextNode ())
            std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (std::shared_ptr <CNode<T>> pDelete)
{
    pDelete ->GetPrevNode() ->SetNextNode (pDelete ->GetNextNode());
    pDelete ->GetNextNode() ->SetPrevNode (pDelete ->GetPrevNode());
    pDelete -> SetNextNode (nullptr);
    pDelete -> SetPrevNode (nullptr);
    pDelete.reset();
}

template <typename T>
void CList<T>::push_front (const T & val)
{
    std::shared_ptr<CNode<T>> tmp (new CNode<T> (val, m_fictionalHead, m_fictionalHead-> GetNextNode()));
    tmp -> GetNextNode() -> SetPrevNode(tmp);
    m_fictionalHead -> SetNextNode(tmp);
}

#endif // LIST_HPP
