# DISK IO

## Requirements

```
$ apt install inotify-tools
```

## Usage

- if you are gonna monitor file accessing under /tmp folder

```
$ inotifywait -r -m /tmp
Setting up watches.  Beware: since -r was given, this may take a while!
Watches established.
/tmp/ DELETE fmd.sock
/tmp/ CREATE fmd.sock
```


