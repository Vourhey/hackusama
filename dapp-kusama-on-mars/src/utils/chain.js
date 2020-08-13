import { ApiPromise, WsProvider } from "@polkadot/api";
import { u8aToString, hexToString } from "@polkadot/util";
import config from "../config";

let instance = null;

export function getInstance() {
  if (instance) {
    return new Promise(function (resolve) {
      resolve(instance);
    });
  }
  const provider = new WsProvider(config.CHAIN_API);
  return ApiPromise.create({
    provider,
    types: {
      Record: "Vec<u8>",
      Parameter: "bool",
      LiabilityIndex: "u64",
    },
  }).then((r) => {
    instance = r;
    return r;
  });
}

export function bitesToHash(r) {
  return u8aToString(r);
}
export function hexToHash(r) {
  return hexToString(r);
}

export async function onEvents(cb) {
  instance.rpc.chain.subscribeNewHeads(async (header) => {
    // console.log("block", header.hash.toString());
    if (typeof cb === "function") {
      const result = await eventsByBlock(header.hash.toString());
      if (result.section) {
        cb(result);
      }
    }
  });
}

export async function eventsByBlock(block) {
  const result = {
    block: block,
    section: "",
    method: "",
    data: {},
  };
  const events = await instance.query.system.events.at(block);
  events.forEach((record) => {
    const { event } = record;
    if (event.section.toString() === "datalog") {
      const types = event.typeDef;
      result.section = event.section.toString();
      result.method = event.method.toString();
      event.data.forEach((data, index) => {
        result.data[types[index].type] = data.toString();
      });
    }
  });
  return result;
}
