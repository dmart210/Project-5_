/**
 * @file: Network.cpp
 * @post: Template class called Network that receives Abstract Data Types (ADT) as the parameter.  
 * @purpose: the purpose of this file is to create a network with a capacity of at most 200 accounts, and store it in the Network
 *           we use different methods to do this such as addAccount and removeAccount that manipulate the Accounts in the Network. To
 *           do this points to Accounts are used, and these pointers are basically the items in the network that act as the Accounts. 
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "Network.hpp"
#include <sstream>
#include <string>

// #include "Post.hpp"
using namespace std;
/**
 * @post template class where T is going to be the items aka the Accounts in the network
 */
template<class T>
/**
 * @post: Default constructor that creates a network with the amount of networks initialized to 0
 */
Network<T>::Network()
{
	item_count = 0;
}
/**
 * @return: the amount of Accounts in the Network 
 */
template<class T>
int Network<T>::getSizeOfNetwork() const{
    return item_count;
}
/**
 * @return: returns true if the item_count (Accounts) is empty
 */
template<class T>
bool Network<T>::isEmpty() const{
    return item_count == 0;
}
/**
 * @param: a T type where T represents the Account class. This item will be added to the network 
 * @return: returns true if if it was able to add the Account to the Network, false otherwise
 */
template<class T>
bool Network<T>::addAccount(const T* item_being_added){
    bool username_duplicates = false;
    for (int i = 0; i < item_count; i++){
        if (getIndexOf(item_being_added) == getIndexOf(temp_items[i])) username_duplicates = true;
    }
    if (username_duplicates == true) return false;
    bool has_room = (item_count < DEFAULT_CAPACITY);
    if (has_room && username_duplicates == false){
        temp_items[item_count] = item_being_added;
        item_count++;
        //changes private member
        return true;
    }
    return false;
}
/**
 * @param: an Account that is going to be removed from the Network
 * @return: returns true if the network was able to remove the Account(item)
 */
template<class T>
bool Network<T>::removeAccount(const T* item_being_removed){
    int found_index = getIndexOf(item_being_removed);
    bool can_remove = !isEmpty() && (found_index > -1);
    if (can_remove){
        item_count--;
        temp_items[found_index] = temp_items[item_count];
    }
    return can_remove;
}
/**
 * @post: clears the amount of Accounts in Network by setting item_count to 0
 */
template<class T>
void Network<T>::clear(){
    item_count = 0;
}
/**
 * @param: Account that is going to be checked if it is in the Network
 * @return: return if the account has an index > -1
 */
template<class T>
bool Network<T>::containsAccount(const T* contains_item){
    return getIndexOf(contains_item) > -1;
}
/**
 * @param: file type
 * @post: will go through the file, find the username and password, and then create Accounts using the usernames and passwords found. 
 */
template <typename T>
void Network<T>::populateNetwork(const string input){
    std::fstream fin;
    fin.open(input, std::ios::in);
    std::string usr = "";
    std::string pswd = "";
    std::string line;
    std::string word;
    while (std::getline(fin, line)){
        if(line == ";") {
            break;
        }
        std::stringstream s(line);
        s >> usr;
        s >> pswd;
        if(usr == "" || pswd == "") {
            std::cout << "Improper format" << std::endl;
            break;
        }
        T* new_entry = new T(usr,pswd);
        bool is_added = addAccount(new_entry);
        if(!is_added) {
            std::cout << "Error when adding account" << std::endl;
            break;
        }
        usr = "";
        pswd = "";
    }
    fin.close();
}
/**
 * @param: const reference of a different network
 * @return: will return the {this} network with the changes applied 
 */
template<class T>
Network<T>& Network<T>::operator-=(const Network<T>& another_net){
    int network_count = another_net.item_count;
    for (int i = 0; i < this->item_count;i++){
        for (int j = 0; j < network_count; j++){
            if(this->temp_items[i] == another_net.temp_items[j]) {
                removeAccount(this->temp_items[i]);
            }
        }
    }
    return *this;
}
/**
 * @param: A T type(account) passed by reference
 * @note: This method will print out all the Post in the method only if the iterator is not nullptr(reached the end of the list), and if the 
 *        account is in the Network. If it passes that test, then it will get the item of the position of the iterator, and then displayPost(),
 *        which as stated before Polymorphised so it will print out the respective Post for the children class of Post.
 */
