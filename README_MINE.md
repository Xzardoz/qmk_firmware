# README

## Compile

```shell
qmk compile -kb lily58 -km gzee
```

```shell
qmk compile -kb crkbd -km default -e CONVERT_TO=helios
```

## Backup as json

```shell
qmk c2json -kb lily58 -km gzee -o foo.json --no-cpp
```
