<template>
  <section class="section-light window" id="window-developletter">
    <div class="window-head">
      <span>
        Implementation of Article 9 "On the establishment of manned and unmanned
        stations"
      </span>
    </div>
    <div class="window-content">
      <p>
        <b>
          States Parties may establish manned and unmanned stations on the moon.
          A State Party establishing a station shall use only that area which is
          required for the needs of the station and shall immediately inform the
          Secretary-General of the United Nations of the location and purposes
          of that station. Subsequently, at annual intervals that State shall
          likewise inform the Secretary-General whether the station continues in
          use and whether its purposes have changed.
        </b>
      </p>
      <table class="table-hover table-responsive">
        <thead>
          <tr>
            <th>Last expedition</th>
            <th>Perimetr</th>
            <th>Mars Basecamp name</th>
            <th>Actions</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="(item, i) in list" :key="i">
            <td>{{ item.time }}</td>
            <td>{{ item.perimeter }}</td>
            <td>{{ item.camp }}</td>
            <td>{{ item.action }}</td>
          </tr>
        </tbody>
      </table>
    </div>
  </section>
</template>

<script>
import { bitesToHash, hexToHash, onEvents } from "../utils/chain";
import { ipfsCat } from "../utils/tools";
import config from "../config";

export default {
  data() {
    return {
      list: [
        // {
        // time: "2 days ago",
        // odonometry: "4 km",
        // basecamp: "Airalab village",
        // action: "Rent apartments (soon)",
        // },
      ],
    };
  },
  async mounted() {
    let datalog = (
      await this.$chain.query.datalog.datalog(config.AGENTS.LAND)
    ).toArray();

    for (const item of datalog.slice(-1)) {
      const hash = bitesToHash(item[1]);
      const res = await ipfsCat(hash);
      this.list.push({
        time: new Date(Number(item[0])).toLocaleString(),
        // tx: "0xab91...17a6",
        ipfs: hash,
        action: res.action,
        camp: res.camp,
        perimeter: res.perimeter,
      });
    }

    onEvents(async (result) => {
      if (result.data.AccountId === config.AGENTS.LAND) {
        const hash = hexToHash(result.data.Record);
        const res = await ipfsCat(hash);
        this.list.push({
          time: new Date(Number(result.data.Moment)).toLocaleString(),
          // tx: "0xab91...17a6",
          ipfs: hash,
          action: res.action,
          camp: res.camp,
          perimeter: res.perimeter,
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
