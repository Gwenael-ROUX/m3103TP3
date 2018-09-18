#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"


template <typename T>
class CList
{
private:
    std::shared_ptr <CNode<T>> m_fictionaHead;
    std::shared_ptr <CNode<T>> m_realTail;

public:
    CList ();
    ~CList ();
    void push_front (const T & val);
    void Show () const;
    std::shared_ptr <CNode<T>> Find (const T & val) const;
    void Delete (std::shared_ptr <CNode<T>>);
    void push_back (const T & val);
    std::shared_ptr <CNode<T>> Begin () const;
    void AddAfter (std::shared_ptr <CNode<T>>, const T & val);
};

template <typename T>
std::shared_ptr <CNode<T>> CList<T>::Begin () const
{
    return m_fictionaHead;
}

template <typename T>
void CList<T>::AddAfter (std::shared_ptr <CNode<T>> ptr, const T & val)
{
    std::shared_ptr<CNode<T>> ptr2 (new CNode<T> (val, ptr-> GetNextNode()));
    ptr -> SetNextNode (ptr2);
    if (ptr == m_realTail) m_realTail = ptr->GetNextNode ();
}

template <typename T>
CList<T>::CList () : m_fictionaHead (new CNode<T> ()), m_realTail (m_fictionaHead) {}

template <typename T>
CList<T>::~CList () {
    //delete m_fictionaHead;
}

template <typename T>
std::shared_ptr <CNode<T>> CList<T>::Find (const T & val) const
{
    std::shared_ptr <CNode<T>> Ptr (m_fictionaHead->GetNextNode ());
    for (; Ptr != nullptr && Ptr -> GetData () != val ; Ptr = Ptr->GetNextNode ());

    return Ptr;
}



template <typename T>
void CList<T>::push_front (const T & val)
{
    std::shared_ptr<CNode<T>> Ptr (new CNode<T> (val, m_fictionaHead->GetNextNode ()));
    m_fictionaHead->SetNextNode (Ptr);
    if (m_realTail == m_fictionaHead) m_realTail = m_fictionaHead->GetNextNode ();
}

template <typename T>
void CList<T>::Show () const
{
    //for (CNodeInt* Ptr (m_Head); Ptr; ++*Ptr)
    for (std::shared_ptr <CNode<T>> Ptr (m_fictionaHead -> GetNextNode()); Ptr; Ptr = Ptr->GetNextNode ())
            std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (std::shared_ptr <CNode<T>> pDelete)
{
    std::shared_ptr <CNode<T>> pFind (m_fictionaHead);
    for ( ; pFind -> GetNextNode () != pDelete ; pFind = pFind -> GetNextNode ());

    pFind -> SetNextNode (pDelete -> GetNextNode ());
    if (pDelete == m_realTail) m_realTail = pFind;
    pDelete -> SetNextNode (nullptr);

    //delete pDelete;
}

template <typename T>
void CList<T>::push_back (const T & val)
{
    std::shared_ptr <CNode<T>> pTmp (new CNode<T> (val, nullptr));
    m_realTail -> SetNextNode (pTmp);
    m_realTail = pTmp;
}


#endif // LIST_HPP
