#include <iostream>
#include "http.h"

using namespace std;

string auth_bot(string token){
    return send_get_http_req("https://api.telegram.org/bot" + token + "/getMe");
}