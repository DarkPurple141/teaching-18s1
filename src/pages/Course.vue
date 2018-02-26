<template lang="html">
   <section class="content">
      <section-header :name="course"/>
      <div v-for="cl in classes">
         <router-link :to="{ name: 'Class', params: { class: cl.path } }">
            {{ cl.name }}
         </router-link>
      </div>
      <article class="content-body">
         <p>{{ copy }}</p>
      </article>
   </section>
</template>

<script>
import SectionHeader from '@/components/SectionHeader'
import { getJSON, toCaps } from '@/helpers'

export default {
   components: { SectionHeader },
   props: {
      course: {
         type: String,
         required: true
      }
   },

   data() {
      return {
         classes: [],
         copy: "I'll be putting anything worth announcing here. For class relevant labs and tute material click the above link."
      }
   },

   beforeMount() {
      getJSON(`${this.course}/index.json`)
         .then(json => json.classes.forEach(
            item => this.classes.push({ path: item, name: toCaps(item)})
         ))
   }
}
</script>

<style lang="less" scoped>
@import '../assets/colors.less';
@import '../assets/article.less';


</style>
