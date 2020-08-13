<template>
  <fragment>
    <div class="sidebar flexcols">
      <div class="sidebar-col sidebar-col--sm">
        <div class="sidebar-col-in">
          <section>
            <a class="dapplogo-sign" href="/">
              <img
                class="theme-day"
                alt="dApp logo"
                src="assets/i/logo-dapp-sign.svg"
              />
              <img
                class="theme-night"
                alt="dApp logo"
                src="assets/i/logo-dapp-sign.svg"
              />
            </a>
          </section>
          <section class="sidebar-col--bottom">
            <a
              class="sidebar-i--lg js-sidebar-link"
              href="javascript:;"
              on-toggle="#sidebar-info"
            >
              ?
            </a>
          </section>
        </div>
      </div>
      <div
        class="sidebar-col sidebar-col-padding js-sidebar-content"
        id="sidebar-info"
      >
        <div class="sidebar-col-in">
          <section>
            <nav class="nav-vertical">
              <a href="https://github.com/airalab" target="_blank">
                <span class="i-github align-vertical"></span>
                <span class="align-vertical">Github</span>
              </a>
              <a href="https://www.reddit.com/r/robonomics/" target="_blank">
                <span class="i-reddit align-vertical"></span>
                <span class="align-vertical">Reddit</span>
              </a>
              <a href="https://robonomics.network/" target="_blank">
                <span class="i-cursor align-vertical"></span>
                <span class="align-vertical">robonomomics.network</span>
              </a>
              <a href="https://aira.life/" target="_blank">
                <span class="i-cursor align-vertical"></span>
                <span class="align-vertical">aira.life</span>
              </a>
            </nav>
          </section>
        </div>
      </div>
    </div>
    <div class="content">
      <div class="content-in">
        <router-view />
      </div>
    </div>
  </fragment>
</template>

<style>
.theme-light .vue-lb-container button {
  background-color: transparent;
}
.theme-light .vue-lb-container button:hover {
  background-color: transparent;
}
</style>
