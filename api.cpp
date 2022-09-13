#include <iostream>
#include "http.h"
#include "json.hpp"


//using namespace std;
using json = nlohmann::json;

bool checkBotToken(string token){
    std::string data = send_get_http_req("https://api.telegram.org/bot" + token + "/getMe");
    char * tab2 = new char [data.length()+1];
    strcpy (tab2, data.c_str());

    json json_object = json::parse(tab2);
    //std::cout << json_object["ok"];
    //return json_object;
    return json_object["ok"];
}

json getUpdates(string token){
    std::string data = send_get_http_req("https://api.telegram.org/bot" + token + "/getUpdates");
    char * tab2 = new char [data.length()+1];
    strcpy (tab2, data.c_str());
    json json_object = json::parse(tab2);
    json queue = json_object["result"];
    for (json::iterator it = queue.begin(); it != queue.end(); ++it) {
        std::cout << *it << '\n';
    }
    return 0;
}
bool sendMessage(string token, string message, long long chat_id){
    string req = "https://api.telegram.org/bot" + token + "/sendMessage?chat_id=" + std::to_string(chat_id) + "&text=" + message + "";
    std::string data = send_get_http_req(req);
    char * tab2 = new char [data.length()+1];
    strcpy (tab2, data.c_str());
    json json_object = json::parse(tab2);
    return json_object["ok"];
}
