# Kusama On Mars 

During the hackathon, our team has studied the UN Agreement Governing the Activities of States on the Moon and Other Celestial Bodies from 1979. On the basis of the studied material, it was proposed to consider the interplanetary architecture of the Kusama network and create software modules that implement article 6 "On freedom of scientific investigation", article 7 "On preventing disruption of the existing balance of its environment" and article 9 "On the establishment of manned and unmanned stations."

## The Robonomics Parachain

## Dapp

The Dapp shows results that were achived during the Mars expedition.

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

Public RPC node: wss://rpc.parachain.robonomics.network/ 
Robonomics Node: https://parachain.robonomics.network/


