#include <iostream>
#include <string>
#include <cstring>

#include "http.h"
#include "api.h"
#include "http.cpp"

using namespace std;

int main(){
    string url = "https://api.github.com/repos/ret7020/WebRoboBlock/contributors?anon=true&key=value";
    cout << send_get_http_req(url);
    return 0;
}