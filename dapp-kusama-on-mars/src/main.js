import Vue from "vue";
import App from "./App.vue";
import router from "./router";
import VueLazyLoad from "vue-lazyload";
import * as tools from "./utils/tools";
import Fragment from "vue-fragment";

Vue.use(Fragment.Plugin);
Vue.use(VueLazyLoad);
Vue.filter("sliceAddress", tools.sliceAddress);

Vue.config.productionTip = false;

new Vue({
  router,
  render: (h) => h(App),
}).$mount("#app");
