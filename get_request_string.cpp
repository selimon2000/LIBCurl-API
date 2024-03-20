#include <iostream>
#include <curl/curl.h>
#include <string>


/*
// Callback function to write received data
size_t write_callback(char *ptr, size_t size, size_t nmemb, std::string *stream) {
    size_t count = size * nmemb;
    stream->append(ptr, count);
    return count;
}

int main() {

    std::string response;

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    if (!curl)
        return 1;
        
    // Set the URL to the API endpoint
    curl_easy_setopt(curl, CURLOPT_URL, "https://jsonmock.hackerrank.com/api/football_competitions");
    // Set write callback function to handle response data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    // Pass the response string as the userdata parameter
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Perform the request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    else 
        // Print the received data
        std::cout << "Response:" << std::endl << response << std::endl;

    // Cleanup
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}
*/


int main() {

    CURL *curl = curl_easy_init();
  
    if (!curl) {std::cout << "Initialisation Failed" << std::endl; return 1;}
  
    curl_easy_setopt(curl, CURLOPT_URL, "https://jsonmock.hackerrank.com/api/football_competitions");

    // Perform the request
    CURLcode res = curl_easy_perform(curl);

    //  Check for errors
    if (res != CURLE_OK) std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

    double totalTime;
    double dnsTime;
    double connectTime;

    // Get information about the performed transfer
    curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &totalTime);
    curl_easy_getinfo(curl, CURLINFO_NAMELOOKUP_TIME, &dnsTime);
    curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &connectTime);

    // Print the retrieved information
    printf("\n\nTotal time taken: %.3f seconds\n", totalTime);
    printf("DNS time: %.3f seconds\n", dnsTime);
    printf("Connect time: %.3f seconds\n", connectTime);

    curl_easy_cleanup(curl);
}