import axios from "axios";

export function sliceAddress(text) {
  return text.slice(0, 6) + "..." + text.slice(-4);
}
export function ipfsCat(hash) {
  return axios.get(`https://ipfs.io/ipfs/${hash}`).then((r) => {
    return r.data;
  });
}
