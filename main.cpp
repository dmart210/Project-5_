#include "Account.hpp"
#include "General.hpp"
#include "LinkedList.hpp"
#include "Network.hpp"
#include "Node.hpp"
#include "Poll.hpp"
#include "Post.hpp"
#include "Promotional.hpp"
using namespace std;

int main(){
    cout << "depressed" << endl;
    Post* p1_ = new General("title", "body", "user");
    Post* p2_ = new General ("title2","body2","user2");

    if (p1_ > p2_) cout << "good";
    else cout << "basd";

}