// Code used to help parse information
// https://gist.github.com/PanagiotisPtr/e0c279a317ddc5d3369557f404bed06b
// https://github.com/open-source-parsers/jsoncpp/tree/master


#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>


std::size_t callback( const char *in, std::size_t size, std::size_t num, std::string *out) {
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}


// Printing All the JSON Data
/*
int main() {

    const std::string url("https://jsonmock.hackerrank.com/api/football_competitions");

    CURL* curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
    // Follow HTTP redirects if necessary.
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Response information.
    long httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    // Hook up data container (will be passed as the last parameter to the callback handling function).
    // Can be any pointer type, since it will internally be passed as a void pointer.
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

    // Run our HTTP GET command, capture the HTTP response code, and clean up.
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    if (httpCode == 200) {
        std::cout << "\nGot successful response from " << url << std::endl;

        // Response looks good - done using Curl now.  Try to parse the results and print them out.
        Json::Value jsonData;
        Json::Reader jsonReader;

        if (jsonReader.parse(*httpData.get(), jsonData)) {
            std::cout << "Successfully parsed JSON data" << std::endl;
            std::cout << "\nJSON data received:" << std::endl;
            std::cout << jsonData.toStyledString() << std::endl;
        }
        else {
            std::cout << "Could not parse HTTP data as JSON" << std::endl;
            std::cout << "HTTP data was:\n" << *httpData.get() << std::endl;
            return 1;
        }
    }

    else std::cout << "Couldn't GET from " << url << " - exiting" << std::endl; return 1;

    return 0;
}
*/


// Printing specific parts of JSON data
int main() {
    const std::string url("https://jsonmock.hackerrank.com/api/football_competitions");

    CURL* curl = curl_easy_init();
    if (!curl) { std::cerr << "Failed to initialize libcurl" << std::endl; return 1; }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    long httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) { std::cerr << "Failed to perform HTTP request: " << curl_easy_strerror(res) << std::endl; curl_easy_cleanup(curl); return 1; }

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    if (httpCode == 200) {
        std::cout << "\nGot successful response from " << url << std::endl;

        Json::Value jsonData;
        Json::Reader jsonReader;

        if (jsonReader.parse(*httpData.get(), jsonData)) {
            std::cout << "Successfully parsed JSON data" << std::endl;
            std::cout << "\nJSON data received:" << std::endl;

            // Check if jsonData has the key "data" and if it's an array
            if (jsonData.isMember("data") && jsonData["data"].isArray()) {
                // Access the "data" array
                const Json::Value& dataArray = jsonData["data"];

                // Iterate through each element in the "data" array
                for (const auto element : dataArray) {
                    if (element["year"].asInt() == 2013)
                        std::cout << element["winner"].asString() << std::endl;
                }
            } else { std::cerr << "JSON data does not contain 'data' array or it's not an array" << std::endl; return 1; }
        } else { std::cerr << "Could not parse HTTP data as JSON" << std::endl; return 1; }
    } else { std::cerr << "Couldn't GET from " << url << " - exiting" << std::endl; return 1; }

    return 0;
}