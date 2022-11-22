#include "LinkedList.hpp"
#include "Node.hpp"
#include "Post.hpp"
#include "General.hpp"
//#include "Network.hpp"
#include "Account.hpp"
using namespace std;
#include <string>
int main() {
//    srand(time(NULL));
//    LinkedList<int> list;

    LinkedList<Post*> list;
//    for (int i = 0; i < 5; i++){
//        list.insert(rand()%100+1, 0);
//    }
    Post* ptr1 = new General("first", "description", "1");
    Post* ptr2 = new General("second", "description", "12");
    Post* ptr3 = new General("third", "description", "123");
    Post* ptr4 = new General("fourth", "description", "1234");
    Post* ptr5 = new General("fifth", "description", "123555");
    list.insert(ptr1,0);
    list.insert(ptr2,0);
    list.insert(ptr3,0);
    list.insert(ptr4,0);
    list.insert(ptr5,0);
//    std::cout << "Original:\n";
//    list.printList();
//    std::cout << "\n\n";
//    LinkedList<Post*> sortedLessToG = list.bubbleSortLessToGreat();
//    LinkedList<Post*> sortedGToLess = list.bubbleSortGreatToLess();
//    std::cout << "Less to Greater:\n";
//    sortedLessToG.printList();
//    std::cout << "\n\n";
//    std::cout << "Greater to Less:\n";
//    sortedGToLess.printList();
    return 0;
}
