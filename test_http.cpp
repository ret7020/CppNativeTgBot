
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <cstring>

using namespace std;

size_t writeFunction(void* ptr, size_t size, size_t nmemb, string* data) {
    data -> append((char*)ptr, size * nmemb);
    return size * nmemb;
}

string send_get(string url){
    auto curl = curl_easy_init();
    
    if (curl) {
        // Convert url from string to *char
        int url_length = url.length();
        char url_arr[url_length + 1];
        strcpy(url_arr, url.c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url_arr);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.5060.114 Safari/537.36");

        string response_string;
        string header_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        curl = NULL;
        cout << response_string;
        return response_string;
    }
    return 0;
    
}

int main(int argc, char** argv) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    string url = "https://api.github.com/repos/ret7020/WebRoboBlock/contributors?anon=true&key=value";
    cout << send_get(url);
    return 0;
}