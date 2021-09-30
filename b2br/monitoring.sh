#!/bin/bash
#nproc --all same as #nproc
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
fdisk=$(df -H /home/ --output=avail | grep "[0-9]")
udisk=$(df -m /home/ --output=used | grep "[0-9]")
pdisk=$(df /home/ --output=pcent | grep "[0-9]")
lvm=$(lsblk | grep "lvm" |wc -l)

wall "
        #Architecture: uname -a
        #CPU physical : $(nproc)
        #vCPU : $(grep "^processor" /proc/cpuinfo | wc -l)
        #Memory Usage:
        #Disk Usage





        "