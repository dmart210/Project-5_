/****************************************************************************************************************************
Title         :   Post.cpp
Author        :   Dream Team
Description   :   Implementation for Post class
****************************************************************************************************************************/


#include "Post.hpp"


/**
   Parameterized constructor.
   @param      : The title of the post (a string)
   @param      : The body content of the post (a string)
   @param      : The username of the Account that added this post (a string)

   @post         : Sets the title, body and username to the value of the parameters
                   It will also generate the current time and store it
*/
Post::Post(std::string title, std::string body, std::string username) {
    post_title_ = title;
    post_body_ = body;
    time_stamp_ = time(NULL);
    username_ = username;
}


/**
   @return : the title of the Post
*/
std::string Post::getTitle() const {
    return post_title_;
}


/**
  @param  : a reference to title of the Post
  @post   : sets the private data member to the value of the parameter
*/
void Post::setTitle(const std::string& title) {
    post_title_ = title;
}


/**
   @return : the body of the Post
*/
std::string Post::getBody() const {
    return post_body_;
}


/**
   @param  : a reference to body of the Post
   @post   : sets the private data member to the value of the parameter
*/
void Post::setBody(const std::string& body) {
    post_body_ = body;
}


/*
   Accessor Function
   @return       : username associated with this Post
*/
std::string Post::getUsername() const {
    return username_;
}


/*
   Mutator Function
   @param        : a reference to the username associated with this Post
   @post   : sets the private data member to the value of the parameter
*/
void Post::setUsername(const std::string& username) {
    username_ = username;
}


/**
    @post:  prints out the post in the following format:
    \n
    {post_title_} at {time_stamp_}:
    {post_body_}
    \n
*/
void Post::getTimeStamp() const {
    std::cout << asctime(localtime(&time_stamp_));
}



/*
   Mutator Function
   @post   : sets the private data member to the current time
*/
void Post::updateTimeStamp() {
    time_stamp_ = time(0);
}

/**
 * 
 * @note: operator that compares the the usernames of two post objects and sees if the left Post is less than the right post
 * @return: returns true if the Post on the left side is less than  (first in the alpha bet) than the Post on the right side.
 */
bool Post::operator<(const Post& post_)const{
    std::string this_len = this->getUsername();
    std::string post_len = post_.getUsername();
    return this_len < post_len;
}


/**
 * 
 * @note: operator that compares the the usernames of two post objects and sees if the left post is greater than the right post. 
 * @return: returns true if the Post on the left side is greater (farther in the alphabet) than the Post on the right side.
 */
bool Post::operator>(const Post& post_) const{
    std::string this_len = this->getUsername();
    std::string post_len = post_.getUsername();
    return this_len > post_len;
    return false;
}