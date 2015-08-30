# fast-cp

## Description

fast-cp is made to send large ammounts of data accross machines.

## Usage

### Command Line

#### Server
```
fast-cp --from ~/Documents/my_giant_photo.png --to ip_or_address.com:/photos/my_giant_photo.png
fast-cp --from ~Documents/my_photos/ --to ip_or_address:/photos/
```

#### Client

```
fast-cp --wait-files
```

## How it works

### Web Socket

fast-cp uses tcp sockets do connect the machines.
