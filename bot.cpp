#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>


#include "http.h"
#include "api.h"
#include "http.cpp"
#include "api.cpp"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int main(){
    if (checkBotToken(API_TOKEN)){
        cout << "[DEBUG] Token correct\n";
        long long polling_queue_offset = 0, returned_poll_offset;
        long chat_id;
        bool new_messages;
        string message;
        //cout << sendMessage(API_TOKEN, convert_http_query("Test message from API!"), 937293845);
        while (true){
            
            tie(returned_poll_offset, chat_id, new_messages, message) = getUpdates(API_TOKEN, polling_queue_offset);
            //cout << chat_id;
            if (new_messages){
                cout << "-----\n";
                polling_queue_offset = returned_poll_offset;
                cout << message << endl;
                cout << "------\n";
            }
            
            //sleep_for(seconds(1));
        }
    }else{  
        cout << "[DEBUG] Invalid token. Exiting...\n";
    }
    return 0;
}