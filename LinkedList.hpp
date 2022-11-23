/****************************************************************************************************************************
Title         :   LinkedList.hpp
Author        :   Dream Team
Description   :   header/interface files for LinkedList class
****************************************************************************************************************************/


#ifndef LinkedList_
#define LinkedList_

#include <iostream>
#include <vector>
#include "Node.hpp"


template<typename ItemType>
class LinkedList {

    public:
        /* Default constructor*/
        LinkedList();

        /* Copy Contructors*/
        LinkedList(const LinkedList<ItemType> &list);




        /* Destructor */
        ~LinkedList();

        /*
            Inserts parameter item in caller list at parameter position
            @pre position is a valid place within the list, otherwise false will be returned
            @post returns true if the item has been inserted in the caller list
        **/
        bool insert(const ItemType &item, const int &position);

        /*
            removes node at parameter position
            @pre position is a valid place within the list, otherwise false will be returned
            @post returns true if the item at position has been removed from the caller list
        **/
        bool remove(const int &position);

        /* Returns the size of the lis;t */
        int getSize() const;

        /* Returns the head pointer */
        Node<ItemType> *getHeadPtr() const;

        /* Returns whether the caller list is empty */
        bool isEmpty() const;

        /*
            @post    : removes all items from the caller list,
                       no nodes remain in the list
        **/
        void clear();


        /*
            @param         : item object to find in the list
            @return     : the position (index) of the parameter object
        **/
        int getIndexOf(const ItemType &item) const;


        /*
            @pre      :   current_position and new_position is valid
            @return   :   true if item is moved to new_position, false otherwise
            @post     :   Moves item from current_position to new_position, if valid
        **/
        bool moveItem(int &current_position, const int &new_position);



        /*
            @param            :   A reference to an item
            @return           :   Return true if item was moved to top, false otherwise
            @post             :   Will move the item from its current position to the front
                                  of the list.
                                  For example, given the list 1 -> 3 -> 5 -> 6, moving 5 to the
                                  top of the list would result in 5 -> 1 -> 3 -> 6
                                  (recall that positions start at 0 and end at n-1).
        */
        bool moveItemToTop(const ItemType &item);


        /*
            @param            :   Another LinkedList passed by reference
            @post             :   Sets the current LinkedList with the same items as the provided
                                  LinkedList but in reverse order
        */
        void reverseCopy(const LinkedList<ItemType> &a_list);

        /**
         * 
         * @pre: Comp must be a valid Comparator of either [std::less<Post>{} or std::greater<Post>{}]
         * @@post: This method will go through the feed_ LinkedList and using bubble sort, we will sort from either least to greatest,
         *         or from greatest to least, all depending on the comparator given. 
         * @note: The way bubble sort works is we're going to iterate throughout the LinkedList and see if the current Nodes username is greater than/less
         *        than the following Nodes usernames. If it is, then we are going to swap those two Post objects. And after we swap them, we increment
         *        the swap_counter.
         * 
         */
        template<typename Comparator>
        void bubbleSort(Comparator comp, int* swap_counter);
        /**
         * 
         * @post: This method will simply traverse through the LinkedList, get the item, and displayPost of the Post* it obtains. 
         */
        void printList();
        /**
         * @pre: Node 1 and Node 2 should be present in the LinkedList, but doesn't have to be since we are traversing through any LinkedList
         * @post: This method will get Two nodes [node1 and node 2], and with these nodes we will swap the item inside them.
         *        To do this, set a brand new ItemType (which will be = Post*), set the right most nodes item or Node2's item to Node1's item, and then
         *        set the first nodes item (node 1) to the temp which is node2's item. 
         *        EX:
         *        node1 = post_ptr1
         *        node2 = post_ptr2
         *        swap(node1, node2)
         *        node1 = post_ptr2
         *        node2 = post_ptr1
         * 
         */
        void swap (Node<ItemType>* item1, Node<ItemType>* item2);



    private:
        /*
            @pre      :  pos is a valid place in the list, otherwise nullptr will be returned
            @param    :  the position of the item to be returned
            @return   :  a pointer to the node at pos
        **/
        Node<ItemType> *getAtPos(const int &pos) const;
        Node<ItemType> *head_;
        size_t size_;
        int swapp =0;
};

#include "LinkedList.cpp"
#endif