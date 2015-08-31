# fast-cp

## Description

fast-cp is made to send large ammounts of data accross machines.

## Usage

### Command Line

#### Sender 

```
fast-cp copy --from ~/Documents/my_giant_photo.png --to 10.0.10.1:9090
fast-cp copy --from ~/Documents/my_photos/ --to 10.0.10.1:9090
```

#### Receiver 

```
fast-cp wait --port 9090 --save-at ~/Documents/photos/my_giant_photo.png
fast-cp wait --port 9090 --save-at ~/Documents/photos/
```

### Replicating through several machines

This command allows machines to receive the files and replicate them. When a machines receives the files, it chooses one from the list and send the files. This process is repeated until every machine of the list get the files.

#### Master 

```
fast-cp replicate --from ~/Documents/some_imporant_origin/ --to list_of_ips.txt
```

#### Clients

```
fast-cp replicate --to ~/Documents/some_imporant_destination/
```

## How it works

### Web Socket

fast-cp uses tcp sockets do connect the machines.
