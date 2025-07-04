#include <stdio.h> 
#include <gtest/gtest.h>
#include "linkedlist.h"

TEST(Get, Get_4_EmptyList)
{
    LinkedList<int>* EmptyList = new LinkedList<int>;
    EXPECT_THROW(EmptyList->Get(4), LinkedList<int>::OutOfRangeException);
}

TEST(InsertHead, InsertHead_EmptyList_86)
{
    LinkedList<int>* EmptyList = new LinkedList<int>;
    EmptyList->InsertHead(86);
    ASSERT_EQ(EmptyList->Get(0), 86); 
    ASSERT_EQ(EmptyList->GetSize(), 1);
}

TEST(InsertHead, Twice_InsertHead_EmptyList_86)
{
    LinkedList<int>* EmptyList = new LinkedList<int>;
    EmptyList->InsertHead(8);
    EmptyList->InsertHead(86);
    ASSERT_EQ(EmptyList->Get(0), 86);
    ASSERT_EQ(EmptyList->Get(1), 8);
    ASSERT_EQ(EmptyList->GetSize(), 2);
}

TEST(InsertHead, 3x_InsertHead_EmptyList_86)
{
    int x = 8;
    int y = 86;
    int z = 789;
    LinkedList<int>* EmptyList = new LinkedList<int>;
    EmptyList->InsertHead(x);
    EmptyList->InsertHead(y);
    EmptyList->InsertHead(z);
    ASSERT_EQ(EmptyList->Get(0), z);
    ASSERT_EQ(EmptyList->Get(1), y);
    ASSERT_EQ(EmptyList->Get(2), x);
    ASSERT_EQ(EmptyList->GetSize(), 3);;
}

TEST(Insert, InsertHead_0_Insert1_86_Get)
{
    LinkedList<int>* ZeroElementList = new LinkedList<int>;
    ZeroElementList->InsertHead(0);
    ZeroElementList->Insert(1, 86);
    ASSERT_EQ(ZeroElementList->GetSize(), 2);;
    ASSERT_EQ(ZeroElementList->Get(0), 0);   
    ASSERT_EQ(ZeroElementList->Get(1), 86);     
}

TEST(Insert, Insert_4_EmptyList)
{
    LinkedList<int>* EmptyList = new LinkedList<int>;
    EXPECT_THROW(EmptyList->Insert(4, 456), LinkedList<int>::OutOfRangeException);
}

TEST(Insert, Insert_0_EmptyList)
{
    LinkedList<int>* EmptyList = new LinkedList<int>;
    EmptyList->Insert(0, 456);
    ASSERT_EQ(EmptyList->Get(0), 456);
}

TEST(Insert, InsertHead_0_Insert1_86_Insert2_789_Insert3_456)
{
    LinkedList<int>* ZeroElementList = new LinkedList<int>;
    ZeroElementList->InsertHead(0);
    ZeroElementList->Insert(1, 86);
    ZeroElementList->Insert(2, 789);
    ZeroElementList->Insert(3, 456);
    ASSERT_EQ(ZeroElementList->GetSize(), 4);
    ASSERT_EQ(ZeroElementList->Get(0), 0);   
    ASSERT_EQ(ZeroElementList->Get(1), 86); 
    ASSERT_EQ(ZeroElementList->Get(2), 789);
    ASSERT_EQ(ZeroElementList->Get(3), 456);    
}

TEST(InsertTail, InsertTail)
{
    LinkedList<int>* EmptyList = new LinkedList<int>;
    EmptyList->InsertHead(0);
    EmptyList->Insert(1, 86);
    EmptyList->Insert(2, 456);    
    EmptyList->InsertTail(789);
    ASSERT_EQ(EmptyList->Get(0), 0); 
    ASSERT_EQ(EmptyList->Get(1), 86);  
    ASSERT_EQ(EmptyList->Get(2), 456);
    ASSERT_EQ(EmptyList->Get(3), 789);  
    ASSERT_EQ(EmptyList->GetSize(), 4);
}

