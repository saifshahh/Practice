# **Linux Commands & Bash Scripting Cheat Sheet**

## **1. File and Directory Commands**
| Command | Description |
|---------|-------------|
| `pwd` | Show current directory |
| `ls` | List files and directories |
| `cd <directory>` | Change directory |
| `mkdir <directory_name>` | Create a new directory |
| `rmdir <directory_name>` | Remove a directory |
| `touch <filename>` | Create a file |
| `cat <filename>` | View file contents |
| `cp <source> <destination>` | Copy a file |
| `mv <source> <destination>` | Move or rename a file |
| `rm <filename>` | Delete a file |

---

## **2. Memory Usage Commands**
| Command | Description |
|---------|-------------|
| `free -m` | Check memory usage in MB |
| `free -g` | Check memory usage in GB |
| `cat /proc/meminfo` | Check detailed memory usage |
| `ps aux --sort=-%mem | head` | Show memory usage per process |
| `vmstat 1` | Monitor memory usage live |

---

## **3. CPU Usage Commands**
| Command | Description |
|---------|-------------|
| `top` | Check CPU usage |
| `htop` | Interactive CPU and process monitor |
| `mpstat` | CPU usage summary |
| `lscpu` | Check CPU details |
| `sar -u 1 5` | Monitor CPU usage over time |

---

## **4. Process Management Commands**
| Command | Description |
|---------|-------------|
| `ps aux` | List running processes |
| `pstree` | List all processes in tree format |
| `kill <PID>` | Kill a process by PID |
| `kill -9 <PID>` | Force kill a process |
| `pkill <process_name>` | Kill a process by name |
| `pgrep <process_name>` | Check a specific process by name |
| `top` | Monitor real-time processes |
| `ps fax` | Show process hierarchy |
| `cat /proc/<PID>/status` | Check process details by PID |
| `netstat -tulnp | grep <port>` | Find which process is using a port |

---

## **5. User and System Information Commands**
| Command | Description |
|---------|-------------|
| `su <username>` | Switch user |
| `sudo <command>` | Run command as root |
| `whoami` | Show current user |
| `who` | Show active users |
| `uptime` | Show system uptime |

---

## **6. Disk and Network Commands**
| Command | Description |
|---------|-------------|
| `df -h` | Show disk usage |
| `find /path -name <filename>` | Find a file |
| `grep 'text' <filename>` | Search text in a file |
| `ping <website>` | Check network connectivity |
| `ifconfig` or `ip a` | Show IP address |
| `wget <URL>` | Download files |

---

## **7. File Compression Commands**
| Command | Description |
|---------|-------------|
| `tar -xvf <file.tar>` | Extract tar files |
| `tar -czvf <file.tar.gz> <directory>` | Compress files to tar.gz |

---

## **8. Bash Scripting Basics**
### **Special Environment Variables**
| Variable | Description |
|---------|-------------|
| `$0` | The name of the script itself |
| `$1, $2, ...` | Positional parameters (arguments passed to the script) |
| `$#` | The number of arguments passed to the script |
| `$@` | All arguments passed to the script as separate words |
| `$*` | All arguments passed to the script as a single string |
| `$$` | The process ID (PID) of the current script |
| `$?` | The exit status of the last executed command |
| `$_` | The last argument of the previous command |
| `$!` | The PID of the last background command |

---

## **9. Bash Scripting Examples**
### **Printing Script Arguments**
```bash
#!/bin/bash
echo "Script name: $0"
echo "First argument: $1"
echo "Second argument: $2"
echo "Number of arguments: $#"
echo "All arguments: $@"
```

### **Looping Examples**
#### **For Loop**
```bash
for i in {1..5}; do
echo "Iteration $i"
done
```

#### **While Loop**
```bash
counter=1
while [[ $counter -le 5 ]]; do
echo "Count: $counter"
counter=$((counter+1))
done
```

#### **Until Loop**
```bash
counter=1
until [[ $counter -gt 5 ]]; do
echo "Counter: $counter"
counter=$((counter+1))
done
```

### **Conditional Statements**
#### **Basic If Statement**
```bash
if [[ 5 -gt 3 ]]; then
echo "5 is greater than 3"
fi
```

#### **If-Else Statement**
```bash
if [[ 2 -gt 3 ]]; then
echo "2 is greater than 3"
else
echo "2 is not greater than 3"
fi
```

#### **If-Elif-Else Statement**
```bash
if [[ 2 -gt 3 ]]; then
echo "2 is greater than 3"
elif [[ 2 -eq 2 ]]; then
echo "2 equals 2"
else
echo "Neither condition met"
fi
```

### **File Existence Check**
```bash
if [[ -f "filename.txt" ]]; then
echo "File exists."
else
echo "File does not exist."
fi
```

### **Reading User Input**
```bash
echo "Enter your name:"
read name
echo "Hello, $name!"
```

### **Case Statement**
```bash
read -p "Enter a number between 1 and 3: " num
case $num in
1) echo "You entered one." ;;
2) echo "You entered two." ;;
3) echo "You entered three." ;;
*) echo "Invalid input." ;;
esac
```

🚀 **This cheat sheet covers essential Linux commands and Bash scripting basics. Save this document for quick reference!** 🚀

