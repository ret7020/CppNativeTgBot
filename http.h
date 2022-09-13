#ifndef HTTP_H
#define HTTP_H

#include <string>
#include <cstring>


size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data);
std::string send_get_http_req(std::string url);
std::string convert_http_query(std::string data);
#endif
