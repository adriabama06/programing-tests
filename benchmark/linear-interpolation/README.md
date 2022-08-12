# Work:
Get 450000000 numbers (in float in 32 bits) between 0 and 1000

# Results on i7 11700kf:
Windows 10 Home x64 3.60GHz 16 threads

| Lang          | Single Thread | Multi Thread |
| ------------- | -------------:| -----------: |
| C             | 1.29s         | 0.73s        |
| Go            | 2.68s         | 2.24s        |
| JavaScript    | -             | -            |
| Python        | 218.21s       | 229.60s      |
| Rust          | 11.30s        | idk how code |

idk why rust cut code at line 202050 when is writing the file (0.44900224 number between 0 and 1000)
wtf python uses 13GB of RAM (i have 16GB) for do all the work
javascript death because is too many work

# Results on Raspberry Pi 4:
Raspbian Debian GNU/Linux 11 (bullseye) aarch64 (64bit for arm) 2GHz (overclock) 4 threads

| Lang          | Single Thread | Multi Thread |
| ------------- | -------------:| -----------: |
| C             | 7.20s         | 5.24s        |
| Go            | 16.08s        | 14.81s       |
| JavaScript    | -             | -            |
| Python        | 1137.36s      | -            |
| Rust          | 66.74s        | idk how code |

ok in this case python use close to 3500MB of RAM (i have 4GB) for do all the work, and never ends because is killed by the system (the time show is the time at the process end)
javascript death because is too many work
