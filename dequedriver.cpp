//Written by: Rebecca Su
//Student ID: 20760868

#include <iostream>
#include "deque.h"

int main(){
    std::string thisLine;
    std::string command;
    int param = 0;
    List list;
    
    while(!std::cin.eof())
    {
        std::getline(std::cin,thisLine);
        
        size_t pos = thisLine.find(" ");
        
        if(pos != std::string::npos)
        {
            command = thisLine.substr(0, pos);
            param = std::stoi(thisLine.substr(pos + 1, thisLine.size()));
        }
        else
            command = thisLine;
        
		if(command == "enqueue_front")
            list.enqueue_front(param);
        else if(command == "enqueue_back")
            list.enqueue_back(param);
        else if(command == "dequeue_front")
        {
            try
            {
                list.dequeue_front();
            }
            catch(DequeError e)
            {
                std::cout << "failure" << std::endl;
            }
        }
        else if(command == "dequeue_back")
        {
            try
            {
                list.dequeue_back();
            }
            catch(DequeError e)
            {
                std::cout << "failure" << std::endl;
            }
        }
        else if(command == "clear")
        {
            list.clear();
            std::cout << "success" << std::endl;
        }
        else if(command == "front")
        {
            try
            {
                if(list.front() == param)
                    std::cout << "success" << std::endl;
                else
                    std::cout << "failure" << std::endl;
            }
            catch(DequeError e)
            {
                std::cout << "failure" << std::endl;
            }
        }
        else if(command == "back")
        {
            try
            {
                if(list.back() == param)
                    std::cout << "success" << std::endl;
                else
                    std::cout << "failure" << std::endl;
            }
            catch(DequeError e)
            {
                std::cout << "failure" << std::endl;
            }
        }
        else if(command == "empty")
            list.empty();
        else if(command == "size")
            list.get_size();
        else if(command == "print")
            list.print();
    }
    return 0;
}
