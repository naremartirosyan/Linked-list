#include <stdexcept>

template <typename T>
class Node
{
public:
   T Value;
   Node<T>* Pointer;
};

template <typename T>
class LinkedList
{
public:
   void InsertHead(T value);
   void Insert(int position, T value);
   void InsertTail(T value);
   T Get(int position);
   void Remove(int position);
   Node<T>* Head;
   int ElementCount = 0;

   class OutOfRangeException: public std::runtime_error
   {
      public:
      OutOfRangeException(std::string msg): std::runtime_error(msg) {}
   };
};

template <typename T>
void LinkedList<T>::InsertHead(T value)
{
   Node<T>* Node_0 = new Node<T>; 
   Node_0->Pointer = Head;
   ElementCount++;
   Node_0->Value = value;
   Head = Node_0;
}

template <typename T>
T LinkedList<T>::Get(int position)
{
   if(position > ElementCount - 1)
   {
      throw(LinkedList::OutOfRangeException("An element with such position does not exist."));
   }

   Node<T>* Temp = Head;
   while(position > 0)
   {
      Temp = Temp->Pointer;
      position--;
   }
   return Temp->Value;
}

template <typename T>
void LinkedList<T>::Insert(int position, T value)
{
   if(position > ElementCount)
   {
      throw(LinkedList::OutOfRangeException("Can't insert an element there."));
   }

   Node<T>* Node_1 = new Node<T>; 
   ElementCount++;
   Node_1->Value = value;

   Node<T>* Temp = Head;
   while(position > 1)
   {
      Temp = Temp->Pointer;
      position--;
   }
   Temp->Pointer = Node_1;
}
 
template <typename T>
void LinkedList<T>::InsertTail(T value)
{
   Node<T>* Tail = new Node<T>; 
   ElementCount++;
   Tail->Value = value;
   Tail->Pointer = nullptr;

   Node<T>* Temp = Head;
   int position = 1;
   while(position < ElementCount - 1)
   {
      Temp = Temp->Pointer;
      position++;
   }
   Temp->Pointer = Tail;
}

template <typename T>
void LinkedList<T>::Remove(int position)
{
   if(position > ElementCount)
   {
      throw(LinkedList::OutOfRangeException("No element in that position."));
   }

   Node<T>* Temp = Head;
   while(position > 1)
   {
      Temp = Temp->Pointer;
      position--;
   }
   Temp->Pointer = Temp->Pointer->Pointer;

   ElementCount--;
}