template<class T>
void Network<T>::printFeedForAccount(T& account_being_displayed){
    T* acc = &account_being_displayed;
    Node<Post*>* iterator = feed.getHeadPtr();
    while(iterator != nullptr) {
        if (containsAccount(acc) && iterator != nullptr){
            iterator->getItem()->displayPost();
        }
        iterator = iterator->getNext();
    }
}
/**
 * @param: const reference of an Account and the username that the Account would like to follow
 * @return: true if the Account was able to follow said username
 */
template<class T>
bool Network<T>::authenticateFollow(T& _account, const string username){

    return false;
}
/**
 * @param: A reference to T{Post} which will be added to the feed
 * @return: will return true if it was able to add the post to the feed.
 */
template<class T>
bool Network<T>::addToFeed(Post* account_post){
    Post* post_ptr = account_post;
    feed.insert(post_ptr,0);
    return true;
}
/**
 * @param: const pointer of a username of an Account
 * @return: the integer of the index of where the Account with the username {_username} is found, if it is found. 
 */
template<class T>
int Network<T>::getIndexOf(const T* _username){
    bool found = false;
    int result = -1;
    int search_index = 0;
    while (!found && (search_index < item_count)){
        if (temp_items[search_index] == _username){
            found = true;
            result = search_index;
        }
        else search_index++;
    }
    return result;
}

/**
 * @param: A string reference that will contain a phrase that is case sensitive
 * @return: Will return the number of Post pointers removed if it contained that phrase 
 */
template<class T>
int Network<T>::removeIfContains(const string& phrase_sensitive){
    int occureneces(0);
    if (feed.getSize() == 0){
        return occureneces;
    }
    else{
        Node<Post*>* curr = feed.getHeadPtr();
        while (curr != nullptr){
            Post* curr_post = feed.getHeadPtr();
            curr = curr->getNext();
            if (curr_post->getTitle().find(phrase_sensitive) != std::string::npos || curr_post->getBody().find(phrase_sensitive) != std::string::npos){
                int acc_index = getIndexOf(curr_post->getUsername());
                if (acc_index > -1){
                    temp_items[acc_index]->removePost(curr_post);
                }
                occureneces;
            }
        }
    }
    return occureneces;
}

template<class T>
LinkedList<Post*> Network<T>::getFeed(){
    return feed;
}

template<class T>
void Network<T>::setFeed(LinkedList<Post *> list) {
     feed = list;
}
template<class T>
bool Network<T>::updateFeed(Post* post){
    return feed.moveItemToTop(post);
}

template<class T>
void Network<T>::swap(Post* p1, Post* p2){
    string temp = p1->getUsername();
    p1->setUsername(p2->getUsername());
    p2->setUsername(temp);
}

template<class T>
template<typename Comparator> 
LinkedList<Post*> Network<T>::bSortByUsername(Comparator comp, int* swap_counter){
    LinkedList<Post*> sortedList = feed;
    int size = sortedList.getSize();
    bool swapped = true;
    int pass = 1;
    Node<Post*>* iterator = sortedList.getHeadPtr();
    if (comp == std::less<Post*>{}){
        while (swapped && (pass < size)){
            swapped = false;
            while (iterator != nullptr){
                if (iterator->getItem() > iterator->getNext()->getItem()){
                    swap(iterator->getItem(), iterator->getNext()->getItem());
                    swapped = true;
                }
                iterator = iterator->getNext();
                pass++;
            }
        }
    }
    else if (comp == std::greater<Post*>{}){
        while (swapped && (pass < size)){
            swapped = false;
            while (iterator != nullptr){
                if (iterator->getItem() < iterator->getNext()->getItem()){
                    swap(iterator->getItem(), iterator->getNext()->getItem());
                    swapped = true;
                }
                iterator = iterator->getNext();
            }
        }
    }
    else{
        throw std::runtime_error("error wrong format for comparator");
    }
    return sortedList;
}