TEST(Remove, Remove_Node_2)
{
    LinkedList<int>* EmptyList = new LinkedList<int>;
    EmptyList->InsertHead(0);
    EmptyList->Insert(1, 86);
    EmptyList->Insert(2, 456);    
    EmptyList->InsertTail(789);
    EmptyList->Remove(2);
    ASSERT_EQ(EmptyList->Get(0), 0); 
    ASSERT_EQ(EmptyList->Get(1), 86);  
    ASSERT_EQ(EmptyList->Get(2), 789); 
   ASSERT_EQ(EmptyList->GetSize(), 3);   
   ASSERT_EQ(EmptyList->GetSize(), 3);
}

TEST(Remove, Remove_Exception)
{
    LinkedList<int> EmptyList;
    EmptyList.InsertHead(0);
    EmptyList.Insert(1, 86);
    EmptyList.Insert(2, 456);    
    EmptyList.InsertTail(789);
    EmptyList.Remove(2);
    EXPECT_THROW(EmptyList.Get(3), LinkedList<int>::OutOfRangeException);
    
}

TEST(Constructor_Destructor, ElementCount)
{
   LinkedList<int> EmptyList;
   ASSERT_EQ(EmptyList.GetSize(), 0);
}

TEST(Constructor_Destructor, Destructor)
{
   LinkedList<int> EmptyList;
   EmptyList.InsertHead(0);
   EmptyList.Insert(1, 86);
   EmptyList.Insert(2, 456);    
   EmptyList.InsertTail(789);
}

TEST(Copy_Constructor, Get1)
{
    LinkedList<int> List1;
    List1.InsertHead(0);
   List1.Insert(1, 86);
   List1.Insert(2, 456);    
   List1.InsertTail(789);
   LinkedList<int> List2 = List1;
   ASSERT_EQ(List2.Get(1), List1.Get(1));
   ASSERT_EQ(List1.GetSize(), List2.GetSize());
}

TEST(Operator, Get1)
{
    LinkedList<int> List1;
    List1.InsertHead(0);
   List1.Insert(1, 86);
   List1.Insert(2, 456);    
   List1.InsertTail(789);
   LinkedList<int> List2;
   List2.InsertHead(0);
   List2.Insert(1, 289);
   List2 = List1;
   ASSERT_EQ(List2.Get(1), List1.Get(1));
   ASSERT_EQ(List1.GetSize(), List2.GetSize());
}

TEST(Operator, Self_Assignment)
{
    LinkedList<int> List1;
    List1.InsertHead(0);
   List1.Insert(1, 86);
   List1.Insert(2, 456);    
   List1.InsertTail(789);
   List1 = List1;
   ASSERT_EQ(List1.Get(1), List1.Get(1));
   ASSERT_EQ(List1.GetSize(), List1.GetSize());
}

TEST(Move, Test1)
{
    LinkedList<int> List1;
    List1.InsertHead(0);
   List1.Insert(1, 86);
   List1.Insert(2, 456);    
   List1.InsertTail(789);
   LinkedList<int> List2(std::move(List1));
   ASSERT_EQ(List2.GetSize(), 4);
   ASSERT_EQ(List1.GetSize(), 0);
   ASSERT_EQ(List2.Get(2), 456);
}

TEST(Move_Assignment, Test1)
{
    LinkedList<int> List1;
    List1.InsertHead(0);
   List1.Insert(1, 86);
   List1.Insert(2, 456);    
   List1.InsertTail(789);
   LinkedList<int> List2;
   List2.InsertHead(0);
   List2.Insert(1, 289);
   List2 = std::move(List1);
   ASSERT_EQ(List2.Get(1), 86);
   ASSERT_EQ(List1.GetSize(), 0);
}

TEST(Move_Assignment, Self_Assignment)
{
    LinkedList<int> List1;
    List1.InsertHead(0);
   List1.Insert(1, 86);
   List1.Insert(2, 456);    
   List1.InsertTail(789);
   List1 = std::move(List1);
   ASSERT_EQ(List1.Get(1), 86);
   ASSERT_EQ(List1.GetSize(), 4);
}