<template lang="html">
   <section class="labs">
      <section-header name="labs"/>
      <h3>{{ this.meta.description }}</h3>
      <section class="lab-cards">
         <card v-for="(lab, index) in labs"
         :link="lab.path"
         :meta="lab.meta"
         :number="index"
         :key="lab.path"/>
      </section>
   </section>
</template>

<script>
import SectionHeader from '@/components/SectionHeader'
import Card from '@/components/Card'
import { getJSON } from '@/helpers'

export default {
   components: { SectionHeader, Card },
   props: {
      cls: {
         type: String,
         required: true
      },
      course: {
         type: String,
         required: true
      }
   },

   data() {
      return {
         labs: [],
         meta: {}
      }
   },

   beforeMount() {
      getJSON(`/static/${this.course}/${this.cls}/index.json`)
         .then(json => {
            json.weeks.forEach(week => this.labs.push({ path: week, meta: {} }))
            this.meta = json.meta
         })
         .then(() => {
            this.labs.forEach(lab => {
               getJSON(`/static/${this.course}/${this.cls}/${lab.path}/index.json`)
                  .then((labJSON) => {
                     lab.meta = labJSON.meta
                  })
            })
         })
   }
}
</script>

<style lang="less" scoped>
@import '../assets/colors.less';

.lab-cards {
   display: flex;
   flex-direction: row;
   flex-wrap: wrap;
}

h3 {
   margin: 10px 0px;
   text-align: left;
   color: @secondary-text;
}

</style>
