<template>
  <section class="section-light window" id="window-developletter">
    <div class="window-head">
      <span>
        Implementation of Article 6 on "On freedom of scientific investigation"
      </span>
    </div>
    <div class="window-content">
      <p>
        <b>
          There shall be freedom of scientific investigation on the moon by all
          States Parties without discrimination of any kind, on the basis of
          equality and in accordance with international law.
        </b>
      </p>
      <table class="table-hover table-responsive">
        <thead>
          <tr>
            <th>last signal</th>
            <!-- <th>Paracahin tx ID</th> -->
            <th>IPFS hash</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="(item, i) in list" :key="i">
            <td>{{ item.time }}</td>
            <!-- <td>{{ item.tx }}</td> -->
            <td>
              <a :href="`https://ipfs.io/ipfs/${item.ipfs}`" target="_blank">
                {{ item.ipfs | sliceAddress }}
              </a>
            </td>
          </tr>
        </tbody>
      </table>
    </div>
  </section>
</template>

<script>
import { bitesToHash, hexToHash, onEvents } from "../utils/chain";
import config from "../config";

export default {
  data() {
    return {
      list: [
        // {
        //   time: "5:20 min ago",
        //   tx: "0xab91...17a6",
        //   ipfs: "QmUr...kmdH8",
        // },
      ],
    };
  },
  async mounted() {
    let datalog = (
      await this.$chain.query.datalog.datalog(config.AGENTS.BASECAMP)
    ).toArray();
    datalog.slice(-10).forEach((item) => {
      this.list.push({
        time: new Date(Number(item[0])).toLocaleString(),
        // tx: "0xab91...17a6",
        ipfs: bitesToHash(item[1]),
      });
    });

    onEvents((result) => {
      if (result.data.AccountId === config.AGENTS.BASECAMP) {
        this.list.push({
          time: new Date(Number(result.data.Moment)).toLocaleString(),
          // tx: "0xab91...17a6",
          ipfs: hexToHash(result.data.Record),
        });
      }
    });
  },
};
</script>

<style scoped>
table {
  width: 100%;
}
table th {
  text-align: center;
}
</style>
