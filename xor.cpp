#include <iostream>
#define decrypt encrypt

std::string encrypt(std::string msg, std::string key){
    std::string tmp(key);
    while(key.size() < msg.size()) key += tmp;
    for(int i = 0; i < msg.size(); i++) msg[i] ^= key[i];
    return msg;
}
