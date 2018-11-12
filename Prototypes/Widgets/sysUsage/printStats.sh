#!/bin/bash
#script to print system's current CPU usage, memory usage, and disk usage

#CPU usage
#values from 0.3 seconds earlier
old_stats=$(cat /proc/stat | head -1)
#sum of active CPU cycles (system, nice, and user)
let old_work=$(echo $old_stats | awk '{print $2+$3+$4}')
#sum of all CPU cycles
let old_total=$old_work+$(echo $old_stats | awk '{print $5+$6+$7+$8+$9+$10}')

sleep 0.3

#current values
new_stats=$(cat /proc/stat | head -1)
#sum of active CPU cycles (system, nice, and user)
let new_work=$(echo $new_stats | awk '{print $2+$3+$4}')
#sum of all CPU cycles
let new_total=$new_work+$(echo $new_stats | awk '{print $5+$6+$7+$8+$9+$10}')

#ratio of differences between working cycles and total cycles give %CPU usage over this interval
echo CPU Usage: $(bc <<< "scale=1; 100 * ($new_work - $old_work) / ($new_total - $old_total)")%

#Memory usage
#free system call gives used memory and total memory.
#divide used by total to get percent used
free -m | grep "Mem:" | awk '{printf "Memory Usage: %.1f%% (%dM of %dM)\n", $3/$2*100, $3, $2}'

#Disk usage
#df gives percentage, used, and available in columns 5,3,4 respectively
df -h | grep "/home" | awk '{printf "Disk Usage: %s (%s of %s)\n", $5, $3, $4}'


