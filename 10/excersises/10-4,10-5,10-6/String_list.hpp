#ifndef _STRING_LIST_H_
#define _STRING_LIST_H_

#include <list>
#include <string>

class String_list
{
        private:
                std::string* p_str;
                size_t n;
        public:
                String_list(): p_str(0), n(0) {};
                ~String_list();
                std::string* begin() { return p_str; }
                std::string* end() { return p_str + n; }
                void push(std::string);
                std::string pop();
};


#endif
