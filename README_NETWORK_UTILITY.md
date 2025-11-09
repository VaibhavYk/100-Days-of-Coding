# Network Utility Program

A comprehensive C program for Windows that provides network diagnostic tools including IP address detection, ping functionality, and internet speed testing.

## Features

1. **Public IP Address Detection**
   - Retrieves your public-facing IP address using external API
   - Uses curl or wget to fetch IP from ipify.org

2. **Local IP Address Detection**
   - Shows your local network IP address(es)
   - Uses Windows IP Helper API for accurate results
   - Displays all active network adapters

3. **Ping Functionality**
   - Sends ICMP ping requests to any website
   - Shows response times and statistics
   - Calculates average latency

4. **Internet Speed Test**
   - Basic download speed estimation
   - Downloads test file and measures transfer rate
   - Displays speed in Mbps

## Requirements

### Windows
- Windows 7 or later
- MinGW-w64 or Visual Studio (for compilation)
- curl.exe (usually included in Windows 10+)

### Linux (for testing in sandbox)
- GCC compiler
- curl or wget

## Compilation Instructions

### On Windows with MinGW:
```bash
gcc network_utility.c -o network_utility.exe -lws2_32 -liphlpapi
```

### On Windows with Visual Studio:
```bash
cl network_utility.c ws2_32.lib iphlpapi.lib
```

### On Linux (for testing):
```bash
gcc network_utility.c -o network_utility
```

## Usage

1. Compile the program using the instructions above
2. Run the executable:
   ```bash
   # Windows
   network_utility.exe
   
   # Linux
   ./network_utility
   ```

3. Choose from the menu options:
   - **Option 1**: Display your public IP address
   - **Option 2**: Display your local IP address(es)
   - **Option 3**: Ping a specific website
   - **Option 4**: Test internet speed
   - **Option 5**: Run all tests at once
   - **Option 0**: Exit the program

## Code Structure Explanation

### Main Components:

1. **Header Files**
   - `winsock2.h`, `ws2tcpip.h`: Windows socket programming
   - `iphlpapi.h`: Windows IP Helper API for network adapter info
   - `windows.h`: General Windows API functions

2. **Key Functions**

   - `main()`: Entry point, handles menu and user input
   - `getPublicIP()`: Fetches public IP using curl/wget
   - `getLocalIP()`: Gets local IP using Windows API
   - `pingWebsite()`: Executes ping command and displays results
   - `testInternetSpeed()`: Downloads test file to measure speed

3. **How Each Feature Works**

   **Public IP Detection:**
   ```c
   // Uses popen() to execute curl command
   // Fetches IP from https://api.ipify.org
   // Parses and displays the result
   ```

   **Local IP Detection:**
   ```c
   // Calls GetAdaptersAddresses() Windows API
   // Iterates through all network adapters
   // Filters active adapters and extracts IPv4 addresses
   // Skips loopback (127.0.0.1) addresses
   ```

   **Ping Functionality:**
   ```c
   // Executes system ping command
   // Windows: ping -n 4 hostname
   // Parses output to show response times
   // Displays statistics (min/max/average)
   ```

   **Speed Test:**
   ```c
   // Downloads 1MB test file using curl
   // Measures time taken for download
   // Calculates speed in bytes/sec
   // Converts to Mbps for display
   ```

## Example Output

```
========================================
   Network Utility Program
========================================

========================================
1. Show Public IP Address
2. Show Local IP Address
3. Ping a Website
4. Test Internet Speed
5. Run All Tests
0. Exit
========================================
Enter your choice: 5

--- Complete Network Diagnostics ---

1. Public IP Address:
Your Public IP: 203.0.113.45

2. Local IP Address:
Adapter: Ethernet
Local IP: 192.168.1.100

3. Ping Test (google.com):
Sending 4 ping requests to google.com...

Reply from 142.250.185.46: bytes=32 time=15ms TTL=117
Reply from 142.250.185.46: bytes=32 time=14ms TTL=117
Reply from 142.250.185.46: bytes=32 time=16ms TTL=117
Reply from 142.250.185.46: bytes=32 time=15ms TTL=117

Average = 15ms

4. Speed Test:
Testing download speed...
Downloaded in 0.523 seconds
Average speed: 1912045 bytes/sec
Download Speed: 14.56 Mbps
```

## Troubleshooting

### "curl not found" error:
- **Windows 10+**: curl is usually pre-installed. Check by running `curl --version` in Command Prompt
- **Older Windows**: Download curl from https://curl.se/windows/
- **Alternative**: Install wget from https://eternallybored.org/misc/wget/

### "Failed to initialize Winsock" error:
- Ensure you're compiling with `-lws2_32` flag
- Check that Winsock2 is available on your system

### No local IP displayed:
- Check that you have an active network connection
- Ensure network adapter is enabled in Network Settings
- Try running as Administrator

### Ping fails:
- Check firewall settings (ICMP might be blocked)
- Verify internet connection
- Try pinging a different website

## Dependencies

- **Winsock2** (ws2_32.lib): Windows socket library
- **IP Helper API** (iphlpapi.lib): Windows network adapter information
- **curl or wget**: For fetching public IP and speed tests

## Notes

- The speed test is a basic estimation. For accurate results, use dedicated tools like:
  - https://fast.com (Netflix speed test)
  - https://speedtest.net (Ookla speed test)
  
- The program requires internet connection for public IP and speed test features

- Local IP detection works offline

- Ping functionality requires ICMP to be allowed through firewall

## Platform Compatibility

- **Primary Target**: Windows (7, 8, 10, 11)
- **Secondary**: Linux (with minor modifications, already included)
- **Code uses preprocessor directives** (`#ifdef _WIN32`) for cross-platform compatibility

## Security Considerations

- Uses HTTPS for public IP API (secure connection)
- No sensitive data is stored or transmitted
- All network operations use standard system APIs
- External API (ipify.org) is a trusted service

## License

Free to use and modify for educational and personal purposes.

## Author Notes

This program demonstrates:
- Windows socket programming (Winsock2)
- Windows API usage (IP Helper API)
- System command execution (popen)
- Network diagnostics implementation
- Cross-platform C programming techniques
- Error handling and user input validation

Perfect for learning network programming in C!
