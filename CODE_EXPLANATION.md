# Network Utility - Detailed Code Explanation

This document explains every part of the network utility program in detail, perfect for learning C programming and network concepts.

## Table of Contents
1. [Header Files and Libraries](#header-files-and-libraries)
2. [Function Prototypes](#function-prototypes)
3. [Main Function](#main-function)
4. [Menu Display](#menu-display)
5. [Public IP Detection](#public-ip-detection)
6. [Local IP Detection](#local-ip-detection)
7. [Ping Functionality](#ping-functionality)
8. [Speed Test](#speed-test)
9. [Helper Functions](#helper-functions)

---

## Header Files and Libraries

```c
#include <stdio.h>      // Standard input/output (printf, scanf, FILE)
#include <stdlib.h>     // Standard library (malloc, free, system)
#include <string.h>     // String manipulation (strcpy, strcmp, strstr)
```

### Windows-Specific Headers:
```c
#ifdef _WIN32
    #include <winsock2.h>   // Windows socket programming (WSA functions)
    #include <ws2tcpip.h>   // TCP/IP specific functions (inet_ntop)
    #include <iphlpapi.h>   // IP Helper API (GetAdaptersAddresses)
    #include <windows.h>    // General Windows API
    #pragma comment(lib, "ws2_32.lib")    // Link Winsock library
    #pragma comment(lib, "iphlpapi.lib")  // Link IP Helper library
#endif
```

**Why these headers?**
- `winsock2.h`: Provides socket functions for network communication on Windows
- `ws2tcpip.h`: Contains TCP/IP protocol definitions and conversion functions
- `iphlpapi.h`: Allows us to query network adapter information
- `windows.h`: General Windows API functions

**What is `#pragma comment`?**
- Tells the compiler to link specific libraries
- Alternative to specifying `-lws2_32 -liphlpapi` in compilation command

---

## Function Prototypes

```c
void displayMenu();
void getPublicIP();
void getLocalIP();
void pingWebsite(const char* hostname);
void testInternetSpeed();
void clearInputBuffer();
```

**Why declare prototypes?**
- Tells compiler about functions before they're defined
- Allows functions to be defined in any order
- Improves code organization

---

## Main Function

### 1. Winsock Initialization (Windows Only)

```c
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock.\n");
        return 1;
    }
#endif
```

**What is Winsock?**
- Windows Sockets API for network programming
- Must be initialized before using any socket functions

**What does `WSAStartup` do?**
- Initializes the Winsock library
- `MAKEWORD(2, 2)` requests Winsock version 2.2
- `wsaData` receives information about the Winsock implementation

**Why check return value?**
- Returns 0 on success, error code on failure
- If initialization fails, network functions won't work

### 2. Main Menu Loop

```c
while (1) {
    displayMenu();
    printf("Enter your choice: ");
    
    if (scanf("%d", &choice) != 1) {
        clearInputBuffer();
        printf("\nInvalid input! Please enter a number.\n\n");
        continue;
    }
    clearInputBuffer();
```

**Why `while (1)`?**
- Creates infinite loop
- Program runs until user chooses to exit (option 0)

**Why check `scanf` return value?**
- `scanf` returns number of successfully read items
- If user enters non-numeric input, `scanf` returns 0
- Prevents program from crashing on invalid input

**Why `clearInputBuffer()`?**
- Removes leftover characters from input buffer
- Prevents issues with next input operation

### 3. Switch Statement

```c
switch (choice) {
    case 1:
        getPublicIP();
        break;
    case 2:
        getLocalIP();
        break;
    // ... more cases
    case 0:
        #ifdef _WIN32
        WSACleanup();  // Clean up Winsock
        #endif
        return 0;
}
```

**Why use switch instead of if-else?**
- More readable for multiple conditions
- More efficient for many cases
- Easier to maintain

**Why `WSACleanup()`?**
- Releases resources used by Winsock
- Should be called before program exits
- Good practice to clean up resources

---

## Public IP Detection

```c
void getPublicIP() {
    char command[512];
    FILE *fp;
    char ip[100];
    
    #ifdef _WIN32
    sprintf(command, "curl -s https://api.ipify.org 2>nul");
    #else
    sprintf(command, "curl -s https://api.ipify.org 2>/dev/null");
    #endif
```

### How It Works:

1. **Build Command String:**
   ```c
   sprintf(command, "curl -s https://api.ipify.org 2>nul");
   ```
   - `curl`: Command-line tool for transferring data
   - `-s`: Silent mode (no progress bar)
   - `https://api.ipify.org`: Free API that returns your public IP
   - `2>nul`: Redirects error messages to null (Windows)
   - `2>/dev/null`: Redirects error messages to null (Linux)

2. **Execute Command:**
   ```c
   fp = popen(command, "r");
   ```
   - `popen()`: Opens a pipe to execute command
   - `"r"`: Read mode - we want to read command output
   - Returns FILE pointer to read from

3. **Read Output:**
   ```c
   if (fgets(ip, sizeof(ip), fp) != NULL) {
       ip[strcspn(ip, "\n")] = 0;  // Remove newline
       printf("Your Public IP: %s\n", ip);
   }
   ```
   - `fgets()`: Reads one line from the pipe
   - `strcspn(ip, "\n")`: Finds position of newline character
   - Sets newline to null terminator to remove it

4. **Close Pipe:**
   ```c
   pclose(fp);
   ```
   - Closes the pipe and frees resources

### Why Use External API?

- Public IP is assigned by your ISP
- Can't be determined locally
- Need to ask external server "what IP do you see?"

---

## Local IP Detection

This is the most complex function. Let's break it down:

### Windows Implementation:

```c
#ifdef _WIN32
    PIP_ADAPTER_ADDRESSES pAddresses = NULL;
    ULONG outBufLen = 15000;
    
    pAddresses = (IP_ADAPTER_ADDRESSES *)malloc(outBufLen);
```

**What is `PIP_ADAPTER_ADDRESSES`?**
- Pointer to structure containing network adapter information
- Defined in `iphlpapi.h`
- Contains adapter name, IP addresses, MAC address, etc.

**Why allocate 15000 bytes?**
- Initial buffer size for adapter information
- May need to be increased if many adapters exist

### Get Adapter Information:

```c
dwRetVal = GetAdaptersAddresses(AF_INET, GAA_FLAG_INCLUDE_PREFIX, 
                                NULL, pAddresses, &outBufLen);

if (dwRetVal == ERROR_BUFFER_OVERFLOW) {
    free(pAddresses);
    pAddresses = (IP_ADAPTER_ADDRESSES *)malloc(outBufLen);
    dwRetVal = GetAdaptersAddresses(AF_INET, GAA_FLAG_INCLUDE_PREFIX,
                                    NULL, pAddresses, &outBufLen);
}
```

**What does `GetAdaptersAddresses` do?**
- Retrieves information about all network adapters
- `AF_INET`: Get IPv4 addresses only
- `GAA_FLAG_INCLUDE_PREFIX`: Include subnet prefix information
- `outBufLen`: Size of buffer (updated if too small)

**Why check for `ERROR_BUFFER_OVERFLOW`?**
- Buffer might be too small
- Function updates `outBufLen` with required size
- Reallocate and try again

### Iterate Through Adapters:

```c
while (pCurrAddresses) {
    if (pCurrAddresses->OperStatus == IfOperStatusUp && 
        pCurrAddresses->IfType != IF_TYPE_SOFTWARE_LOOPBACK) {
```

**What is `OperStatus`?**
- Operational status of adapter
- `IfOperStatusUp`: Adapter is active and connected
- Filters out disabled adapters

**What is loopback?**
- Virtual adapter (127.0.0.1)
- Used for local communication
- We skip it because it's not a real network connection

### Extract IP Address:

```c
PIP_ADAPTER_UNICAST_ADDRESS pUnicast = pCurrAddresses->FirstUnicastAddress;

while (pUnicast) {
    if (pUnicast->Address.lpSockaddr->sa_family == AF_INET) {
        struct sockaddr_in *sa_in = (struct sockaddr_in *)pUnicast->Address.lpSockaddr;
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(sa_in->sin_addr), ip, INET_ADDRSTRLEN);
```

**What is unicast address?**
- Regular IP address assigned to adapter
- As opposed to multicast or broadcast addresses

**What does `inet_ntop` do?**
- Converts binary IP address to string
- "ntop" = Network TO Presentation
- `AF_INET`: IPv4 format
- `INET_ADDRSTRLEN`: Maximum length of IPv4 string (16 bytes)

---

## Ping Functionality

```c
void pingWebsite(const char* hostname) {
    char command[512];
    
    #ifdef _WIN32
    sprintf(command, "ping -n %d %s", count, hostname);
    #else
    sprintf(command, "ping -c %d %s", count, hostname);
    #endif
```

### Command Differences:

**Windows:**
- `ping -n 4 google.com`
- `-n`: Number of echo requests

**Linux:**
- `ping -c 4 google.com`
- `-c`: Count of packets

### Parse Output:

```c
while (fgets(line, sizeof(line), fp) != NULL) {
    if (strstr(line, "Reply") || strstr(line, "time=") || 
        strstr(line, "Average")) {
        printf("%s", line);
    }
}
```

**What does `strstr` do?**
- Searches for substring in string
- Returns pointer if found, NULL if not
- Used to filter relevant lines from ping output

**Why filter output?**
- Ping produces many lines
- We only want lines with actual results
- Makes output cleaner and more readable

---

## Speed Test

```c
void testInternetSpeed() {
    const char* testURL = "http://speedtest.ftp.otenet.gr/files/test1Mb.db";
    
    #ifdef _WIN32
    sprintf(command, "curl -o nul -s -w \"Downloaded in %%{time_total} seconds\\n\" %s", testURL);
    #endif
```

### curl Options Explained:

- `-o nul`: Output to null (don't save file)
- `-s`: Silent mode
- `-w`: Write out format string after transfer
- `%%{time_total}`: Total time taken (double % to escape in sprintf)
- `%%{speed_download}`: Average download speed in bytes/sec

### Calculate Speed:

```c
if (downloadSpeed > 0) {
    double mbps = (downloadSpeed * 8) / (1024 * 1024);
    printf("Download Speed: %.2f Mbps\n", mbps);
}
```

**Why multiply by 8?**
- `downloadSpeed` is in bytes per second
- Internet speed is measured in bits per second
- 1 byte = 8 bits

**Why divide by (1024 * 1024)?**
- Converts bytes to megabytes
- 1 MB = 1024 KB = 1024 * 1024 bytes
- Result is in Megabits per second (Mbps)

---

## Helper Functions

### Clear Input Buffer:

```c
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
```

**Why needed?**
- After `scanf`, newline character remains in buffer
- Next input operation would read this newline
- This function removes all characters until newline

**How it works:**
- `getchar()`: Reads one character
- Loop continues until newline (`\n`) or end of file (`EOF`)
- Effectively clears the buffer

---

## Key Concepts Summary

### 1. Preprocessor Directives
```c
#ifdef _WIN32
    // Windows code
#else
    // Linux code
#endif
```
- Allows code to work on multiple platforms
- Compiler includes only relevant code

### 2. Error Handling
```c
if (fp == NULL) {
    printf("Error occurred\n");
    return;
}
```
- Always check if operations succeeded
- Prevents crashes and provides user feedback

### 3. Memory Management
```c
pAddresses = (IP_ADAPTER_ADDRESSES *)malloc(outBufLen);
// ... use memory ...
free(pAddresses);
```
- Allocate memory with `malloc`
- Always free allocated memory
- Prevents memory leaks

### 4. String Manipulation
```c
sprintf(command, "ping %s", hostname);  // Build string
strstr(line, "Reply")                   // Search string
strcspn(ip, "\n")                       // Find character
```
- Essential for building commands and parsing output

### 5. File Operations
```c
fp = popen(command, "r");   // Open pipe
fgets(line, size, fp);      // Read line
pclose(fp);                 // Close pipe
```
- Used to execute commands and read output

---

## Learning Path

If you're new to C programming, study in this order:

1. **Basic C**: Variables, functions, loops, conditionals
2. **Pointers**: Understanding memory addresses
3. **Strings**: Character arrays and string functions
4. **File I/O**: Reading and writing files
5. **System Calls**: Executing system commands
6. **Network Programming**: Sockets and protocols
7. **Windows API**: Platform-specific functions

---

## Further Reading

- **Winsock Programming**: https://docs.microsoft.com/en-us/windows/win32/winsock/
- **IP Helper API**: https://docs.microsoft.com/en-us/windows/win32/api/iphlpapi/
- **C Network Programming**: Beej's Guide to Network Programming
- **curl Documentation**: https://curl.se/docs/

---

## Practice Exercises

1. **Modify the program to:**
   - Ping multiple websites in sequence
   - Save results to a file
   - Add IPv6 support
   - Create a GUI version

2. **Add new features:**
   - Traceroute functionality
   - DNS lookup
   - Port scanning
   - Network bandwidth monitoring

3. **Improve error handling:**
   - More descriptive error messages
   - Retry logic for failed operations
   - Logging system

---

This detailed explanation should help you understand every aspect of the program. Happy coding!
