<template>
  <section class="section-light window" id="window-developletter">
    <div class="window-head">
      <span>
        Implementation of Article 7 "On preventing disruption of the existing
        balance of its environment"
      </span>
    </div>
    <div class="window-content">
      <p>
        <b>
          In exploring and using the moon, States Parties shall take measures to
          prevent the disruption of the existing balance of its environment
          whether by introducing adverse changes in that environment, by its
          harmful contamination through the introduction of extra-environmental
          matter or otherwise. States Parties shall also take measures to avoid
          harmfully affecting the environment of the earth through the
          introduction of extraterrestrial matter or otherwise.
        </b>
      </p>
      <div class="gallery">
        <div class="row">
          <div
            class="col-xs12-4 col-md-4"
            v-for="(image, i) in images"
            :key="i"
          >
            <img :src="image.thumb" @click="openGallery(i)" />
            <span>{{ image.hash | sliceAddress }}</span>
          </div>
        </div>
      </div>
      <LightBox
        :media="images"
        ref="lightbox"
        :show-caption="false"
        :show-light-box="false"
      ></LightBox>
    </div>
  </section>
</template>

<script>
import LightBox from "vue-image-lightbox";
import "vue-image-lightbox/dist/vue-image-lightbox.min.css";
import { bitesToHash, onEvents, hexToHash } from "../utils/chain";
import config from "../config";

export default {
  components: {
    LightBox,
  },
  data() {
    return {
      images: [
        // {
        //   thumb: "https://via.placeholder.com/150",
        //   src: "https://via.placeholder.com/300",
        // }
      ],
    };
  },
  async mounted() {
    let datalog = (
      await this.$chain.query.datalog.datalog(config.AGENTS.HABITAT)
    ).toArray();
    datalog.forEach((item) => {
      const hash = bitesToHash(item[1]);
      if (
        hash === "QmTu9PVtGZwUCTQiURUZijXVEPsiNX2kjWUEDqUEcJTVDY" ||
        hash === "QmeWhK3WCM7orCh9ryyjrQQmREo7DxZhSP93CztCkCvXRd" ||
        hash === "QmTC7JJajfYzgGiygeVPdGZZhRr3yZegGG65KQsCgMw5UQ"
      ) {
        return;
      }
      this.images.push({
        hash,
        thumb: `https://ipfs.io/ipfs/${hash}`,
        src: `https://ipfs.io/ipfs/${hash}`,
      });
    });

    onEvents((result) => {
      if (result.data.AccountId === config.AGENTS.HABITAT) {
        const hash = hexToHash(result.data.Record);
        this.images.push({
          hash,
          thumb: `https://ipfs.io/ipfs/${hash}`,
          src: `https://ipfs.io/ipfs/${hash}`,
        });
      }
    });
  },
  methods: {
    openGallery(index) {
      this.$refs.lightbox.showImage(index);
    },
  },
};
</script>

<style scoped>
.gallery img {
  width: 100%;
  cursor: pointer;
}
</style>
