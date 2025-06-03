# Linked-list

Implement a single linked list as a template class with pointers with the following interface using test-driven development:


template <typename T>
class LinkedList
{
public:
   void InsertHead(T value);
   void Insert(int position, T value);
   void InsertTail(T value);
   T Get(int position);
   void Remove(int position);
};

Hint: Add any missing details to the class.