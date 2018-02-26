<template>
  <div id="app">
    <site-header/>
    <main>
      <router-view :key="$route.path"></router-view>
    </main>
    <site-footer/>
  </div>
</template>

<script>
import SiteHeader from '@/components/SiteHeader'
import SiteFooter from '@/components/SiteFooter'

export default {
  components: { SiteHeader, SiteFooter },
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

h3 {
   margin: 20px;
   text-align: left;
   color: @secondary-text;
}

main {
  max-width: 800px;
  width: 90%;
  margin-left: auto;
  margin-right: auto;
  text-align: center;
  margin-top: 40px;
  margin-bottom: 170px;
}

</style>
