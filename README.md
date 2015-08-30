# fast-cp

## Description

fast-cp is made to send large ammounts of data accross machines.

## Usage

### Command Line

#### Server
```
fast-cp copy --from ~/Documents/my_giant_photo.png --to ip_or_address.com:/photos/my_giant_photo.png
fast-cp copy --from ~Documents/my_photos/ --to ip_or_address:/photos/
```

#### Client

```
fast-cp --wait-files
```
### Replicating through several machines

This command allows machines to receive the files and replicate them. When a machines receives the files, it chooses one from the list and send the files. This process is repeated until every machine of the list get the files.

#### Server
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
