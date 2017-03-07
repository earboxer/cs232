#!/bin/sh
#This script is intended to be run from cs-ssh.calvin.edu
#Written by: Mitch Stark
#2/26/17


#attempt to ssh into each machine discovered
sshfile="machines.txt"
while read -r line
do
    #attempt to connect, with a 3 second timeout (for windows machines/offline)
    output="$(ssh -n -o ConnectTimeout=3 mjs73@$line.cs.calvin.edu 'who | wc -l')"
    if [ "$output" != "" ]; then
        echo $line has [$output] users
        echo $line has [$output] users >> "summary.txt"
    else
        echo $line cannot connect. Either offline/windows/not permitted
        echo $line cannot connect. Either offline/windows/not permitted >> "summary.txt"
    fi
done <"$sshfile"

echo "find summary of found machines/users in summary.txt"

