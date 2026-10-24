/* Copyright (c) 2026 AmigaChrome Team. MIT licence. */
#include <curl/curl.h>
int main(void)
{
    CURL *handle;
    if (curl_global_init(CURL_GLOBAL_DEFAULT) != CURLE_OK) return 1;
    handle = curl_easy_init();
    if (handle) curl_easy_cleanup(handle);
    curl_global_cleanup();
    return handle ? 0 : 2;
}
