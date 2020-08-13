<template>
  <div>
    <h1>Kusama on Mars Parachain</h1>
    <p>
      During the hackathon, our team has studied the
      <a href="volume-1363-A-23002-English.pdf" target="_blank">
        UN Agreement Governing the Activities of States on the Moon and Other
        Celestial Bodies from 1979 </a
      >. On the basis of the studied material, it was proposed to consider the
      interplanetary architecture of the Kusama network and create software
      modules that implement article 6 "On freedom of scientific investigation",
      article 7 "On preventing disruption of the existing balance of its
      environment" and article 9 "On the establishment of manned and unmanned
      stations."
    </p>
    <h2>Basecamp Mars-1 telemetry</h2>
    <template v-if="ready">
      <Opendata />
      <Environmental />
      <LandSurveying />
    </template>
  </div>
</template>

<script>
import Vue from "vue";
import Opendata from "@/components/Opendata.vue";
import Environmental from "@/components/Environmental.vue";
import LandSurveying from "@/components/LandSurveying.vue";
import { getInstance } from "../utils/chain";

export default {
  name: "Home",
  components: {
    Opendata,
    Environmental,
    LandSurveying,
  },
  data() {
    return {
      ready: false,
    };
  },
  async mounted() {
    Vue.prototype.$chain = await getInstance();
    this.ready = true;
  },
};
</script>

<style>
h1,
h2,
h3,
h4,
h5,
h6 {
  text-align: center;
}
</style>
