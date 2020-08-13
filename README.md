# Kusama On Mars 

During the hackathon, our team has studied the UN Agreement Governing the Activities of States on the Moon and Other Celestial Bodies from 1979. On the basis of the studied material, it was proposed to consider the interplanetary architecture of the Kusama network and create software modules that implement article 6 "On freedom of scientific investigation", article 7 "On preventing disruption of the existing balance of its environment" and article 9 "On the establishment of manned and unmanned stations."

## The Robonomics Parachain

The Kusama architecture allows a dedicated blockchain to live on Mars on its own and at the same time provides other blockchains on Earth to communicate with it.

Kusama will allow finalization of data from Mars on Earth and communication with Mars through transactions from other parachains using XCMP.

## Dapp

To fulfill the article on maintaining balance in the environment, the ecologist saves landscape images of the habitat of the Mars-1 base camp with a demonstration of crops for growing and their impact on the environment.

The Dapp shows results that were achieved during the Mars expedition.

https://mars.robonomics.network/#/

## Robonomics IO

Taking as a basis the principles of allocating territories to private farms in the development of the western United States, we want to give the opportunity to acquire station space on Mars for the inhabitants of the Earth through inter-blockchain communication within the Kusama network

To publish a string to IPFS:

```
echo "{ 'action': 'Rent apartments (soon)', 'camp': 'Airalab village', 'perimeter': 70.83 }" | ./robonomics io write ipfs
```

Note! IPFS daemon must be running

To store the hash in the Robonomcis parachain:

```
echo "{ 'action': 'Rent apartments (soon)', 'camp': 'Airalab village', 'perimeter': 70.83 }" | ./robonomics io write ipfs | ./robonomics io write datalog -s SURI --remote REMOTE
```

where `SURI` is a private key, `REMOTE` is a remote endpoint (or localhost if not provided)

Public RPC node: wss://rpc.parachain.robonomics.network/ 
Robonomics Node: https://parachain.robonomics.network/


