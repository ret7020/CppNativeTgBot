#include <iostream>
#include <string>
#include <cstring>

#include "http.h"
#include "api.h"
#include "http.cpp"
#include "api.cpp"

using namespace std;

int main(){
    cout << auth_bot(API_TOKEN);
    return 0;
}