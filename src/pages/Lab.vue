<template lang="html">
   <section class="labs">
      <p v-for="file in files">{{ file }}</p>
   </section>
</template>

<script>
import { getJSON } from '@/helpers'

export default {
   props: {
      cls: {
         type: String,
         required: true
      },
      course: {
         type: String,
         required: true
      },
      week: {
         type: String,
         required: true
      }
   },

   data() {
      return {
         files: []
      }
   },

   beforeMount() {
      getJSON(`static/${this.course}/${this.cls}/${this.week}/index.json`)
         .then((labJSON) => {
            labJSON.files.forEach(file => this.files.push(file))
            lab.meta = labJSON.meta
         })
   }
}
</script>

<style lang="less">
</style>
