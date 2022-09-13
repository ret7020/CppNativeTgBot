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
        cout << sendMessage(API_TOKEN, convert_http_query("Test message from API!"), 937293845);
        /*while (true){
            cout << get_updates(API_TOKEN);
            sleep_for(nanoseconds(10));
        }*/
    }else{  
        cout << "[DEBUG] Invalid token. Exiting...\n";
    }
    return 0;
}