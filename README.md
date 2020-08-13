# Kusama On Mars 

During the hackathon, our team has studied the UN Agreement Governing the Activities of States on the Moon and Other Celestial Bodies from 1979. On the basis of the studied material, it was proposed to consider the interplanetary architecture of the Kusama network and create software modules that implement article 6 "On freedom of scientific investigation", article 7 "On preventing disruption of the existing balance of its environment" and article 9 "On the establishment of manned and unmanned stations."

## An architecture impossible without KUSAMA

The Kusama architecture allows a dedicated blockchain to live on Mars on its own and at the same time provides other blockchains on Earth to communicate with it.

Kusama will allow finalization of data from Mars on Earth and communication with Mars through transactions from other parachains using XCMP.

The blockchain for data storage was created in accordance with the UN Agreement Governing the Activities of States on the Moon and Other Celestial Bodies from 1979.

## How To Transfer Data Using Satellites

Taking as a basis the principles of allocating territories to private farms in the development of the western United States, we want to give the opportunity to acquire station space on Mars for the inhabitants of the Earth through inter-blockchain communication within the Kusama network.

Taking into account the result of robot's job must be submitted to the blockchain and finalized between 2 planets, the robot has to save metadate.

To publish a string of data to IPFS:

```
echo "{ 'action': 'Rent apartments (soon)', 'camp': 'Airalab village', 'perimeter': 70.83 }" | ./robonomics io write ipfs
```

Note! IPFS daemon must be running

To store the hash in the Robonomcis parachain:

```
echo "{ 'action': 'Rent apartments (soon)', 'camp': 'Airalab village', 'perimeter': 70.83 }" | ./robonomics io write ipfs | ./robonomics io write datalog -s SURI --remote REMOTE
```

where `SURI` is a private key, `REMOTE` is a remote endpoint (or localhost if not provided). 

Public RPC node: wss://rpc.parachain.robonomics.network/ 

Robonomics Node: https://parachain.robonomics.network/

Kusama will handle data sharing to Mars and back 

## Freedom of Scientific Investigation

Research missions must publish the results of their work in the public domain. 

The data is stored in clear text in the hash-oriented IPFS storage, and the hashes themselves are regularly stored on the Kusama network

The Dapp shows results that were achieved during the Mars expedition.

https://mars.robonomics.network/#/


