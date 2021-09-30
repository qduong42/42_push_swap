#!/bin/bash

RED='\e[91m'

ssh-keygen -q -t rsa -N '' <<< ""$'\n'"y" >/dev/null 2>&1
if [ $? != 0 ]; then
	printf "${RED}Something went wrong with creating your ssh key :(."
	exit
fi
tr -d '\n' < ~/.ssh/id_rsa.pub | pbcopy
echo "A new ssh key has been copied to your clipboard, please login to the intra and replace your old one :)"
