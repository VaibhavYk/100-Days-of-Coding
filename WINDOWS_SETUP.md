# Windows Setup Guide for Network Utility

This guide will help you compile and run the Network Utility program on Windows.

## Prerequisites

You need a C compiler for Windows. Choose one of these options:

### Option 1: MinGW-w64 (Recommended for Beginners)

1. **Download MinGW-w64:**
   - Visit: https://www.mingw-w64.org/downloads/
   - Or use MSYS2: https://www.msys2.org/
   
2. **Install MSYS2 (Easiest Method):**
   - Download from: https://www.msys2.org/
   - Run the installer (msys2-x86_64-*.exe)
   - Follow installation wizard
   
3. **Install GCC via MSYS2:**
   ```bash
   # Open MSYS2 terminal and run:
   pacman -Syu
   pacman -S mingw-w64-x86_64-gcc
   pacman -S make
   ```

4. **Add to PATH:**
   - Add `C:\msys64\mingw64\bin` to your Windows PATH
   - Search "Environment Variables" in Windows
   - Edit "Path" variable
   - Add new entry: `C:\msys64\mingw64\bin`

### Option 2: Visual Studio

1. **Download Visual Studio:**
   - Visit: https://visualstudio.microsoft.com/downloads/
   - Download "Visual Studio Community" (Free)
   
2. **Install with C++ Support:**
   - Run installer
   - Select "Desktop development with C++"
   - Install

### Option 3: TDM-GCC (Lightweight)

1. **Download TDM-GCC:**
   - Visit: https://jmeubank.github.io/tdm-gcc/
   - Download and install
   - Automatically adds to PATH

## Compilation

### Method 1: Using Command Prompt (MinGW)

```cmd
cd path\to\network_utility
gcc network_utility.c -o network_utility.exe -lws2_32 -liphlpapi
```

### Method 2: Using Visual Studio Developer Command Prompt

```cmd
cd path\to\network_utility
cl network_utility.c ws2_32.lib iphlpapi.lib
```

### Method 3: Using Makefile (if Make is installed)

```cmd
cd path\to\network_utility
make windows
```

## Running the Program

### From Command Prompt:
```cmd
network_utility.exe
```

### From PowerShell:
```powershell
.\network_utility.exe
```

### Double-click:
Simply double-click `network_utility.exe` in File Explorer

## Installing curl (if needed)

### Windows 10/11:
curl is pre-installed! Verify with:
```cmd
curl --version
```

### Windows 7/8:
1. Download from: https://curl.se/windows/
2. Extract to `C:\curl`
3. Add `C:\curl\bin` to PATH

## Troubleshooting

### Error: "gcc is not recognized"
**Solution:** GCC is not in your PATH
- Reinstall MinGW and ensure "Add to PATH" is checked
- Or manually add to PATH (see installation steps above)

### Error: "cannot find -lws2_32"
**Solution:** Missing Windows SDK libraries
- Ensure you're using MinGW-w64 (not MinGW32)
- Or use Visual Studio compiler instead

### Error: "Failed to initialize Winsock"
**Solution:** 
- Run as Administrator
- Check Windows Firewall settings
- Ensure network services are running

### Error: "curl not found"
**Solution:**
- Install curl (see above)
- Or download wget: https://eternallybored.org/misc/wget/

### Program shows no local IP
**Solution:**
- Check network adapter is enabled
- Run as Administrator
- Ensure you're connected to a network

### Ping fails
**Solution:**
- Check firewall allows ICMP
- Windows Firewall → Advanced Settings → Inbound Rules
- Enable "File and Printer Sharing (Echo Request - ICMPv4-In)"

## Quick Start (Complete Steps)

1. **Install MinGW via MSYS2:**
   ```bash
   # Download and install MSYS2 from https://www.msys2.org/
   # Open MSYS2 terminal:
   pacman -Syu
   pacman -S mingw-w64-x86_64-gcc
   ```

2. **Add to PATH:**
   - Add `C:\msys64\mingw64\bin` to Windows PATH

3. **Compile:**
   ```cmd
   cd path\to\network_utility
   gcc network_utility.c -o network_utility.exe -lws2_32 -liphlpapi
   ```

4. **Run:**
   ```cmd
   network_utility.exe
   ```

## Testing the Program

Once running, try these options:

1. **Test Public IP (Option 1):**
   - Should display your public IP address
   - Requires internet connection

2. **Test Local IP (Option 2):**
   - Shows your local network IP
   - Works offline

3. **Test Ping (Option 3):**
   - Enter: `google.com`
   - Should show ping times

4. **Test Speed (Option 4):**
   - Downloads test file
   - Shows download speed

5. **Run All Tests (Option 5):**
   - Runs all diagnostics at once

## Example Session

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
Enter your choice: 1

--- Public IP Address ---
Your Public IP: 203.0.113.45

========================================
1. Show Public IP Address
2. Show Local IP Address
3. Ping a Website
4. Test Internet Speed
5. Run All Tests
0. Exit
========================================
Enter your choice: 2

--- Local IP Address ---
Adapter: Wi-Fi
Local IP: 192.168.1.100

========================================
1. Show Public IP Address
2. Show Local IP Address
3. Ping a Website
4. Test Internet Speed
5. Run All Tests
0. Exit
========================================
Enter your choice: 3

Enter website to ping (e.g., google.com): google.com

--- Pinging google.com ---
Sending 4 ping requests to google.com...

Reply from 142.250.185.46: bytes=32 time=15ms TTL=117
Reply from 142.250.185.46: bytes=32 time=14ms TTL=117
Reply from 142.250.185.46: bytes=32 time=16ms TTL=117
Reply from 142.250.185.46: bytes=32 time=15ms TTL=117

Ping statistics for 142.250.185.46:
    Packets: Sent = 4, Received = 4, Lost = 0 (0% loss),
Approximate round trip times in milli-seconds:
    Minimum = 14ms, Maximum = 16ms, Average = 15ms
```

## Additional Resources

- **MinGW-w64:** https://www.mingw-w64.org/
- **MSYS2:** https://www.msys2.org/
- **Visual Studio:** https://visualstudio.microsoft.com/
- **curl for Windows:** https://curl.se/windows/
- **C Programming Tutorial:** https://www.learn-c.org/

## Support

If you encounter issues:
1. Check the troubleshooting section above
2. Ensure all prerequisites are installed
3. Verify PATH environment variable is set correctly
4. Try running as Administrator
5. Check Windows Firewall settings

## Notes

- The program requires Windows 7 or later
- Administrator privileges may be needed for some features
- Antivirus software might flag the program (false positive)
- Add exception in antivirus if needed
