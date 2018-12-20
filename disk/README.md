# DISK IO

## Requirements

```
$ apt install inotify-tools
```

## Usage

- if you are gonna monitor file accessing under /tmp folder

```
$ inotifywait -r -m /tmp
```
