#include "sl_wifi.h"
#include "sl_net.h"
#include "sl_http_server.h"
#include "cmsis_os2.h"
#include <stdio.h>
#include <string.h>

#define WIFI_SSID "Bus_Hotspot"
#define WIFI_PASS "busalert1"

static void http_response_handler(sl_http_server_request_t *req, sl_http_server_response_t *res) {
    const char *page =
        "<!DOCTYPE html><html><head><title>Bus Info</title>"
        "<style>"
        "body{font-family:Arial;text-align:center;background:#eef7ff;color:#333;}"
        "h1{color:#0055cc;font-size:30px;margin-top:30px;}"
        "p{font-size:20px;line-height:1.5;}"
        "</style></head>"
        "<body><h1>🚌 Bus Information</h1>"
        "<p><b>Bus Number:</b> 23B</p>"
        "<p><b>Route:</b> Gandhipuram → Peelamedu → Airport</p>"
        "<p><b>Upcoming Stop:</b> Peelamedu</p>"
        "<p><i>Have a safe and pleasant journey!</i></p></body></html>";

    sl_http_server_send_response(res, SL_HTTP_SERVER_OK, page, strlen(page));
    printf("Bus Info: 23B | Route: Gandhipuram → Airport | Next: Peelamedu\n");
}

void app_init(void)
{
    sl_status_t status;
    sl_wifi_ap_profile_t ap_config = {0};
    ap_config.ssid = WIFI_SSID;
    ap_config.security = SL_WIFI_WPA2;
    ap_config.passkey = WIFI_PASS;
    ap_config.channel = 6;

    printf("Starting Bus Hotspot...\n");
    status = sl_wifi_start_ap(&ap_config);
    if (status != SL_STATUS_OK) {
        printf("Wi-Fi AP start failed!\n");
        return;
    }

    printf("Wi-Fi AP started! SSID: %s, PASS: %s\n", WIFI_SSID, WIFI_PASS);
    sl_http_server_init(http_response_handler);
    sl_http_server_start();
    printf("HTTP Server started at: http://192.168.4.1/\n");
}
