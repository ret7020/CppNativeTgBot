#include <iostream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;


int main(){
    json jsonSampleData =
    {
        {"test","TEST"},
        {"true", true},
        {"number",21453}
    };
    cout << jsonSampleData.value("test", "oops");

    return 0;
}