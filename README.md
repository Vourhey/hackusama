# Kusama On Mars 

During the hackathon, our team has studied the UN Agreement Governing the Activities of States on the Moon and Other Celestial Bodies from 1979. On the basis of the studied material, it was proposed to consider the interplanetary architecture of the Kusama network and create software modules that implement article 6 "On freedom of scientific investigation", article 7 "On preventing disruption of the existing balance of its environment" and article 9 "On the establishment of manned and unmanned stations."

## An architecture impossible without KUSAMA

The Kusama architecture allows a dedicated blockchain to live on Mars on its own and at the same time provides other blockchains on Earth to communicate with it.

Kusama will allow finalization of data from Mars on Earth and communication with Mars through transactions from other parachains using XCMP.

The blockchain for data storage was created in accordance with the UN Agreement Governing the Activities of States on the Moon and Other Celestial Bodies from 1979.

## How To Transfer Data Between Mars and Earth

Taking into account the result of robot's job must be submitted to the blockchain and finalized between 2 planets, the robot has to save metadate.

To publish a string of data to IPFS with [Robonomics io](https://github.com/airalab/robonomics#6-robonomics-io):

```
echo "Hello World" | ./robonomics io write ipfs
```

Note! IPFS daemon must be running

To store the hash in the Robonomcis parachain:

```
echo "Hello World" | ./robonomics io write ipfs | ./robonomics io write datalog -s SURI --remote REMOTE
```

where `SURI` is a private key, `REMOTE` is a remote endpoint (or localhost if not provided). 

Public RPC node: wss://rpc.parachain.robonomics.network/ 

Robonomics Node: https://parachain.robonomics.network/

Kusama will handle data sharing to Mars and back

Dr. Helmet-Head used [robonomics io](https://github.com/airalab/robonomics#6-robonomics-io) to publish photos:

```
DrHelmetHead@robonomics-parachain:~$ echo "QmYTwNBvP5bWD7a6VoSnukKvUtB58HUmmU9GxHrdTU5koz" | ./robonomics io write datalog -s 0xf7d0...6642
```

Base Camp Mars-1 used the tool to publish sensor data:

```
Base-Camp-Mars-1@robonomics-parachain:~$ echo "QmYhSXxsz96ARkguJDiX8DceaPv1vgkyCoG48LM88PTEX2" | ./robonomics io write datalog -s  0xd11f...0a9f
```

Rover Mars-2 used `robonomics io` to store a mission:

```
Rover-Mars-2@robonomics-parachain:~$ echo "QmPGFiq2wNTf2Sskq6deEa6qmkWsWRjBt2uDDupVmgb4YU" | ./robonomics io write datalog -s  0x77b1...3e83
2f710bab2ed5c7455d349fc2e8b1e18cb9160bb20754c685705c8db9b32a379c
```

The Dapp shows results that were achieved during the Mars expedition.

https://mars.robonomics.network/#/


