#include <iostream>
#include <string>
#include <cstring>
#include <curl/curl.h>
#include <algorithm>

using namespace std;

size_t writeFunction(void* ptr, size_t size, size_t nmemb, string* data) {
    data -> append((char*)ptr, size * nmemb);
    return size * nmemb;
}

string convert_http_query(string str){

    string::size_type pos = 0;    
    while ((pos = str.find(' ', pos)) != string::npos)
    {
        str.replace(pos, 1, "%20");
        pos += 3;
    }

    return str;
}

string send_get_http_req(string url){
    curl_global_init(CURL_GLOBAL_DEFAULT);
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
        //cout << response_string;
        return response_string;
    }
    return 0;
}