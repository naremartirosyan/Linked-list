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
   Node<T>* Head = nullptr;
   int ElementCount = 0;
public:
   class Iterator
   {
      Node<T>* ptr;
   public:
      using iterator_category = std::forward_iterator_tag;
      using difference_type   = int;
      using value_type        = T;
      using pointer           = T*;  
      using reference         = T&;

      Iterator(Node<T>* ptr)
      {
         this->ptr = ptr;
      }

      T operator *() const
      {
         if(this->ptr == nullptr)
         {
            throw(LinkedList::OutOfRangeException("No elements there."));
         }
         return this->ptr->Value;
      }  

      T& operator *() 
      {
         if(this->ptr == nullptr)
         {
            throw(LinkedList::OutOfRangeException("No elements there."));
         }
         return this->ptr->Value;;
      } 

      Iterator& operator ++()
      {
         if(this->ptr == nullptr)
            {
               throw(LinkedList::OutOfRangeException("No elements there."));
            }
         this->ptr = this->ptr->Pointer;
         return *this;
      }

      bool operator !=(const Iterator& other) 
      {
         if(this->ptr == other.ptr)
         {
            return false;
         }
         else
         {
            return true;
         }
      }

   };

   Iterator begin()
   {
      Iterator Start(Head);
      return Start;
   }
   Iterator end()
   {
      Iterator End(nullptr);
      return End;
   }
   void InsertHead(T value);
   void Insert(int position, T value);
   void InsertTail(T value);
   void Remove(int position);
   T Get(int position) const;
   void ForEach(std::function<void(T&)> lambda);
   int GetSize() const
   {
      return ElementCount;
   }

   LinkedList() 
   {
      Head = nullptr;
      ElementCount = 0;
   }

   LinkedList(const LinkedList<T>& other) 
   {
      for(int i = 0; i < other.ElementCount; i++)
      {
         this->Insert(i, other.Get(i));
      }  
   }

   LinkedList(LinkedList<T>&& other) 
   {
      std::swap(other.Head, this->Head);
      std::swap(other.ElementCount, this->ElementCount);
   }

   ~LinkedList()
   {
      Node<T>* ptr1 = Head;
      if(ElementCount > 0)
      {
         Node<T>* ptr2 = Head->Pointer;
         for(int i = 0; i < ElementCount - 1; i++)
         {
            delete ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->Pointer;
         }
      }
      else
      {
         delete Head;
      }
   }
   
   LinkedList& operator =(const LinkedList<T>& other)
   {
      /*for(int i = 0; i < this->ElementCount; i++)
      {
         this->Remove(i);
      }
      for(int i = 0; i < other.ElementCount; i++)
      {
         this->Insert(i, other.Get(i));
      }*/

      LinkedList<T> tmp = other;
//Kalb's Line--------------------------------------
      std::swap(tmp.Head, this->Head);
      std::swap(tmp.ElementCount, this->ElementCount);
      return *this;  
   }

   LinkedList& operator =(LinkedList<T>&& other)
   {
      LinkedList<T> tmp(std::move(other));
//Kalb's Line-------------------------------------------
      std::swap(tmp.Head, this->Head);
      std::swap(tmp.ElementCount, this->ElementCount);
      return *this;
   }

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
T LinkedList<T>::Get(int position) const
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
   if(position == 0)
   {
      this->InsertHead(value);
      return;
   }

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

template <typename T> 
void LinkedList<T>::ForEach(std::function<void(T&)> lambda)
{
   Node<T>* ptr = Head;
   while(ptr != nullptr)
   {
      lambda(ptr->Value);
      ptr = ptr->Pointer;
   }
}