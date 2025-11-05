/*
 * Network Utility Program
 * 
 * This program provides network diagnostic tools:
 * 1. Display Public and Local IP addresses
 * 2. Ping a website and show average latency
 * 3. Estimate internet speed (download/upload)
 * 
 * Designed for Windows OS
 * Compile with: gcc network_utility.c -o network_utility.exe -lws2_32 -liphlpapi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <iphlpapi.h>
    #include <windows.h>
    #pragma comment(lib, "ws2_32.lib")
    #pragma comment(lib, "iphlpapi.lib")
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <netdb.h>
#endif

// Function prototypes
void displayMenu();
void getPublicIP();
void getLocalIP();
void pingWebsite(const char* hostname);
void testInternetSpeed();
void clearInputBuffer();

/*
 * Main function - Entry point of the program
 */
int main() {
    int choice;
    char hostname[256];
    
    #ifdef _WIN32
    // Initialize Winsock for Windows
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock.\n");
        return 1;
    }
    #endif
    
    printf("========================================\n");
    printf("   Network Utility Program\n");
    printf("========================================\n\n");
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\nInvalid input! Please enter a number.\n\n");
            continue;
        }
        clearInputBuffer();
        
        printf("\n");
        
        switch (choice) {
            case 1:
                printf("--- Public IP Address ---\n");
                getPublicIP();
                break;
                
            case 2:
                printf("--- Local IP Address ---\n");
                getLocalIP();
                break;
                
            case 3:
                printf("Enter website to ping (e.g., google.com): ");
                fgets(hostname, sizeof(hostname), stdin);
                hostname[strcspn(hostname, "\n")] = 0; // Remove newline
                printf("\n--- Pinging %s ---\n", hostname);
                pingWebsite(hostname);
                break;
                
            case 4:
                printf("--- Internet Speed Test ---\n");
                testInternetSpeed();
                break;
                
            case 5:
                printf("--- Complete Network Diagnostics ---\n\n");
                printf("1. Public IP Address:\n");
                getPublicIP();
                printf("\n2. Local IP Address:\n");
                getLocalIP();
                printf("\n3. Ping Test (google.com):\n");
                pingWebsite("google.com");
                printf("\n4. Speed Test:\n");
                testInternetSpeed();
                break;
                
            case 0:
                printf("Exiting program. Goodbye!\n");
                #ifdef _WIN32
                WSACleanup();
                #endif
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
        
        printf("\n");
    }
    
    #ifdef _WIN32
    WSACleanup();
    #endif
    
    return 0;
}

/*
 * Display the main menu
 */
void displayMenu() {
    printf("========================================\n");
    printf("1. Show Public IP Address\n");
    printf("2. Show Local IP Address\n");
    printf("3. Ping a Website\n");
    printf("4. Test Internet Speed\n");
    printf("5. Run All Tests\n");
    printf("0. Exit\n");
    printf("========================================\n");
}

/*
 * Get Public IP Address
 * Uses external API service (ipify.org) via curl command
 */
void getPublicIP() {
    char command[512];
    FILE *fp;
    char ip[100];
    
    // Try using curl first (more common on Windows)
    #ifdef _WIN32
    sprintf(command, "curl -s https://api.ipify.org 2>nul");
    #else
    sprintf(command, "curl -s https://api.ipify.org 2>/dev/null");
    #endif
    
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: curl not found. Trying wget...\n");
        
        // Try wget as fallback
        #ifdef _WIN32
        sprintf(command, "wget -qO- https://api.ipify.org 2>nul");
        #else
        sprintf(command, "wget -qO- https://api.ipify.org 2>/dev/null");
        #endif
        
        fp = popen(command, "r");
        if (fp == NULL) {
            printf("Error: Neither curl nor wget is available.\n");
            printf("Please install curl or wget to use this feature.\n");
            return;
        }
    }
    
    // Read the IP address from command output
    if (fgets(ip, sizeof(ip), fp) != NULL) {
        ip[strcspn(ip, "\n")] = 0; // Remove newline
        printf("Your Public IP: %s\n", ip);
    } else {
        printf("Failed to retrieve public IP address.\n");
        printf("Please check your internet connection.\n");
    }
    
    pclose(fp);
}

/*
 * Get Local IP Address
 * Uses Windows API (GetAdaptersAddresses) or socket method
 */
