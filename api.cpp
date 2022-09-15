#include <iostream>
#include "http.h"
#include "json.hpp"
#include <tuple>



//using namespace std;
using json = nlohmann::json;

bool checkBotToken(string token){
    std::string data = send_get_http_req(API_URL + token + "/getMe");
    char * tab2 = new char [data.length() + 1];
    strcpy (tab2, data.c_str());

    json json_object = json::parse(tab2);
    //std::cout << json_object["ok"];
    //return json_object;
    return json_object["ok"];
}

std::tuple<long long, long, bool, string> getUpdates(string token, long long offset){
    long long new_offset;
    bool new_messages = false;
    long chat_id;
    string message_text;

    std::string data = send_get_http_req(API_URL + token + "/getUpdates?offset=" + std::to_string(offset));
    //cout << data;
    char * tab2 = new char [data.length() + 1];
    strcpy (tab2, data.c_str());
    json json_object = json::parse(tab2);
    json queue = json_object["result"];
    for (auto& message : queue) {
        new_offset = message["update_id"];
        message_text = message["message"]["text"];
        chat_id = std::stoi(message["message"]["chat"]["id"]);
        new_messages = true;
        
        
    }
    cout << chat_id;
    return {new_offset + 1, chat_id, new_messages, message_text};

    
}
bool sendMessage(string token, string message, long long chat_id){
    string req = API_URL + token + "/sendMessage?chat_id=" + std::to_string(chat_id) + "&text=" + message + "";
    std::string data = send_get_http_req(req);
    char * tab2 = new char [data.length() + 1];
    strcpy (tab2, data.c_str());
    json json_object = json::parse(tab2);
    return json_object["ok"];
}
