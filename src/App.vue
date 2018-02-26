<template>
  <div id="app">
    <site-header/>
    <main>
      <router-view></router-view>
    </main>
  </div>
</template>

<script>
import SiteHeader from '@/components/SiteHeader'

export default {
  components: { SiteHeader },
  name: 'Teaching'
}
</script>

<style lang="less">
@import './assets/colors.less';

*, *:after, *:before {
   margin: 0;
   padding: 0;
}

#app {
  font-family: -apple-system,system-ui,BlinkMacSystemFont,"Segoe UI",Roboto,"Helvetica Neue",Arial,sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: @primary-text;
  font-size: 16px;
  font-weight: normal;
  line-height: 1;
}

main {
  text-align: center;
  margin-top: 40px;
}

</style>
