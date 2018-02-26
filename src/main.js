// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'

import Icon from 'vue-awesome/components/Icon'
import './icons'

import 'prism-themes/themes/prism-atom-dark.css'
//import 'prism-themes/themes/prism-duotone-light.css'
import 'prismjs/components/prism-c.min.js'
import 'prismjs/components/prism-yaml.min.js'
import 'prismjs/components/prism-bash.min.js'

Vue.component('icon', Icon)

Vue.config.productionTip = false

/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  template: '<App/>',
  components: { App }
})
