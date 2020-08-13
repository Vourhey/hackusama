# Kusama On Mars 

## The Robonomics Parachain

## Dapp

https://mars.robonomics.network/#/

## Robonomics IO

To publish a string to IPFS:

```
echo "Hello world" | ./robonomics io write ipfs
```

Note! IPFS daemon must be running

To store the hash in the Robonomcis parachain:

```
echo "Hello world" | ./robonomics io write ipfs | ./robonomics io write datalog -s SURI --remote REMOTE
```

where `SURI` is a private key, `REMOTE` is a remote endpoint (or localhost if not provided)


