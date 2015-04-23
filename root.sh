#########################################################################
# File Name: root.sh
# Author: TinyPi
# mail: haijun.pi@ck-telecom.com
# Created Time: 2015年04月22日 星期三 14时04分52秒
#########################################################################
#!/bin/bash

echo "adb wait-for-device"
adb wait-for-device
echo "setprop"
adb shell 'setprop ro.debuggable 1'
adb wait-for-device
echo "root"
adb root
