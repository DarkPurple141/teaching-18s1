<template lang="html">
   <section class="labs">
      <section-header :name="week"/>
      <article v-for="file in files">
         <h3>{{file.path}}</h3>
         <pre><code class="language-c">{{ file.content }}</code></pre>
      </article>
   </section>
</template>

<script>
import { getJSON, getFile } from '@/helpers'
import SectionHeader from '@/components/SectionHeader'
import Prism from 'prismjs'

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

   components: { SectionHeader },

   data() {
      return {
         files: [],
         update: false
      }
   },

   beforeMount() {
      getJSON(`${this.course}/${this.cls}/${this.week}/index.json`)
         .then((labJSON) => {
            labJSON.files.forEach(file => this.files.push({ path: file, content: "" }))
         })
         .then(() => {
            this.files.forEach(file => {
               getFile(`${this.course}/${this.cls}/${this.week}/${file.path}`)
                  .then((content) => {
                     file.content = content
                  })
            })
         })
   },

   mounted() {
      setTimeout(() => {
         Prism.highlightAll()
      }, 500)
   }
}
</script>

<style lang="less" scoped>

pre {
   background-color: #1d1f21;
   text-align: left;
   transition: color 0.3s;
}

</style>