void getLocalIP() {
    #ifdef _WIN32
    // Windows-specific implementation using IP Helper API
    PIP_ADAPTER_ADDRESSES pAddresses = NULL;
    PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
    ULONG outBufLen = 15000;
    DWORD dwRetVal = 0;
    int found = 0;
    
    // Allocate memory for adapter addresses
    pAddresses = (IP_ADAPTER_ADDRESSES *)malloc(outBufLen);
    if (pAddresses == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    // Get adapter addresses
    dwRetVal = GetAdaptersAddresses(AF_INET, GAA_FLAG_INCLUDE_PREFIX, NULL, pAddresses, &outBufLen);
    
    if (dwRetVal == ERROR_BUFFER_OVERFLOW) {
        free(pAddresses);
        pAddresses = (IP_ADAPTER_ADDRESSES *)malloc(outBufLen);
        if (pAddresses == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        dwRetVal = GetAdaptersAddresses(AF_INET, GAA_FLAG_INCLUDE_PREFIX, NULL, pAddresses, &outBufLen);
    }
    
    if (dwRetVal == NO_ERROR) {
        pCurrAddresses = pAddresses;
        
        // Iterate through all adapters
        while (pCurrAddresses) {
            // Skip loopback and non-operational adapters
            if (pCurrAddresses->OperStatus == IfOperStatusUp && 
                pCurrAddresses->IfType != IF_TYPE_SOFTWARE_LOOPBACK) {
                
                PIP_ADAPTER_UNICAST_ADDRESS pUnicast = pCurrAddresses->FirstUnicastAddress;
                
                while (pUnicast) {
                    if (pUnicast->Address.lpSockaddr->sa_family == AF_INET) {
                        struct sockaddr_in *sa_in = (struct sockaddr_in *)pUnicast->Address.lpSockaddr;
                        char ip[INET_ADDRSTRLEN];
                        inet_ntop(AF_INET, &(sa_in->sin_addr), ip, INET_ADDRSTRLEN);
                        
                        // Skip localhost
                        if (strcmp(ip, "127.0.0.1") != 0) {
                            printf("Adapter: %S\n", pCurrAddresses->FriendlyName);
                            printf("Local IP: %s\n", ip);
                            found = 1;
                        }
                    }
                    pUnicast = pUnicast->Next;
                }
            }
            pCurrAddresses = pCurrAddresses->Next;
        }
        
        if (!found) {
            printf("No active network adapter found.\n");
        }
    } else {
        printf("GetAdaptersAddresses failed with error: %d\n", dwRetVal);
    }
    
    if (pAddresses) {
        free(pAddresses);
    }
    
    #else
    // Unix/Linux implementation using socket method
    struct sockaddr_in serv;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (sock < 0) {
        printf("Socket creation failed.\n");
        return;
    }
    
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr("8.8.8.8");
    serv.sin_port = htons(53);
    
    if (connect(sock, (const struct sockaddr*)&serv, sizeof(serv)) < 0) {
        printf("Connection failed.\n");
        close(sock);
        return;
    }
    
    struct sockaddr_in name;
    socklen_t namelen = sizeof(name);
    if (getsockname(sock, (struct sockaddr*)&name, &namelen) < 0) {
        printf("Failed to get local IP.\n");
        close(sock);
        return;
    }
    
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &name.sin_addr, ip, INET_ADDRSTRLEN);
    printf("Local IP: %s\n", ip);
    
    close(sock);
    #endif
}

/*
 * Ping a website and show average latency
 * Uses system ping command and parses output
 */
void pingWebsite(const char* hostname) {
    char command[512];
    FILE *fp;
    char line[256];
    int count = 4; // Number of ping requests
    
    printf("Sending %d ping requests to %s...\n\n", count, hostname);
    
    #ifdef _WIN32
    // Windows ping command
    sprintf(command, "ping -n %d %s", count, hostname);
    #else
    // Linux/Unix ping command
    sprintf(command, "ping -c %d %s", count, hostname);
    #endif
    
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to execute ping command.\n");
        return;
    }
    
    // Read and display ping output
    int foundStats = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Display relevant lines
        if (strstr(line, "Reply") || strstr(line, "bytes from") || 
            strstr(line, "time=") || strstr(line, "Average") || 
            strstr(line, "Minimum") || strstr(line, "Maximum")) {
            printf("%s", line);
            foundStats = 1;
        }
    }
    
    if (!foundStats) {
        printf("Could not reach %s. Please check:\n", hostname);
        printf("- Your internet connection\n");
        printf("- The hostname is correct\n");
        printf("- Firewall settings\n");
    }
    
    pclose(fp);
}

/*
 * Test Internet Speed
 * Downloads and uploads test files to measure speed
 */
void testInternetSpeed() {
    char command[512];
    FILE *fp;
    
    printf("Note: This is a basic speed estimation.\n");
    printf("For accurate results, use dedicated speed test tools.\n\n");
    
    // Test download speed
    printf("Testing download speed...\n");
    
    // Use a small test file (1MB) from a reliable source
    const char* testURL = "http://speedtest.ftp.otenet.gr/files/test1Mb.db";
    
    #ifdef _WIN32
    // Windows: Use curl with timing
    sprintf(command, "curl -o nul -s -w \"Downloaded in %%{time_total} seconds\\nAverage speed: %%{speed_download} bytes/sec\\n\" %s 2>nul", testURL);
    #else
    // Linux: Use curl with timing
    sprintf(command, "curl -o /dev/null -s -w \"Downloaded in %%{time_total} seconds\\nAverage speed: %%{speed_download} bytes/sec\\n\" %s 2>/dev/null", testURL);
    #endif
    
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: curl not found.\n");
        printf("Please install curl to use this feature.\n");
        printf("\nAlternatively, you can manually test speed at: https://fast.com\n");
        return;
    }
    
    char line[256];
    double downloadSpeed = 0;
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        
        // Parse speed in bytes/sec
        if (strstr(line, "speed:")) {
            sscanf(line, "Average speed: %lf", &downloadSpeed);
        }
    }
    pclose(fp);
    
    // Convert to Mbps if speed was captured
    if (downloadSpeed > 0) {
        double mbps = (downloadSpeed * 8) / (1024 * 1024);
        printf("Download Speed: %.2f Mbps\n", mbps);
    }
    
    printf("\n");
    
    // Upload test (simplified - uses POST request)
    printf("Testing upload speed...\n");
    printf("(Upload test requires a test server endpoint)\n");
    printf("Skipping upload test in this basic implementation.\n");
    printf("\nFor comprehensive speed tests, visit: https://fast.com or https://speedtest.net\n");
}

/*
 * Clear input buffer to prevent issues with scanf
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
